#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#define MAX_SIZE 101

typedef struct saddleDot
{
    int maximumElement;
    int indexMaximum;
    int minimumElement;
    int indexMinimum;
} saddleDot;

void matrixInit(int* matrix, int sizeOfMatrix)
{
    for (int i = 0; i < sizeOfMatrix; ++i)
    {
        matrix[i] = MAX_SIZE;
    }
}

bool matrixCheck(int* matrix, int sizeOfMatrix)
{
    for (int i = 0; i < sizeOfMatrix; ++i)
    {
        if (matrix[i] > MAX_SIZE - 1)
        {
            return false;
        }
    }
    return true;
}

void saddleDotsFinder(int* array, int cntOfRows, int cntOfColumns, bool parameterRowOrColumn, int rowIndex, int columnIndex, struct saddleDot** arrOfSaddleDots)
{
    // parameterRowOrColumn == 0 - we will find a maximum and a minimum in row
    // parameterRowOrColumn == 1 - we will find a maximum and a minimum in column
    int maximum = -101;
    int indexMax = 0, indexMin = 0;
    int minimum = 101;
    if (!parameterRowOrColumn)
    {
        for (int i = rowIndex * cntOfColumns; i < rowIndex * cntOfColumns + cntOfColumns - 1; ++i)
        {
            if (array[i] > maximum)
            {
                maximum = array[i];
                indexMax = i;
            }
            if (array[i] < minimum)
            {
                minimum = array[i];
                indexMin = i;
            }
        }
        arrOfSaddleDots[rowIndex]->maximumElement = maximum;
        arrOfSaddleDots[rowIndex]->indexMaximum = indexMax;
        arrOfSaddleDots[rowIndex]->minimumElement = minimum;
        arrOfSaddleDots[rowIndex]->indexMinimum = indexMin;
    }
    else
    {
        for (int i = columnIndex; i < columnIndex + cntOfColumns * cntOfRows; i += cntOfColumns)
        {
            if (array[i] > maximum)
            {
                maximum = array[i];
                indexMax = i;
            }
            if (array[i] < minimum)
            {
                minimum = array[i];
                indexMin = i;
            }
        }
        arrOfSaddleDots[columnIndex + cntOfRows]->maximumElement = maximum;
        arrOfSaddleDots[columnIndex + cntOfRows]->indexMaximum = indexMax;
        arrOfSaddleDots[columnIndex + cntOfRows]->minimumElement = minimum;
        arrOfSaddleDots[columnIndex + cntOfRows]->indexMinimum = indexMin;
    }
}

int main()
{
    printf("Hello! Please give me the input n and m - two integers\n");
    printf("that are less than or equal to a 100 and which are\n");
    printf("the dimensions of the matrix that is falling on the input.\n");
    printf("Then enter n * m integers which are modulo less than or equal to 100\n");
    printf("separated by a space, of this matrix.\n");
    printf("I will display the indexes of all its saddle points, where the\n");
    printf("saddle point is the element that is the smallest in its row and the\n");
    printf("largest in its column or, conversely, the largest in its row and\n");
    printf("the smallest in its column.\n");
    printf("Your n and m:");
    int cntOfRows = 0, cntOfColumns = 0, errorCode = 0;
    scanf("%d %d", &cntOfRows, &cntOfColumns);
    int cntOfMatrixElements = cntOfRows * cntOfColumns;
    int* matrix = calloc(cntOfMatrixElements, sizeof(int));
    if (matrix == NULL)
    {
        printf("Allocating memory for the matrix suffered a setback!\n");
        return -1;
    }
    struct saddleDot* arrOfSaddleDots = calloc(cntOfColumns + cntOfRows, sizeof(struct saddleDot));
    if (arrOfSaddleDots == NULL)
    {
        printf("Allocating memory for the matrix suffered a setback!\n");
        return -1;
    }
    matrixInit(matrix, cntOfMatrixElements);
    printf("Now, please, enter %d integer numbers - elements of the matrix\n", cntOfMatrixElements);
    for (int i = 0; i < cntOfMatrixElements; ++i)
    {
        errorCode = scanf("%d", &matrix[i]);
        if (!errorCode)
        {
            printf("Your elements contains not only a integer numbers!\n");
            free(matrix);
            return -1;
        }
    }
    if (!matrixCheck(matrix, cntOfMatrixElements))
    {
        printf("Matrix contains less than %d elements!\n", cntOfMatrixElements);
        free(matrix);
        return -1;
    }
    for (int i = 0; i < cntOfRows; ++i)
    {
        saddleDotsFinder(matrix, cntOfRows, cntOfColumns, false, i, 0, &arrOfSaddleDots);
    }
    for (int i = 0; i < cntOfColumns; ++i)
    {
        saddleDotsFinder(matrix, cntOfRows, cntOfColumns, true, 0, i, &arrOfSaddleDots);
    }
    int answerArray[MAX_SIZE] = {0};
    for (int i = 0; i < MAX_SIZE; ++i)
    {
        answerArray[i] = -1;
    }
    int pointerToAnswerArray = 0;
    for (int i = 0; i < cntOfRows; ++i)
    {
        for (int j = 0; j < cntOfColumns; ++j)
        {
            if ((arrOfSaddleDots[i].maximumElement == arrOfSaddleDots[j].minimumElement) || (arrOfSaddleDots[i].minimumElement == arrOfSaddleDots[j].maximumElement))
            {
                answerArray[pointerToAnswerArray] = arrOfSaddleDots[i].indexMaximum;
                ++pointerToAnswerArray;
            }
        }
    }
    pointerToAnswerArray = 0;
    if (answerArray[pointerToAnswerArray] != -1)
    {
        printf("Here your saddle index for your matrix: ");
        while (answerArray[pointerToAnswerArray] != -1)
        {
            printf("%d ", answerArray[pointerToAnswerArray]);
            ++pointerToAnswerArray;
        }
    }
    else
    {
        printf("Your matrix doesn't contains any saddle dots!\n");
    }
    free(matrix);
}