#include <stdio.h>

unsigned long recursionFibCount(unsigned long number)
{
    if (number <= 0)
    {
        return 0;
    }
    if (number <= 2)
    {
        return 1;
    }
    return (recursionFibCount(number - 1) + recursionFibCount(number - 2));
}

unsigned long iterateFibCount(unsigned long number)
{
    unsigned long preprevious = 0, previous = 0, now = 1;
    for (int i = 0; i < number - 1; ++i)
    {
        preprevious = previous;
        previous = now;
        now = preprevious + previous;
    }
    return now;
}

int main() {
    unsigned long number = 0;
    printf("Hello! Please, give me an natural number which means a number in a Fibonacci series,\n");
    printf("and I will count it for you with a 2 different ways: with recursion and with iteration!\n");
    printf("Your number is:");
    scanf("%lu", &number);
    if (number <= 0)
    {
        printf("Woops! I think you gave me not a natural number although I asked for it :))");
        printf("Please, try again!");
    }
    else
    {
        printf("The iterate counting %luth number in Fibonacci row is: %lu.\n", number, iterateFibCount(number));
        printf("The recursion counting %luth number in Fibonacci row is: %lu.", number, recursionFibCount(number));
    }
}
