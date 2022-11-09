#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

void printArray(int *array, int lenOfArray)
{
    for (int i = 0; i < lenOfArray; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void swap(int *firstElement, int *secondElement)
{
    int temp = *firstElement;
    *firstElement = *secondElement;
    *secondElement = temp;
}

bool isCorrectedArray(int *array, int lenOfArray)
{
   for (int i = 0; i < lenOfArray - 1; i++)
   {
       if (array[i] > array[i + 1])
       {
           return false;
       }
   }
   return true;
}

void bogosort(int *array, int lenOfArray)
{
    while (!isCorrectedArray(array, lenOfArray))
    {
        swap(&array[0], &array[rand() % lenOfArray]);
    }
}

int ma2in()
{
    srand(time(NULL));
    int lenOfArray = 0;
    printf("Hello! Please, give me a N - size of array\n");
    printf("and then N integer numbers - elements of array.\n");
    printf("I will sort your array with a bogosort!\n");
    printf("WARNING: do not enter the number, which is greater than 13!\n");
    printf("Programm will be working too long!\n");
    printf("Number N is:");
    scanf("%d", &lenOfArray);
    int *array = calloc(lenOfArray, sizeof(int));
    if (array == NULL)
    {
        printf("Allocating memory for the array didn't work correctly!\n");
        return 0;
    }
    printf("Now, please, give me a %d integer numbers\n", lenOfArray);
    for (int i = 0; i < lenOfArray; i++)
    {
        scanf("%d", &array[i]);
    }
    printf("Entered array is:\n");
    printArray(array, lenOfArray);
    bogosort(array, lenOfArray);
    printf("Sorted array with bogosort is:\n");
    printArray(array, lenOfArray);
    free(array);
}