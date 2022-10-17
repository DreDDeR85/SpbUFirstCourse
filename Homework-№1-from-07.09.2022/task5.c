#include <stdio.h>
#include <stdlib.h>
#define constLenString 1000

char bracketReverse(char bracket)
{
    if (bracket == ')')
    {
        return '(';
    }
    else if (bracket == ']')
    {
        return '[';
    }
    else if (bracket == '}')
    {
        return '{';
    }
    else if (bracket == '>')
    {
        return '<';
    }
    else
    {
        return 'c';
    }
}

void initialization(char *array, int lenOfArray)
{
    for (int i = 0; i < lenOfArray; ++i)
    {
        array[i] = ' ';
    }
}

int task5(char *string)
{
    int trueLen = 0;
    for (int i = 0; i < constLenString; ++i)
    {
        if (string[i] != ' ')
        {
            trueLen++;
        }
    }
    char *stack = malloc(sizeof(char) * trueLen);
    initialization(stack, trueLen);
    int pointer = 0;
    for (int strInd = 0; strInd < trueLen; strInd++)
    {
        if ((string[strInd] == '[') || (string[strInd] == '<') || (string[strInd] == '(') || (string[strInd] == '{'))
        {
            stack[pointer] = string[strInd];
            pointer += 1;
        }
        else if ((string[strInd] == ']') || (string[strInd] == '>') || (string[strInd] == ')') || (string[strInd] == '}'))
        {
            pointer -= 1;
            if (stack[pointer] != bracketReverse(string[strInd]))
            {
                return -1;
            }
        }
    }
    if (pointer == 0)
    {
        return 1;
    }
    return -1;
}

int main()
{
    char string[constLenString];
    initialization(string, constLenString);
    printf("Hello! Please, give me a string of brackets with less than a 1000 chars and I will check it for balance\n");
    printf("You can choose any of these brackets for your string: (, [, {, <, >, }, ], ),\n");
    printf("and any other symbols except the space ' '.\n");
    printf("The string is:");
    scanf("%s", string);
    int answer = task5(string);
    if (answer == -1)
    {
        printf("The string is not balanced");
    }
    else
    {
        printf("The string is balanced!");
    }
}