#include <stdio.h>
#include <stdlib.h>

void swap(int *firstElement, int *secondElement)
{
    int temp = *secondElement;
    *secondElement = *firstElement;
    *firstElement = temp;
}

void selectionSort(int *array, int lenOfArray)
{
    int minim = 0, pointer = 0;
    for (int i = 0; i < lenOfArray; ++i)
    {
        minim = array[i];
        pointer = i;
        for (int j = i + 1; j < lenOfArray; ++j)
        {
            if (array[j] < minim)
            {
                minim = array[j];
                pointer = j;
            }
        }
        if (array[i] > minim)
        {
            swap(&array[i], &array[pointer]);
        }
    }
}

void printOfArray(int *array, int lenOfArray)
{
    for (int i = 0; i < lenOfArray; ++i)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main()
{
    int lenOfArray = 0;
    printf("Hello! Please, give me an array of N elements,\n");
    printf("and I will sort this array by Selection sort!\n");
    printf("First you must give me a N - number of array's elements,\n");
    printf("Then you should give me a N elements, each on the new line.\n");
    printf("The size N of array:");
    scanf("%d", &lenOfArray);
    int *array = calloc(lenOfArray, sizeof(int));
    if (array == NULL)
    {
        printf("Allocating memory for array suffered a setback!\n");
        return -1;
    }
    for (int i = 0; i < lenOfArray; ++i)
    {
        scanf("%d", &array[i]);
    }
    printf("Entered array:");
    printOfArray(array, lenOfArray);
    selectionSort(array, lenOfArray);
    printf("Sorted array:");
    printOfArray(array, lenOfArray);
    free(array);
}
