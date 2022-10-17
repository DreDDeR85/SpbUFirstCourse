#include <stdio.h>
#include <stdlib.h>
#define arrTestLen 9

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

void mostPopularElement(int *array, int lenOfArray, int *subArr)
{
    int maxElem = 0, cntOfElem = 1, maxCnt = 1;
    quickSort(array, lenOfArray);
    maxElem = array[0];
    for (int i = 0; i < lenOfArray - 1; ++i)
    {
        if (array[i] == array[i + 1])
        {
            cntOfElem += 1;
        }
        else
        {
            if (cntOfElem > maxCnt)
            {
                maxCnt = cntOfElem;
                maxElem = array[i];
            }
            cntOfElem = 1;
        }
    }
    if (cntOfElem > maxCnt)
    {
        maxCnt = cntOfElem;
    }
    subArr[0] = maxElem;
    subArr[1] = maxCnt;
}

void tests(void)
{
    int subArr[] = {0, 1};
    int arrTest1[] = {4, 8, -5, 4, 0, 2, 1, 9, 5};
    int arrTest2[] = {4, 4, 4, 4, 4, 4, 4, 4, 4};
    int arrTest3[] = {1, 2, 3, 4, 5, 6, 7, 9, 0};
    int arrTest4[] = {5, 6, 7, 5, 6, 7, -2, -4, -2};

    printf("Test number one. Original array is:\n");
    printArr(arrTest1, arrTestLen);
    mostPopularElement(arrTest1, arrTestLen, subArr);
    printf("Most popular element in this array is %d. It occurs a %d times.\n", subArr[0], subArr[1]);

    printf("Test number two. Original array is:\n");
    printArr(arrTest2, arrTestLen);
    mostPopularElement(arrTest2, arrTestLen, subArr);
    printf("Most popular element in this array is %d. It occurs a %d times.\n", subArr[0], subArr[1]);

    printf("Test number three. Original array is:\n");
    printArr(arrTest3, arrTestLen);
    mostPopularElement(arrTest3, arrTestLen, subArr);
    printf("Most popular element in this array is %d. It occurs a %d times.\n", subArr[0], subArr[1]);

    printf("Test number four. Original array is:\n");
    printArr(arrTest4, arrTestLen);
    mostPopularElement(arrTest4, arrTestLen, subArr);
    printf("Most popular element in this array is %d. It occurs a %d times.\n", subArr[0], subArr[1]);
}

int main()
{
    tests();
    int lenOfArray = 0, temp = 0;
    int subArr[] = {0, 1};
    printf("Hello! Please, give me a natural n - size of array,\n");
    printf("and then n integer numbers - elements of array\n");
    printf("I will find most popular element in this array faster, than O(n^2)!\n");
    printf("Your n =");
    scanf("%d", &lenOfArray);
    int *array = malloc(sizeof(int) * lenOfArray);
    printf("Now, please, enter the %d integer of your array:\n", lenOfArray);
    for (int i = 0; i < lenOfArray; ++i)
    {
        scanf("%d", &temp);
        array[i] = temp;
    }
    mostPopularElement(array, lenOfArray, subArr);
    printf("The most popular element in entered array is %d.\n", subArr[0]);
    printf("In this array this element contains by %d times", subArr[1]);
    free(array);
}
