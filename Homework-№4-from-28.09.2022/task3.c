#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define maxSizeOfEntry 101

typedef struct entry {
    char phoneNumber[maxSizeOfEntry];
    char name[maxSizeOfEntry];
} dataBase;

void instructionPrint() {
    printf("This program has these commands:\n");
    printf("0 - exit\n");
    printf("1 - add an entry (name and phone number)\n");
    printf("2 - print all available records\n");
    printf("3 - find phone by name\n");
    printf("4 - find name by phone\n");
    printf("5 - save the current data to a file\n");
}

int readCommand() {
    printf("Please, enter the command:");
    int command = 0;
    scanf("%d", &command);
    while (!((command < 6) && (command > -1))) {
        printf("Wrong format! Please, try enter\n");
        printf("the program number again:");
        scanf("%d", &command);
    }
    return command;
}

int readDataFromFile(dataBase **entries, char *nameOfFile, int *cntOfEntries) {
    FILE *file = fopen(nameOfFile, "r");
    if (file == NULL) {
        return -2;
    }
    char checkString[] = "phoneNumbers names";
    char compareFirstString[19] = {0};
    for (int i = 0; i < 18; ++i) {
        compareFirstString[i] = fgetc(file);
    }

    if (strcmp(compareFirstString, checkString)) {
        printf("Incorrect file!\n");
        return -3;
    }
    fclose(file);
    file = fopen(nameOfFile, "r");
    for (int i = 0; i < 2; ++i) {
        fscanf(file, "%s", checkString);
    }
    while (!feof(file)) {
        fscanf(file, "%s", entries[*cntOfEntries]->phoneNumber);
        fscanf(file, "%s", entries[*cntOfEntries]->name);
        ++*cntOfEntries;
    }
    fclose(file);
    return 0;
}

void command1(dataBase **entries, int *cntOfEntries) {
    if (*cntOfEntries > maxSizeOfEntry) {
        printf("File is full! Please, clear some information in it!\n");
        return;
    }
    printf("Please, enter the phone number,\n");
    printf("which is less than 100 symbols or equal to it:");
    scanf("%s", entries[*cntOfEntries]->phoneNumber);
    printf("Please, enter the name of the people,\n");
    printf("which phone number you have already enter\n");
    printf("ans which is less than 100 symbols or equal to it:");
    scanf("%s", entries[*cntOfEntries]->name);
    ++*cntOfEntries;
}

void command2(dataBase **entries, int *cntOfEntries) {
    for (int i = 0; i < *cntOfEntries; ++i) {
        printf("Phone number: %s, Name: %s\n", entries[i]->phoneNumber, entries[i]->name);
    }

}

void command3(dataBase **entries, int *cntOfEntries) {
    bool isFound = false;
    char searchName[maxSizeOfEntry] = {0};
    printf("Please, enter the name by which\n");
    printf("you want to find the phone:");
    scanf("%s", searchName);
    for (int i = 0; i < *cntOfEntries; ++i) {
        if (strcmp(searchName, entries[i]->name) == 0) {
            printf("The following phone number was found: %s\n", entries[i]->phoneNumber);
            isFound = true;
        }
    }
    if (!isFound) {
        printf("I didn't find any number by this name.\n");
    }
}

void command4(dataBase **entries, int *cntOfEntries) {
    bool isFound = false;
    char searchName[maxSizeOfEntry] = {0};
    printf("Please, enter the phone by which\n");
    printf("you want to find the name:");
    scanf("%s", searchName);
    for (int i = 0; i < *cntOfEntries; ++i) {
        if (strcmp(searchName, entries[i]->phoneNumber) == 0) {
            printf("The following name was found: %s\n", entries[i]->name);
            isFound = true;
        }
    }
    if (!isFound) {
        printf("I didn't find any name by this phone number.\n");
    }
}

void freeEntries(dataBase **entries, int cntOfEntries) {
    for (int i = 0; i < cntOfEntries; ++i) {
        free(entries[i]);
    }
}

void command5(dataBase **entries, int *cntOfEntries, char *nameOfFile) {
    FILE *file = fopen(nameOfFile, "w");
    fprintf(file, "phoneNumbers names");
    for (int i = 0; i < *cntOfEntries; ++i) {
        fprintf(file, "\n%s %s", entries[i]->phoneNumber, entries[i]->name);
    }
    fclose(file);
}

int main() {
    char nameOfFile[maxSizeOfEntry] = {0};
    bool firstEntry = true;
    int cntOfEntries = 0;
    printf("Hello! Please, enter the full file path of your file\n");
    printf("in which we gonna input some phone numbers\n");
    printf("and names.\n");
    printf("I immediately warn you that the program is designed\n");
    printf("to work with names and numbers of no more than 100 characters.\n");
    printf("Your file path:");
    scanf("%s", nameOfFile);
    dataBase *entries[maxSizeOfEntry] = {NULL};
    for (int i = 0; i < maxSizeOfEntry; ++i) {
        entries[i] = calloc(1, sizeof(dataBase));
        if (entries[i] == NULL) {
            printf("Allocating memory for array suffered a setback!\n");
            freeEntries(entries, i);
            return -1;
        }
    }
    int isAnyError = readDataFromFile(entries, nameOfFile, &cntOfEntries);
    switch (isAnyError) {
        case 0:
            printf("The file was successfully found!\n");
            break;
        case -2:
            printf("This file does not exist!\n");
            printf("But I already created a file in this path\n");
            FILE *file = fopen(nameOfFile, "w");
            fclose(file);
            break;
        case -3:
            while (isAnyError == -3) {
                printf("This file was not created by this program!\n");
                printf("Please choose another file name\n");
                printf("The new filename is:");
                scanf("%s", nameOfFile);
                isAnyError = readDataFromFile(entries, nameOfFile, &cntOfEntries);
            }
            break;
    }
    instructionPrint();
    char instrAns[2] = {0};
    int whatToDo = readCommand();
    while (whatToDo != 0) {
        switch (whatToDo) {
            case 1:
                command1(entries, &cntOfEntries);
                break;
            case 2:
                command2(entries, &cntOfEntries);
                break;
            case 3:
                command3(entries, &cntOfEntries);
                break;
            case 4:
                command4(entries, &cntOfEntries);
                break;
            case 5:
                command5(entries, &cntOfEntries, nameOfFile);
        }
        printf("Would you like to repeat the instruction text?\n");
        printf("0 - no, anything else with one symbol - yes\n");
        printf("Repeating instruction answer:");
        scanf("%s", instrAns);
        if (strcmp(instrAns, "0\0")) {
            instructionPrint();
        }
        whatToDo = readCommand();
    }
}
