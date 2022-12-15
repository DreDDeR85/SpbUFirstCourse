#include <stdio.h>
#include <stdlib.h>

void swapElements(int *arrayToReverse, int leftPointer, int rightPointer)
{
    for (int indexForSwap = leftPointer; indexForSwap < (rightPointer + leftPointer) / 2; indexForSwap++)
    { //a = x, b = y --> a = y, b = x
        arrayToReverse[indexForSwap] = arrayToReverse[indexForSwap] + arrayToReverse[rightPointer - indexForSwap - 1 + leftPointer]; //a = a + b
        arrayToReverse[rightPointer - indexForSwap - 1 + leftPointer] = arrayToReverse[indexForSwap] - arrayToReverse[rightPointer - indexForSwap - 1 + leftPointer]; //b = a - b
        arrayToReverse[indexForSwap] = arrayToReverse[indexForSwap] - arrayToReverse[rightPointer - indexForSwap - 1 + leftPointer]; //a = a - b
    } //a = y, b = x
}

void printArr(int *array, int lenOfArray)
{
    for (int i = 0; i < lenOfArray; ++i)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main(){
    printf("Hello! Please, give me two glued arrays a and b, and I'll give them back glued together b + a!\n");
    printf("In the first line give me a size x of a first array X, in the second line give me a size y of a second array Y. x and y are natural numbers.\n");
    printf("After this give a x + y elements of integer numbers of the glued arrays X and Y. Then i will swap arrays!\n");
    int lenOfTheFirstArr = 0, lenOfTheSecondArr = 0, enteredElement = 0;
    printf("Length of the first array:");
    scanf("%d", &lenOfTheFirstArr);
    printf("Length of the second array:");
    scanf("%d", &lenOfTheSecondArr);
    int *originalArray = malloc((lenOfTheFirstArr + lenOfTheSecondArr) * sizeof(int));
    printf("%d elements of the whole array:\n", lenOfTheSecondArr + lenOfTheFirstArr);
    for (int i = 0; i < lenOfTheFirstArr + lenOfTheSecondArr; ++i)
    {
        scanf("%d", &enteredElement);
        originalArray[i] = enteredElement;
    }
    printf("Original glued arrays:\n");
    printArr(originalArray, lenOfTheSecondArr + lenOfTheFirstArr);
    swapElements(originalArray, 0, lenOfTheFirstArr + lenOfTheSecondArr);
    swapElements(originalArray, 0, lenOfTheSecondArr);
    swapElements(originalArray, lenOfTheSecondArr, lenOfTheFirstArr + lenOfTheSecondArr);
    printf("I have finished my work! Swaped arrays:\n");
    printArr(originalArray, lenOfTheSecondArr + lenOfTheFirstArr);
}