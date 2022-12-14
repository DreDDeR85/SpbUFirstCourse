#include <stdio.h>
#include <stdbool.h>

void reset(bool *existCheck)
{
    for (int i = 0; i < 3; ++i)
    {
        existCheck[i] = false;
    }
}

void resetTemp(int *array)
{
    for (int i = 0; i < 8; ++i)
    {
        array[i] = 0;
    }
}

int fastPower(int a, int b) // a^b
{
    if (b == 0)
    {
        return 1;
    } else if (b % 2)
    {
        return fastPower(a, b / 2) * fastPower(a, b / 2) * a;
    } else
    {
        return fastPower(a, b / 2) * fastPower(a, b / 2);
    }
}

bool isFileTabulationCorrect(FILE *file)
{
    if (file == NULL)
    {
        return false;
    }
    bool existCheck[3] = {false, false, false};
    // 0 - itemNameExist = false;
    // 1 - itemCntExist = false;
    // 2 - itemPriceExist = false;
    char c = fgetc(file);
    int pointer = 0;
    while (c != EOF)
    {
        if ((c != '\t') && (c != '\n'))
        {
            existCheck[pointer] = true;
        } else if (c == '\t')
        {
            ++pointer;
            if (pointer >= 3)
            {
                return false;
            }
        } else
        {
            pointer = 0;
            if (!(existCheck[0] && existCheck[1] && existCheck[2]))
            {
                return false;
            }
            reset(existCheck);
        }
        c = fgetc(file);
    }
    if (!(existCheck[0] && existCheck[1] && existCheck[2]))
    {
        return false;
    }
    return true;
}

int toInt(int *array)
{
    int answer = 0;
    for (int i = 0; i < 8; ++i)
    {
        answer += array[i] * fastPower(10, i);
    }
    return answer;
}

long long orderCounter(FILE *file)
{
    long long preResult = 0;
    long long result = 0;
    int temp[8] = {0};
    int counterOfItem = 0;
    int priceOfItem = 0;
    char c = fgetc(file);
    int pointer = 0;
    while (c != EOF)
    {
        if (pointer == 0)
        {
            while (c != '\t')
            {
                c = fgetc(file);
            }
        } else if (pointer == 1)
        {
            for (int i = 0; i < 8; ++i)
            {
                if (c == '\t' || c == '\n')
                {
                    break;
                }
                temp[i] = (c - '0');
                c = fgetc(file);
            }
            if (c != '\t')
            {
                c = fgetc(file);
                if (c != '\t')
                {
                    return -1;
                }
            }
            counterOfItem = toInt(temp);
            resetTemp(temp);
        } else if (pointer == 2)
        {
            for (int i = 0; i < 8; ++i)
            {
                if (c == '\t' || c == '\n' || c == EOF)
                {
                    break;
                }
                temp[i] = (c - '0');
                c = fgetc(file);
            }
            if (!(c == '\n' || c == EOF))
            {
                c = fgetc(file);
                if (!(c == '\n' || c == EOF))
                {
                    return -1;
                }
            }
            priceOfItem = toInt(temp);
            resetTemp(temp);
        }
        if (c == '\t')
        {
            ++pointer;
            c = fgetc(file);
        } else if (c == '\n' || c == EOF)
        {
            pointer = 0;
            preResult = priceOfItem * counterOfItem;
            result += preResult;
            priceOfItem = 0;
            counterOfItem = 0;
            preResult = 0;
            c = fgetc(file);
        }
    }
    return result;
}

int main()
{
    printf("Hello! I will count the price for all your\n");
    printf("items in a file \"order.txt\". If your file\n");
    printf("isn't correct, I will print message on your screen.\n\n");
    FILE *fileTesting = fopen("order.txt", "r");
    if (fileTesting == NULL)
    {
        printf("This file doesn't exist!\n");
    }
    if (!isFileTabulationCorrect(fileTesting))
    {
        printf("Your file is not correct!\n");
        printf("Please, repair file's tabulations and line breaks!\n");
        fclose(fileTesting);
        return -1;
    }
    fclose(fileTesting);
    FILE *file = fopen("order.txt", "r");
    long long answer = orderCounter(file);
    if (answer == -1)
    {
        printf("Your file is not correct!\n");
        printf("Please, repair file's item's price or counters!\n");
        fclose(file);
        return -1;
    } else
    {
        printf("Program successfully ended!\n");
        printf("The total cost of the order is: %lld\n", answer);
        fclose(file);
        return 0;
    }
}