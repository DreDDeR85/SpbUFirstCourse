#include <stdio.h>
#define systemOfCounting 10
#define sizeOfArray (3 * systemOfCounting - 2)

void task4(int *luckyTicketsCount)
{
    int arrSumTick[sizeOfArray] = {0};
    int sumsOfDgds = 0;
    for (int firstDgd = 0; firstDgd < systemOfCounting; firstDgd++)
    {
        for (int secondDgd = 0; secondDgd < systemOfCounting; secondDgd++)
        {
            for (int thirdDgd = 0; thirdDgd < systemOfCounting; thirdDgd++)
            {
                sumsOfDgds = firstDgd + secondDgd + thirdDgd;
                arrSumTick[sumsOfDgds]++;
            }
        }
    }
    for (int i = 0; i < sizeOfArray; i++)
    {
        *luckyTicketsCount += arrSumTick[i] * arrSumTick[i];
    }

}

int main() {
    int luckyTicketsCount = 0;
    task4(&luckyTicketsCount);
    printf("Lucky tickets count is: %d", luckyTicketsCount);
}
