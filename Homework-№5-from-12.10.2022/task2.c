#include "stack.h"
#define maxSize 101

void stringInit(char* string)
{
    for (int i = 0; i < maxSize; ++i)
    {
        string[i] = '\0';
    }
}

void redefineOfBracket(char bracket, int* number)
{
    switch (bracket)
    {
        case '(':
            *number = 1;
            break;
        case '{':
            *number = 2;
            break;
        case '[':
            *number = 3;
            break;
        case '<':
            *number = 4;
            break;
        case ')':
            *number = -1;
            break;
        case '}':
            *number = -2;
            break;
        case ']':
            *number = -3;
            break;
        case '>':
            *number = -4;
            break;
        default:
            *number = 0;
            break;
    }
}

bool isBracketsAreBalanced(char* string)
{
    int stringElement = 0, tempPoppedElement = 0;
    stack *stackOfBrackets = NULL;
    int codeOfError = creationOfTheStack(&stackOfBrackets, sizeof(char));
    bool exitFlag = errorDispenser(codeOfError);
    if (exitFlag)
    {
        return codeOfError;
    }
    for (int i = 0; i < maxSize; ++i)
    {
        redefineOfBracket(string[i], &stringElement);
        if (stringElement > 0)
        {
            pushingToStack(stackOfBrackets, &stringElement);
        }
        else if (stringElement < 0)
        {
            exitFlag = isStackNotEmpty(stackOfBrackets);
            if (!exitFlag)
            {
                freeMemoryOfTheStack(stackOfBrackets);
                return false;
            }
            codeOfError =  poppingFromStack(stackOfBrackets, &tempPoppedElement);
            exitFlag = errorDispenser(codeOfError);
            if (exitFlag)
            {
                return codeOfError;
            }
            if (tempPoppedElement + stringElement)
            {
                freeMemoryOfTheStack(stackOfBrackets);
                return false;
            }
        }
    }
    if (isStackNotEmpty(stackOfBrackets))
    {
        freeMemoryOfTheStack(stackOfBrackets);
        return false;
    }
    freeMemoryOfTheStack(stackOfBrackets);
    return true;
}

int main()
{
    printf("Hello! Give me, please, string, which have size\n");
    printf("less than 100 symbols or equals to it.\n");
    printf("I will check out next fact: is this string\n");
    printf("contains balanced brackets or not?\n");
    printf("Your string:");
    char string[maxSize];
    stringInit(string);
    gets(string);
    bool answer = isBracketsAreBalanced(string);
    if (answer)
    {
        printf("Brackets in this string is balanced!\n");
        return 0;
    }
    else
    {
        printf("Brackets in this string is not balanced!\n");
        return 0;
    }
}
