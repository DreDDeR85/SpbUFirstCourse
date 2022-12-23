#include "stack.h"
#define MAX_SIZE 102 //i += 2

void stringReset(char *string)
{
    for (int i = 0; i < MAX_SIZE; ++i)
    {
        string[i] = '\0';
    }
}

bool isADigit(int symbol)
{
    return (('0' <= symbol) && (symbol <= '9'));
}

bool isItAnArithmeticSign(int symbol)
{
    return ((symbol == '+') || (symbol == '-') || (symbol == '/') || (symbol == '*'));
}

bool isItAValidSymbol(int symbol)
{
    return (isADigit(symbol) || isItAnArithmeticSign(symbol) || (symbol == ' ') || (symbol == '\0'));
}

bool isItAValidArithmeticExpression(char *string)
{
    for (int i = 0; i < MAX_SIZE - 1; ++i)
    {
        if (!isItAValidSymbol(string[i]))
        {
            return false;
        }
    }
    int cntOfDgs = 0, cntOfSigns = 0;
    for (int i = 0; i < MAX_SIZE - 1; i += 2)
    {
        if (!isADigit(string[i]) && !isItAnArithmeticSign(string[i]) && (string[i] != '\0'))
        {
            return false;
        }
        if (isADigit(string[i]))
        {
            ++cntOfDgs;
        }
        else if (isItAnArithmeticSign(string[i]))
        {
            ++cntOfSigns;
        }
    }
    return (cntOfDgs - cntOfSigns == 1);
}

int main()
{
    stack *arithmeticStack = NULL;
    bool exitFlag = false;
    int firstNumOperand = 0;
    int secondNumOperand = 1;
    int result = 1;
    int codeOfError = creationOfTheStack(&arithmeticStack, sizeof(int));
    exitFlag = errorDispenser(codeOfError);
    if (exitFlag)
    {
        return codeOfError;
    }
    printf("Hello! Please enter an arithmetic expression written\n");
    printf("in reverse Polish notation, and I will calculate it!\n");
    printf("Please separate the entered single-digit numbers\n");
    printf("and characters with a space \n");
    printf("Also the entered line must\n");
    printf("be less than 100 symbols or equal to it\n");
    printf("Your line:");
    char inputLine[MAX_SIZE] = {0};
    fgets(inputLine, 100, stdin);
    while (!isItAValidArithmeticExpression(inputLine))
    {
        printf("You have entered an incorrect string!\n");
        printf("Please enter the line again!\n");
        stringReset(inputLine);
        gets(inputLine);
    }

    int pointerToStringSymbol = 0;
    int tempNum = 0;
    while (inputLine[pointerToStringSymbol] != '\0')
    {
        if (isADigit(inputLine[pointerToStringSymbol]))
        {
            tempNum = inputLine[pointerToStringSymbol] - '0';
            codeOfError = pushingToStack(arithmeticStack, &tempNum);
            exitFlag = errorDispenser(codeOfError);
            if (exitFlag)
            {
                freeMemoryOfTheStack(arithmeticStack);
                return codeOfError;
            }
        }
        else if (isItAnArithmeticSign(inputLine[pointerToStringSymbol]))
        {
            codeOfError = poppingFromStack(arithmeticStack, &secondNumOperand);
            exitFlag = errorDispenser(codeOfError);
            if (exitFlag)
            {
                freeMemoryOfTheStack(arithmeticStack);
                return codeOfError;
            }
            codeOfError = poppingFromStack(arithmeticStack, &firstNumOperand);
            exitFlag = errorDispenser(codeOfError);
            if (exitFlag)
            {
                freeMemoryOfTheStack(arithmeticStack);
                return codeOfError;
            }
            if (inputLine[pointerToStringSymbol] != '/')
            {
                switch (inputLine[pointerToStringSymbol])
                {
                    case '+':
                        result = firstNumOperand + secondNumOperand;
                        break;
                    case '-':
                        result = firstNumOperand - secondNumOperand;
                        break;
                    case '*':
                        result = firstNumOperand * secondNumOperand;
                        break;
                }
                codeOfError = pushingToStack(arithmeticStack, &result);
                exitFlag = errorDispenser(codeOfError);
                if (exitFlag)
                {
                    freeMemoryOfTheStack(arithmeticStack);
                    return codeOfError;
                }
            } else
            {
                if (secondNumOperand == 0)
                {
                    printf("I can't divide any number by zero!\n");
                    freeMemoryOfTheStack(arithmeticStack);
                    return -6;
                }
                result = firstNumOperand / secondNumOperand;
                codeOfError = pushingToStack(arithmeticStack, &result);
                exitFlag = errorDispenser(codeOfError);
                if (exitFlag)
                {
                    freeMemoryOfTheStack(arithmeticStack);
                    return codeOfError;
                }
            }
        }
        pointerToStringSymbol += 2;
    }
    int answer = 0;
    codeOfError = poppingFromStack(arithmeticStack, &answer);
    exitFlag = errorDispenser(codeOfError);
    if (exitFlag)
    {
        freeMemoryOfTheStack(arithmeticStack);
        return codeOfError;
    }
    printf("The answer on this arithmetic expression is: %d\n", answer);
    return 0;
}
