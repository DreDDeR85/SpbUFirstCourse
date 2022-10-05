#include <stdio.h>
#include <stdlib.h>

void printArr(int *array, int lenOfArray)
{
    for (int i = 0; i < lenOfArray; ++i)
    {
        printf("%d ", array[i]);
    }
}

void insertionSort(int *arr, int arrStart, int arrEnd)
{
    int separator = arrStart;
    for (int i = arrStart + 1; i <= arrEnd; ++i)
    {
        separator = arr[i];
        int j = i - 1;
        while ((arr[j] > separator) && (j >= 0))
        {
            arr[j + 1] = arr[j];
            j -= 1;
        }
        arr[j + 1] = separator;
    }
}

void swap(int *firstElement, int *secondElement)
{
    int temp = *secondElement;
    *secondElement = *firstElement;
    *firstElement = temp;
}

int divide(int *array, int left, int right)
{
    int changingElem = left;
    for (int i = left; i < right; ++i)
    {
        if (array[i] < array[right])
        {
            swap(&array[changingElem], &array[i]);
            changingElem += 1;
        }
    }
    swap(&array[right], &array[changingElem]);
    return changingElem;
}

void quickSortRec(int *array, int left, int right)
{
    if (left < right)
    {
        if (right - left + 1 < 10)
        {
            insertionSort(array, left, right);
        }
        else
        {
            int centerElem = divide(array, left, right);
            quickSortRec(array, left, centerElem - 1);
            quickSortRec(array, centerElem + 1, right);
        }
    }
}

void quickSort(int *array, int lenOfArray)
{
    quickSortRec(array, 0, lenOfArray - 1);
}

int main() {
    int lenOfArray = 0, temp = 0;
    printf("Hello! Please, give me a natural size of array and an array,\n");
    printf("And I will sort him by quick sort and if subarray (or array)\n");
    printf("has length < 10 I will sort him by insertion sort\n");
    printf("Your size of array is:");
    scanf("%d", &lenOfArray);
    int *array = malloc(sizeof(int) * lenOfArray);
    printf("Now please enter the %d integer numbers - the elements of array:\n", lenOfArray);
    for (int i = 0; i < lenOfArray; ++i)
    {
        scanf("%d", &temp);
        array[i] = temp;
    }
    quickSort(array, lenOfArray);
    printf("This is yours sorted array!\n");
    printArr(array, lenOfArray);
    free(array);
}
