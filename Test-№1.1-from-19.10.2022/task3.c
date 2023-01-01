#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#define maxSize 500

int countOfSymbols(char *path)
{
    FILE *testFile = fopen(path, "r");
    char symbol = "c";
    if (testFile == NULL)
    {
        printf("This file does not exist!");
        return -1;
    }
    printf("Your file read correctly!\n");
    int bigArray[maxSize] = {0};
    while (fscanf(testFile, "%c", &symbol) != EOF)
    {
        ++bigArray[symbol];
    }
    for (int i = 0; i < maxSize; ++i)
    {
        if (bigArray[i] != '0')
        {
            printf("%d %c", bigArray[i], char bigArray[i])
        }
    }
}

int main()
{
    int answer = 0;
    printf("Hello! I will count in your .txt file all symbols and print all of them,\n");
    printf("which contains in them one time or above. You should create in your path\n");
    printf("with your program a file 'testFile.txt' for correct working.\n");
    answer = countOfSymbols("testFile.txt");
    if (answer != -1)
    {


    }
}
