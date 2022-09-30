#include <stdio.h>
#include <stdlib.h>

void swap(int *firstElement, int *secondElement)
{
    int temp = *secondElement;
    *secondElement = *firstElement;
    *firstElement = temp;
}

void bubbleSort(int *array, int lenOfArray)
{
    for (int i = 0; i < lenOfArray; ++i)
    {
        for (int j = 0; j < lenOfArray - 1; ++j)
        {
            if (array[j] > array[j + 1])
            {
                swap(&array[j], &array[j + 1]);
            }
        }
    }
}

void insertionSort(int *array, int lenOfArray)
{
    int maxOfArray = array[0], minOfArray = array[0], pointer = 0;
    for (int i = 0; i < lenOfArray; ++i)
    {
        if (array[i] > maxOfArray)
        {
            maxOfArray = array[i];
        }
        if (array[i] < minOfArray)
        {
            minOfArray = array[i];
        }
    }
    int *tempArray = malloc(sizeof(int) * (abs(maxOfArray - minOfArray) + 1));
    for (int i = 0; i < (abs(maxOfArray - minOfArray) + 1); ++i)
    {
        tempArray[i] = 0;
    }
    for (int i = 0; i < lenOfArray; ++i)
    {
        tempArray[array[i] - minOfArray] += 1;
    }
    for (int i = 0; i <(abs(maxOfArray - minOfArray) + 1); ++i)
    {
        if (tempArray[i] != 0)
        {
            array[pointer] = i + minOfArray;
            pointer += 1;
        }
    }
    free(tempArray);
}

int main()
{
    int sizeOfArray = 0;
    printf("Hello! Please, give me an array of integer numbers and\n");
    printf("I can sort it with a two different algorithms: bubble and insertion sort!\n");
    printf("Please, enter the size of your array which you want to sort\n");
    printf("then enter a integer element of array each on a new line\n");
    printf("The size of array is:");
    scanf("%d", &sizeOfArray);
    printf("The next %d integer elements of array is:\n", sizeOfArray);
    int *enteredArray = malloc(sizeof(int) * sizeOfArray);
    for (int i = 0; i < sizeOfArray; ++i)
    {
        scanf("%d", &enteredArray[i]);
    }
    printf("If you want to sort your array with a bubble-sort algorithm,\n");
    printf("please, enter '0'\n");
    printf("If you want to sort your array with a insertion-sort algorithm,\n");
    printf("please, enter '1'\n");
    printf("Your prefer is:");
    int userSetting = 0;
    scanf("%d", &userSetting);
    printf("Your sorted array is:\n");
    if (userSetting == 0)
    {
        bubbleSort(enteredArray, sizeOfArray);
        for (int i = 0; i < sizeOfArray; ++i)
        {
            printf("%d ", enteredArray[i]);
        }
    }
    else
    {
        insertionSort(enteredArray, sizeOfArray);
        for (int i = 0; i < sizeOfArray; ++i)
        {
            printf("%d ", enteredArray[i]);
        }
    }
}