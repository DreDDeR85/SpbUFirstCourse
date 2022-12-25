#include <stdio.h>
#include <string.h>
#define MAX_SIZE 101

int main()
{
    printf("Hello! Please, give me a file, which contains\n");
    printf("Some information. I will delete all duplications\n");
    printf("of spaces and line breaks\n");
    printf("Please, enter the name of the file,\n");
    printf("which length is less than 100 or equal to it:\n");
    char nameOfFile[MAX_SIZE] = {0};
    fgets(nameOfFile, MAX_SIZE - 1, stdin);
    nameOfFile[strlen(nameOfFile) - 1] = '\0';
    FILE* file = fopen(nameOfFile, "r");
    if (file == NULL)
    {
        printf("%s do not exist!\n", nameOfFile);
        return -1;
    }
    int previousSymbol = 0;
    int currentSymbol = fgetc(file);
    printf("There are your file without any duplications\n");
    printf("of spaces and line breaks!\n");
    while (currentSymbol != EOF)
    {
        if ((((currentSymbol == '\n') || (currentSymbol == ' ')) && (currentSymbol != previousSymbol)) || ((currentSymbol != '\n') && (currentSymbol != ' ')))
        {
            printf("%c", currentSymbol);
        }
        previousSymbol = currentSymbol;
        currentSymbol = fgetc(file);
    }
    return 0;
}
