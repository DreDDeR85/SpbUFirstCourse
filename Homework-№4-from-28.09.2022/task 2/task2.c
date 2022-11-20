#include "task2.h"

bool checker(int *firstArray, int *secondArray)
{
    bool checkerAns = true;
    for (int i = 0; i < 2; ++i)
    {
        checkerAns = (checkerAns && (firstArray[i] == secondArray[i]));
    }
    return checkerAns;
}

void tests(void)
{
    int arrTestLen = 9;
    bool isTestPassed = true;
    int subArr[] = {0, 1};

    int arrTest1[] = {4, 8, -5, 4, 0, 2, 1, 9, 5};
    int arrTest1Ans[] = {4, 2};
    int arrTest2[] = {4, 4, 4, 4, 4, 4, 4, 4, 4};
    int arrTest2Ans[] = {4, 9};
    int arrTest3[] = {1, 2, 3, 4, 5, 6, 7, 9, 0};
    int arrTest3Ans[] = {0, 1};
    int arrTest4[] = {5, 6, 7, 5, 6, 7, -2, -4, -2};
    int arrTest4Ans[] = {-2, 2};

    mostPopularElement(arrTest1, arrTestLen, subArr);
    isTestPassed = (isTestPassed && checker(subArr, arrTest1Ans));

    mostPopularElement(arrTest2, arrTestLen, subArr);
    isTestPassed = (isTestPassed && checker(subArr, arrTest2Ans));

    mostPopularElement(arrTest3, arrTestLen, subArr);
    isTestPassed = (isTestPassed && checker(subArr, arrTest3Ans));

    mostPopularElement(arrTest4, arrTestLen, subArr);
    isTestPassed = (isTestPassed && checker(subArr, arrTest4Ans));
    if (isTestPassed)
    {
        printf("Test are passed!\n");
    }
    else
    {
        printf("Tests are not passed!\n");
    }

}


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