#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// Task 7
void sieve(int *arrayOfPrimeNumbers, int number)
{
    for (int i = 0; i <= number; ++i)
    {
        arrayOfPrimeNumbers[i] = true;
    }
    arrayOfPrimeNumbers[0] = false;
    arrayOfPrimeNumbers[1] = false;
    for (int i = 2; i <= number; ++i)
    {
        if (arrayOfPrimeNumbers[i]) {
            for (int j = i * i; j <= number; j += i)
            {
                arrayOfPrimeNumbers[j] = false;
            }
        }
    }
}

int main()
{
    printf("Please, give me a natural number.\n");
    printf("I will print on your screen all prime numbers,\n");
    printf("which do not exceed entered number.\n");
    printf("The number is:");
    int *arrayOfPrimeNumbers;
    int number;
    scanf("%d", &number);
    arrayOfPrimeNumbers = (int*)malloc((number + 1) * sizeof(int));
    sieve(arrayOfPrimeNumbers, number);
    if (number < 2)
    {
        printf("Sorry, but your number has no primes less than it \n");
        printf("You always have an option to give me a number again!");
    }
    else
    {
        printf("All prime numbers, which do not exceed %d is:\n", number);
        for (int i = 0; i <= number; ++i) {
            if (arrayOfPrimeNumbers[i]) {
                printf("%d ", i);
            }
        }
    }
}

