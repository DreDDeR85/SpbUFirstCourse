#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAXNUM 100
#define lenArrForTest 9

void printArr(int *array, int lenOfArray)
{
    for (int i = 0; i < lenOfArray; ++i)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
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
        int centerElem = divide(array, left, right);
        quickSortRec(array, left, centerElem - 1);
        quickSortRec(array, centerElem + 1, right);
    }
}

void quickSort(int *array, int lenOfArray)
{
    quickSortRec(array, 0, lenOfArray - 1);
}

void genOfArray(int *array, int lenOfArray)
{
    for (int i = 0; i < lenOfArray; ++i)
    {
        array[i] = (rand() % MAXNUM) * (1 + (rand() % 2) * (-2));
    }
}

int binSearch(int *array, int searchElem, int left, int right)
{
    if (left > right)
    {
        return -1;
    }
    int middle = left + (right - left) / 2;
    if (array[middle] == searchElem)
    {
        return 1;
    }
    else if(array[middle] < searchElem)
    {
        return binSearch(array, searchElem, middle + 1, right);
    }
    else
    {
        return binSearch(array, searchElem, left, middle - 1);
    }
}

void tests(void)
{
    int arrTest1[] = {1, 2, 3, 4, -5, -6, -7, -8, 0};
    int arrTest2[] = {-43, 3, 23, -54, 34, 86, -32, 66, -12};
    int numTest1[] = {6, 3, 9, 43, 0, 8, 4, -5, -12};
    int numTest2[] = {1, 34, -54, -90, -91, -32, 22, 55, 11};
    printf("This is a test number 1. Original array is:\n");
    printArr(arrTest1, lenArrForTest);
    quickSort(arrTest1, lenArrForTest);
    for (int i = 0; i < lenArrForTest; ++i)
    {
        if (binSearch(arrTest1, numTest1[i], 0, lenArrForTest) == 1)
        {
            printf("Pseudo random generated number is %d, and %d contains in the array!\n", numTest1[i], numTest1[i]);
        }
        else
        {
            printf("Pseudo random generated number is %d, and %d not contains in the array!\n", numTest1[i], numTest1[i]);
        }
    }
    printf("This is a test number 2. Original array is:\n");
    printArr(arrTest2, lenArrForTest);
    quickSort(arrTest2, lenArrForTest);
    for (int i = 0; i < lenArrForTest; ++i)
    {
        if (binSearch(arrTest2, numTest2[i], 0, lenArrForTest) == 1)
        {
            printf("Pseudo random generated number is %d, and %d contains in the array!\n", numTest2[i], numTest2[i]);
        }
        else
        {
            printf("Pseudo random generated number is %d, and %d not contains in the array!\n", numTest2[i], numTest2[i]);
        }
    }
}

int main()
{
    tests();
    srand(time(NULL));
    int n = 0, k = 0, answer = 0;
    printf("Hello! Please, give me a 2 numbers: n and k,\n");
    printf("where n is the natural size of array with n random numbers\n");
    printf("and k is your next k integer entered numbers, which you want\n");
    printf("to check on existence in array\n");
    printf("Your n:");
    scanf("%d", &n);
    printf("Your k:");
    scanf("%d", &k);
    int *arrayAnswer = malloc(sizeof(int) * k);
    int *array = malloc(sizeof(int) * n);
    genOfArray(array, n);
    printf("The generation of array is complete! Random generated array:\n");
    printArr(array, n);
    genOfArray(arrayAnswer, k);
    printf("The generation of k numbers is complete! Random generated k numbers:\n");
    printArr(arrayAnswer, k);
    quickSort(array, n);
    for (int i = 0; i < k; ++i) {
        answer = binSearch(array, arrayAnswer[i], 0, n - 1);
        if (answer == 1) {
            printf("The element %d contains in the array!\n", arrayAnswer[i]);
        } else {
            printf("The element %d do not contains in the array!\n", arrayAnswer[i]);
        }
    }
    free(array);
 
