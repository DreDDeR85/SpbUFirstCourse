#include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE 101

bool firstCondition(int symbol) // the symbol satisfies the condition [1-9 A-E a-e]
{
    return (((symbol >= 'A') && (symbol <= 'E')) || ((symbol >= 'a') && (symbol <= 'e')) || ((symbol >= '1') && (symbol <= '9')));
}

bool secondCondition(int symbol) // the symbol satisfies the condition [0-9 A-E a-e]
{
    return ((symbol == '0') || firstCondition(symbol));
}

bool isItRegularExpression(char* string)
{
    if (string == NULL)
    {
        return false;
    }
    char currentSymbol = 0;
    int iterator = 0;
    int status = 1;
    while ((string[iterator] != '\n') && (string[iterator] != '\0'))
    {
        currentSymbol = string[iterator];
        switch (status)
        {
            case 1:
                if (!firstCondition(currentSymbol))
                {
                    return false;
                }
                ++status;
                ++iterator;
                break;
            case 2:
                if (secondCondition(currentSymbol))
                {
                    ++iterator;
                    // currentSymbol = string[iterator];
                }
                else if (currentSymbol == '.')
                {
                    ++iterator;
                    ++status;
                }
                else
                {
                    return false;
                }
                break;
            case 3:
                if (secondCondition(currentSymbol))
                {
                    ++iterator;
                    ++status;
                }
                else
                {
                    return false;
                }
                break;
            default: //case 4
                if (secondCondition(currentSymbol))
                {
                    ++iterator;
                    // currentSymbol = string[iterator];
                }
                else if ((currentSymbol != '\n') && (currentSymbol != '\0'))
                {
                    return false;
                }
                break;
        }
    }
    return (status == 4);
}

int main()
{
    printf("Hello! Please give me a string with some characters as input,\n");
    printf("and I will check if this string satisfies the regular expression\n");
    printf("\"[1-9 A-E a-e][0-9 A-E a-e]*.[0-9 A-E a-e]+\"\n");
    printf("Also the entered line must be less than %d symbols or equal to it\n", MAX_SIZE - 1);
    printf("Your string is:");
    char inputLine[MAX_SIZE] = {0};
    fgets(inputLine, MAX_SIZE - 1, stdin);
    if (isItRegularExpression(inputLine))
    {
        printf("Your entered line is a regular expression!\n");
    }
    else
    {
        printf("Your entered line is not a regular expression!\n");
    }
    return 0;
}