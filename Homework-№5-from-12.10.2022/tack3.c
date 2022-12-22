#include "stack.h"
#define MAX_SIZE 101

void stringReset(char* string)
{
    for (int i = 0; i < MAX_SIZE - 1; ++i)
    {
        string[i] = '\0';
    }
}

bool isItAnArithmeticSign(int symbol)
{
    return ((symbol == '+') || (symbol == '-') || (symbol == '/') || (symbol == '*'));
}

bool isADigit(int symbol)
{
    return (('0' <= symbol) && (symbol <= '9'));
}

bool isItInfixForm(char* string)
{
    int cntOfArifSigns = 0, cntOfDigits = 0;
    for (int i = 0; i < MAX_SIZE - 1; ++i)
    {
        if (isItAnArithmeticSign(string[i]))
        {
            ++cntOfArifSigns;
        }
        else if (isADigit(string[i]))
        {
            ++cntOfDigits;
        }
        else if ((string[i] == '\0') || (string[i] == '\n') || (string[i] == ' ') || (string[i] == '(')  || (string[i] == ')'))
        {
            continue;
        }
        else
        {
            return false;
        }
    }
    return (cntOfDigits - cntOfArifSigns == 1) && (cntOfDigits > 0);
}

int worthOfOperator(int operator)
{
    switch (operator)
    {
        case '(':
            return 1;
        case ')':
            return 1;
        case '+':
            return 2;
        case '-':
            return 2;
        case '/':
            return 3;
        case '*':
            return 3;
        default:
            return 0;
    }
}

int main()
{
    printf("Hello! Please, give me an arithmetic\n");
    printf("expression in usual, infix form, and\n");
    printf("then I will give you this expression\n");
    printf("in postfix form!\n");
    printf("You can use digits and these signs:\n");
    printf("+, -, *, /, (, ) and add or don't add\n");
    printf("spaces between them. The length of\n");
    printf("your expression must be less than 100\n");
    printf("characters or equals to it\n");
    printf("Your expression is:");
    char infixForm[MAX_SIZE] = {0};
    fgets(infixForm, MAX_SIZE - 1, stdin);
    while (!isItInfixForm(infixForm))
    {
        printf("Your infix form expression doesn't correct!\n");
        printf("Please, enter expression again:");
        stringReset(infixForm);
        fgets(infixForm, MAX_SIZE - 1, stdin);
    }
    stack* operators = NULL;
    int codeOfError = creationOfTheStack(&operators, sizeof(char));
    bool exitFlag = errorDispenser(codeOfError);
    if (exitFlag)
    {
        freeMemoryOfTheStack(operators);
        return codeOfError;
    }
    char postfixForm[2 * MAX_SIZE] = {0};
    int pointerToPostfixFormSym = 0;
    int topStackOperator = 0, currentOperator = 0, worthOfTopStackOperator = 0, worthOfCurrentOperator = 0;
    for (int i = 0; i < MAX_SIZE; ++i)
    {
        if (isADigit(infixForm[i]) || isItAnArithmeticSign(infixForm[i]))
        {
            if (isADigit(infixForm[i]))
            {
                postfixForm[pointerToPostfixFormSym] = infixForm[i];
                postfixForm[pointerToPostfixFormSym + 1] = ' ';
                pointerToPostfixFormSym += 2;
            }
            else if (isItAnArithmeticSign(infixForm[i]))
            {
                codeOfError = lookingForTheTopElement(operators, &topStackOperator);
                if (codeOfError != -5)
                {
                    exitFlag = errorDispenser(codeOfError);
                    if (exitFlag)
                    {
                        freeMemoryOfTheStack(operators);
                        return codeOfError;
                    }
                }
                currentOperator = (int)infixForm[i];
                worthOfTopStackOperator = worthOfOperator(topStackOperator);
                worthOfCurrentOperator = worthOfOperator(currentOperator);
                if (worthOfTopStackOperator >= worthOfCurrentOperator)
                {
                    codeOfError = poppingFromStack(operators, &topStackOperator);
                    exitFlag = errorDispenser(codeOfError);
                    if (exitFlag)
                    {
                        freeMemoryOfTheStack(operators);
                        return codeOfError;
                    }
                    postfixForm[pointerToPostfixFormSym] = (char)topStackOperator;
                    postfixForm[pointerToPostfixFormSym + 1] = ' ';
                    pointerToPostfixFormSym += 2;
                    codeOfError = pushingToStack(operators, &currentOperator);
                    exitFlag = errorDispenser(codeOfError);
                    if (exitFlag)
                    {
                        freeMemoryOfTheStack(operators);
                        return codeOfError;
                    }
                }
                else
                {
                    codeOfError = pushingToStack(operators, &currentOperator);
                    exitFlag = errorDispenser(codeOfError);
                    if (exitFlag)
                    {
                        freeMemoryOfTheStack(operators);
                        return codeOfError;
                    }
                }
            }
        }
        else if (infixForm[i] == '(')
        {
            currentOperator = (int)infixForm[i];
            codeOfError = pushingToStack(operators, &currentOperator);
            exitFlag = errorDispenser(codeOfError);
            if (exitFlag)
            {
                freeMemoryOfTheStack(operators);
                return codeOfError;
            }
        }
        else if (infixForm[i] == ')')
        {
            codeOfError = lookingForTheTopElement(operators, &topStackOperator);
            while ((codeOfError != -5) && (topStackOperator != '('))
            {
                codeOfError = poppingFromStack(operators, &topStackOperator);
                exitFlag = errorDispenser(codeOfError);
                if (exitFlag)
                {
                    freeMemoryOfTheStack(operators);
                    return codeOfError;
                }
                postfixForm[pointerToPostfixFormSym] = (char)topStackOperator;
                postfixForm[pointerToPostfixFormSym + 1] = ' ';
                pointerToPostfixFormSym += 2;
                codeOfError = lookingForTheTopElement(operators, &topStackOperator);
            }
            if (topStackOperator == '(')
            {
                codeOfError = poppingFromStack(operators, &topStackOperator);
                exitFlag = errorDispenser(codeOfError);
                if (exitFlag)
                {
                    freeMemoryOfTheStack(operators);
                    return codeOfError;
                }
            }
        }
        else if ((infixForm[i] == '\0') || (infixForm[i] == '\n'))
        {
            codeOfError = lookingForTheTopElement(operators, &topStackOperator);
            while (codeOfError != -5)
            {
                codeOfError = poppingFromStack(operators, &topStackOperator);
                exitFlag = errorDispenser(codeOfError);
                if (exitFlag)
                {
                    freeMemoryOfTheStack(operators);
                    return codeOfError;
                }
                postfixForm[pointerToPostfixFormSym] = (char)topStackOperator;
                postfixForm[pointerToPostfixFormSym + 1] = ' ';
                pointerToPostfixFormSym += 2;
                codeOfError = lookingForTheTopElement(operators, &topStackOperator);
            }
            break;
        }
    }
    freeMemoryOfTheStack(operators);
    printf("This is your postfix form:%s", postfixForm);
}