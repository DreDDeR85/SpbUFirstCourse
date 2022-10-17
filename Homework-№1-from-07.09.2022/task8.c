#include <stdio.h>

void task8(int *counterZero, int *counterOfNumbers, int *nowElement)
{
    while (*nowElement != -1)
    {
        if (*nowElement == 0)
        {
            *counterZero += 1;
        }
        *counterOfNumbers += 1;
        scanf("%d", &*nowElement);
    }
}

int main()
{
    printf("Hello! Please, give me an array of integer numbers and I will count the number of zeros there!\n");
    printf("If you want to stop typing, you must give me a '-1' without quotes. Let's type!\n");
    int counterZero = 0, counterOfNumbers = 0, nowElement = 1;
    scanf("%d", &nowElement);
    task8(&counterZero, &counterOfNumbers, &nowElement);
    if (counterOfNumbers == 0)
    {
        printf("I didn't count any zero in this empty array!");
    }
    else if (counterZero > 1)
    {
        printf("I counted %d zeros in this array of %d numbers", counterZero, counterOfNumbers);
    }
    else if (counterZero == 1)
    {
        printf("I counted only one zero in this array of %d numbers", counterOfNumbers);
    }
    else
    {
        printf("I didn't count no one zero in this array of %d numbers", counterOfNumbers);
    }
}