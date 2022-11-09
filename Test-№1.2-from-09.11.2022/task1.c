#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

void swap(int *firstElement, int *secondElement)
{
    int temp = *firstElement;
    *firstElement = *secondElement;
    *secondElement = temp;
}

void printArray(int *array, int lenOfArray)
{
    for (int i = 0; i < lenOfArray; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}


void evenOddSort(int *array, int lenOfArray)
{
    int leftPointer = 0, rightPointer = lenOfArray - 1;
    while (leftPointer < rightPointer)
    {
        if (array[leftPointer] % 2 == 1)
        {
            if (array[rightPointer] % 2 == 0)
            {
                swap(&array[leftPointer], &array[rightPointer]);
                leftPointer++;
                rightPointer--;
            }
            else
            {
                rightPointer--;
            }
        }
        else
        {
            leftPointer++;
        }
    }
}

bool isCorrArray(int *array, int lenOfArray)
{
    bool answer = true;
    bool AreNotWeChangedTheNowOst = true;
    int nowOst = 0;
    for (int i = 0; i < lenOfArray; i++)
    {
        if ((abs(array[i]) % 2) != nowOst)
        {
            if (AreNotWeChangedTheNowOst)
            {
                nowOst = 1 - nowOst;
                AreNotWeChangedTheNowOst = false;
            }
            else
            {
                return false;
            }
        }
    }
    return true;
}

void tests()
{
    int array1[10] = {4, 3, 8, 425, -45, 0, 9, -1, 93, 68};
    int array2[10] = {2, 22, 16, -6, -9, -33, -11, 5, 21321, 9};
    evenOddSort(array1, 10);
    evenOddSort(array2, 10);
    if (isCorrArray(array1, 10))
    {
        printf("The first test passed correctly!\n");
    }
    else
    {
        printf("Program failed on the first test!\n");
    }
    if (isCorrArray(array2, 10))
    {
        printf("The second test passed correctly!\n");
    }
    else
    {
        printf("Program failed on the second test!\n");
    }
}

int main()
{
    tests();
    int lenOfArray = 0;
    printf("Hello! Please, give me a N - size of array\n");
    printf("and then N integer numbers - elements of array.\n");
    printf("I will sort your array by special even-odd sort,\n");
    printf("and after this sort you will get a array with even\n");
    printf("numbers at the start of array and then the odd numbers.\n");
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
    evenOddSort(array, lenOfArray);
    printf("Sorted array with even-odd sort is:\n");
    printArray(array, lenOfArray);
    free(array);
}