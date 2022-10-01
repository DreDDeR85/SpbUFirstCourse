#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *firstElement, int *secondElement)
{
    int temp = *secondElement;
    *secondElement = *firstElement;
    *firstElement = temp;
}

void firstQsortStep(int *array, int lenOfArray)
{
    int mainElement = array[0], leftPointer = 1, rightPointer = lenOfArray - 1;
    while(leftPointer < rightPointer)
    {
        while (array[leftPointer] < mainElement)
        {
            leftPointer += 1;
        }
        while (array[rightPointer] >= mainElement)
        {
            rightPointer -= 1;
        }
        if (leftPointer < rightPointer)
        {
            swap(&array[leftPointer], &array[rightPointer]);
        }
    }
    swap(&array[0], &array[leftPointer - 1]);
}

void elementOfArrayGeneration(int *element)
{
    int sign = rand() % 100;
    int temp = (rand() % 100) * (1 + (-2) * (sign % 2));
    *element = temp;
}

void arrayGeneration(int *array, int sizeOfArray)
{
    for (int i = 0; i < sizeOfArray; i++)
    {
        elementOfArrayGeneration(&array[i]);
    }
}

int main()
{
    srand(time(NULL));
    int sizeOfArray = 0;
    printf("Hello! Please, give me a N - natural number of size of array,\n");
    printf("ans I will generate an array with N length, which I will fill\n");
    printf("a random numbers x, -100 <= x <= 100.\n");
    printf("Then I will sort this array for the first element so that\n");
    printf("for the left side of this element will be elements which are smaller\n");
    printf("than it and for the right side - which are bigger.\n");
    printf("The size of array =");
    scanf("%d", &sizeOfArray);
    int *array = malloc(sizeof(int) * sizeOfArray);
    arrayGeneration(array, sizeOfArray);
    printf("That is the generated array:\n");
    for (int i = 0; i < sizeOfArray; ++i)
    {
        printf("%d ", array[i]);
    }
    firstQsortStep(array, sizeOfArray);
    printf("\nThe sorted random generated array with an %d elements is\n", sizeOfArray);
    for (int i = 0; i < sizeOfArray; ++i)
    {
        printf("%d ", array[i]);
    }
    free(array);
}