#include <stdio.h>
#include <string.h>
#define TRIAD 3
#define MAXSIZE 256 + 3 // 256 for the string, 2 for the additional digits
                        // and one for the dark lord in the dark throne
                        // in the land of Mordor, where the shadows lie.
                        // (one for the '\0')

void shift(char* string, int cntOfShifts, int lenOfString)
{
    if (cntOfShifts == 0)
    {
        return;
    }
    for (int j = 0; j < cntOfShifts; ++j)
    {
        for (int i = lenOfString - 1 + cntOfShifts; i > 0; --i)
        {
            string[i] = string[i - 1];
        }
        string[0] = '0';
    }
}

void cutFromString(char* buffer, char* string, int fromWhere)
{
    for (int i = 0; i < TRIAD; ++i)
    {
        buffer[i] = string[fromWhere + i];
    }
}

int triadTable(char* buffer, char* transfer)
{
    char zero[] = {'0', '0', '0', '\0'};
    char one[] = {'0', '0', '1', '\0'};
    char two[] = {'0', '1', '0', '\0'};
    char three[] = {'0', '1', '1', '\0'};
    char four[] = {'1', '0', '0', '\0'};
    char five[] = {'1', '0', '1', '\0'};
    char six[] = {'1', '1', '0', '\0'};
    char seven[] = {'1', '1', '1', '\0'};
    char stop[] = {'\0', '\0', '\0', '\0'};
    char anotherStop[] = {'\n', '\0', '\0', '\0'};

    if (!strcmp(buffer, zero))
    {
        *transfer = '0';
        return 0;
    }
    else if (!strcmp(buffer, one))
    {
        *transfer = '1';
        return 0;
    }
    else if (!strcmp(buffer, two))
    {
        *transfer = '2';
        return 0;
    }
    else if (!strcmp(buffer, three))
    {
        *transfer = '3';
        return 0;
    }
    else if (!strcmp(buffer, four))
    {
        *transfer = '4';
        return 0;
    }
    else if (!strcmp(buffer, five))
    {
        *transfer = '5';
        return 0;
    }
    else if (!strcmp(buffer, six))
    {
        *transfer = '6';
        return 0;
    }
    else if (!strcmp(buffer, seven))
    {
        *transfer = '7';
        return 0;
    }
    else if (!strcmp(buffer, stop))
    {
        return 1;
    }
    else if (!strcmp(buffer, anotherStop))
    {
        return 1;
    }
    return -1;
}

int main()
{
    printf("Hello! Please give me an input number\n");
    printf("written in binary notation that does\n");
    printf("not exceed characters 0 and 1\n");
    printf("Your number:");
    char inputBinNum[MAXSIZE] = {0};
    fgets(inputBinNum, MAXSIZE - 3, stdin);
    int lenOfTheBinNum = (int) strlen(inputBinNum) - 1;
    int cntOfShifts = (TRIAD - lenOfTheBinNum % TRIAD) % TRIAD;
    shift(inputBinNum, cntOfShifts, lenOfTheBinNum);
    char buffer[TRIAD + 1] = {0};
    int errorCode = 0;
    int pointerToOctNumberPos = 0;
    char addingOctDigit = '\0';
    char octNumber[(MAXSIZE + 2) / TRIAD + 1] = {0}; // the maximum length of octNum from 256-digit
                                                 // binNum is 86
    for (int i = 0; i < MAXSIZE - 2; i += 3)
    {
        cutFromString(buffer, inputBinNum, i);
        errorCode = triadTable(buffer, &addingOctDigit);
        if (errorCode == -1)
        {
            printf("Entered string is not a binary number!\n");
            return -1;
        }
        else if (errorCode == 1)
        {
            break;
        }
        octNumber[pointerToOctNumberPos] = addingOctDigit;
        ++pointerToOctNumberPos;
    }
    printf("Your number in octal notation:%s\n", octNumber);
}
