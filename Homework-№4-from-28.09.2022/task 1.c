#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define size 32 //in this task all lengths are a 32

void printOfArray(char *array)
{
    for (int i = 0; i < size; ++i)
    {
        printf("%c", array[i]);
    }
    printf("\n");
}

void initialization(char *array)
{
    for (int i = 0; i < size; ++i)
    {
        array[i] = '0';
    }
}

void binAddingOne(char *binOfNum)
{
    bool notExit = true;
    int i = size - 1;
    while (notExit)
    {
        if (binOfNum[i] == '1')
        {
            --i;
        }
        else
        {
            notExit = false;
            for (int j = i + 1; j < size; j++)
            {
                binOfNum[j] = '0';
            }
            binOfNum[i] = '1';
        }
    }
}

void reverse(char *array)
{
    for (int i = 0; i < size; ++i)
    {
        switch (array[i])
        {
            case '0':
                array[i] = '1';
                break;
            default:
                array[i] = '0';
                break;
        }
    }
}

void toBin(int number, char *binRepr)
{
    int temp = number;
    temp = abs(temp);
    int pointer = size - 1;
    while (temp > 0)
    {
        if (temp % 2 == 0)
        {
            binRepr[pointer] = '0';
        }
        else
        {
            binRepr[pointer] = '1';
        }
        temp /= 2;
        --pointer;
    }
    if (number < 0)
    {
        reverse(binRepr);
        binAddingOne(binRepr);
    }
}

int fromBin(char *binRepr)
{
    int number = 0;
    int temp = 1;
    bool isItOne = true;
    for (int i = size - 1; i > 0; --i)
    {
        isItOne = (binRepr[i] == '1');
        number += isItOne * temp;
        temp *= 2;
    }
    isItOne = (binRepr[0] == '1');
    number -= temp * isItOne;
    return number;
}

int binAdding(int firstNum, int secondNum, char *sum)
{
    char *binOfFirstNum = calloc(size, sizeof(char));
    if (binOfFirstNum == NULL)
    {
        printf("Allocating memory for array suffered a setback!\n");
        return -1;
    }
    char *binOfSecondNum = calloc(size, sizeof(char));
    if (binOfSecondNum == NULL)
    {
        printf("Allocating memory for array suffered a setback!\n");
        return -1;
    }
    initialization(binOfSecondNum);
    initialization(binOfFirstNum);
    toBin(firstNum, binOfFirstNum);
    toBin(secondNum, binOfSecondNum);
    printOfArray(binOfFirstNum);
    printOfArray(binOfSecondNum);
    bool inMind = false;
    for (int i = size - 1; i >= 0; i--)
    {
        if ((binOfSecondNum[i] == '1') && (binOfFirstNum[i] == '1') && inMind)
        {
            sum[i] = '1';
        }
        else if ((binOfSecondNum[i] == '1') && (binOfFirstNum[i] == '1'))
        {
            sum[i] = '0';
            inMind = true;
        }
        else if (((binOfSecondNum[i] == '1') || (binOfFirstNum[i] == '1')) && inMind)
        {
            sum[i] = '0';
        }
        else if ((binOfSecondNum[i] == '1') || (binOfFirstNum[i] == '1'))
        {
            sum[i] = '1';
        }
        else if (inMind)
        {
            sum[i] = '1';
            inMind = false;
        }
        else
        {
            sum[i] = '0';
        }
    }
    return 0;
}

int main()
{
    int firstNumber = 0;
    scanf("%d", &firstNumber);
    int secondNumber = 0;
    scanf("%d", &secondNumber);
    char *binFirstNum = calloc(size, sizeof(char));
    if (binFirstNum == NULL)
    {
        printf("Allocating memory for array suffered a setback!\n");
        return -1;
    }
    char *binSecondNum = calloc(size, sizeof(char));
    if (binSecondNum == NULL)
    {
        printf("Allocating memory for array suffered a setback!\n");
        return -1;
    }
    char *binSum = calloc(size, sizeof(char));
    if (binSum == NULL)
    {
        printf("Allocating memory for array suffered a setback!\n");
        return -1;
    }
    binAdding(firstNumber, secondNumber, binSum);
    printOfArray(binSum);
    int sum = fromBin(binSum);
    printf("%d", sum);
}
