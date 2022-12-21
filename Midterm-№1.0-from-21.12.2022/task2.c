#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#define NAMEMAXSIZE 50
#define FILEMAXSIZE 1000

typedef struct product
{
    char name[NAMEMAXSIZE];
    char price[NAMEMAXSIZE];
} product;

void swap(struct product** firstElement, struct product** secondElement)
{
    struct product* temp = *secondElement;
    *secondElement = *firstElement;
    *firstElement = temp;
}

int divide(struct product** array, int left, int right, int numOfParameter)
{
    if (!numOfParameter)
    {
        int changingElem = left;
        for (int i = left; i < right; ++i)
        {
            if (array[i]->name < array[right]->name)
            {
                swap(&array[changingElem], &array[i]);
                changingElem += 1;
            }
        }
        swap(&array[right], &array[changingElem]);
        return changingElem;
    }
    else
    {
        int changingElem = left;
        for (int i = left; i < right; ++i)
        {
            if (array[i]->price < array[right]->price)
            {
                swap(&array[changingElem], &array[i]);
                changingElem += 1;
            }
        }
        swap(&array[right], &array[changingElem]);
        return changingElem;
    }

}

void quickSortRec(struct product** array, int left, int right, int numOfParameter)
{
    if (left < right)
    {
        int centerElem = divide(array, left, right, numOfParameter);
        quickSortRec(array, left, centerElem - 1, numOfParameter);
        quickSortRec(array, centerElem + 1, right, numOfParameter);
    }
}

void quickSort(struct product** array, int lenOfArray, int numOfParameter)
{
    quickSortRec(array, 0, lenOfArray - 1, numOfParameter);
}

bool isItADigit(char symbol)
{
    return ((symbol >= '0') && (symbol <= '9'));
}

bool isItANumber(char* string)
{
    for (int i = 0; i < NAMEMAXSIZE; ++i)
    {
        if (!isItADigit(string[i]))
        {
            return false;
        }
    }
    return true;
}

int readFromFile(struct product* ourFile)
{
    FILE* file = fopen("storage.txt", "r");
    struct product** arrayOfFileElements = calloc(FILEMAXSIZE, sizeof(product));
    char readableSymbol = fgetc(file);
    char readableString[NAMEMAXSIZE];
    int pointerToReadStringSym = 0;
    int pointerToArrProduct = 0;
    if (readableSymbol == EOF)
    {
        fclose(file);
        return -1;
    }
    while (readableSymbol != EOF)
    {
        if (readableSymbol == '-')
        {
            if (!(pointerToArrProduct % 2))
            {
                strcpy(arrayOfFileElements[pointerToArrProduct / 2]->name, readableString);
                reset(readableString);
                continue;
            }
            else
            {
                strcpy(arrayOfFileElements[pointerToArrProduct / 2]->price, readableString);
                reset(readableString);
                continue;
            }

        }
        else if (readableSymbol == ' ')
        {
            continue;
        }
        else:
        {
            readableString[pointerToReadStringSym] = readableSymbol;

        }
    }
    fclose(file);
}