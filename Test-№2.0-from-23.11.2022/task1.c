#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define dateSize 10

bool isItANumber(char *queue, int iterator)
{
    char numbers[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    bool answer = false;
    for (int i = 0; i < dateSize; ++i)
    {
        if (queue[iterator] == numbers[i])
        {
            answer = true;
            break;
        }
    }
    return answer;
}

bool isItADot(char *queue, int iterator)
{
    if (queue[iterator] == '.')
    {
        return true;
    }
    return false;
}

bool isItADate(char *queue, int counter)
{
    int pointer = counter % 10;
    bool answer = true;
    int comparesLostCnt = 10;
    //date has this format: n n . n n . n n n n
    //.mask for i for help: 0 1 2 3 4 5 6 7 8 9
    char dot = '.';
    for (int i = pointer; i < dateSize; ++i)
    {
        switch (i)
        {
            case 0:
                answer *= isItANumber(queue, i);
                break;
            case 1:
                answer *= isItANumber(queue, i);
                break;
            case 2:
                answer *= isItADot(queue, i);
                break;
            case 3:
                answer *= isItANumber(queue, i);
                break;
            case 4:
                answer *= isItANumber(queue, i);
                break;
            case 5:
                answer *= isItADot(queue, i);
                break;
            case 6:
                answer *= isItANumber(queue, i);
                break;
            case 7:
                answer *= isItANumber(queue, i);
                break;
            case 8:
                answer *= isItANumber(queue, i);
                break;
            case 9:
                answer *= isItANumber(queue, i);
                break;
            default:
                answer = false;
        }
        --comparesLostCnt;
        if (answer == false)
        {
            return false;
        }
    }
    for (int i = 0; i < comparesLostCnt; ++i)
    {
        switch (i)
        {
            case 0:
                answer *= isItANumber(queue, i);
                break;
            case 1:
                answer *= isItANumber(queue, i);
                break;
            case 2:
                answer *= isItADot(queue, i);
                break;
            case 3:
                answer *= isItANumber(queue, i);
                break;
            case 4:
                answer *= isItANumber(queue, i);
                break;
            case 5:
                answer *= isItADot(queue, i);
                break;
            case 6:
                answer *= isItANumber(queue, i);
                break;
            case 7:
                answer *= isItANumber(queue, i);
                break;
            case 8:
                answer *= isItANumber(queue, i);
                break;
            case 9:
                answer *= isItANumber(queue, i);
                break;
            default:
                answer = false;
        }
        if (answer == false)
        {
            return false;
        }
    }
    return true;
}

int fromCharToInt(char number)
{
    char numbers[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    for (int i = 0; i < 10; ++i)
    {
        if (number == numbers[i])
        {
            return i;
        }
    }
    return -1;
}

void helpDateInit(char *helpDate, char *date)
{
    //date has this format: n n . n n . n n n n
    //.mask for i for help: 0 1 2 3 4 5 6 7 8 9
    helpDate[0] = date[6];
    helpDate[1] = date[7];
    helpDate[2] = date[8];
    helpDate[3] = date[9];
    helpDate[4] = date[3];
    helpDate[5] = date[4];
    helpDate[6] = date[0];
    helpDate[7] = date[1];
}

bool isItABestDate(char *firstDate, char *secondDate)
{
    // The question is: Is it a firstDate are greater than secondDate?
    // return 1 = yes
    // return 0 = dates are equal
    // return -1 = no
    //date has this format: n n . n n . n n n n
    //.mask for i for help: 0 1 2 3 4 5 6 7 8 9
    char helpFirstDate[dateSize];
    helpDateInit(helpFirstDate, firstDate);
    char helpSecondDate[dateSize];
    helpDateInit(helpSecondDate, secondDate);
    int endOfIter = dateSize - 2;
    for (int i = 0; i < endOfIter; ++i)
    {
        if (fromCharToInt(helpFirstDate[i]) > fromCharToInt(helpSecondDate[i]))
        {
            return true;
        }
        else if (fromCharToInt(helpFirstDate[i]) < fromCharToInt(helpSecondDate[i]))
        {
            return false;
        }
    }
    return false;
}

void copyDate(char *from, char *to)
{
    for (int i = 0; i < dateSize; ++i)
    {
        to[i] = from[i];
    }
}

void task1(FILE *file, char *answer, int *errorCode)
{
    bool flag = true;
    char queue[dateSize] = {' '};
    int counter = 0;
    char now = fgetc(file);
    if (now == EOF)
    {
        *errorCode = -1;
    }
    queue[counter] = now;
    ++counter;
    char bestDate[dateSize] = "01.01.0001";
    while (now != EOF)
    {
        now = fgetc(file);
        queue[counter % 10] = now;
        ++counter;
        if (isItADate(queue, counter))
        {
            if (flag)
            {
                copyDate(queue, bestDate);
                flag = false;
            }
            else
            {
                if (isItABestDate(queue, bestDate))
                {
                    copyDate(queue, bestDate);
                }
            }
            copyDate("01.01.0001", queue);
        }
    }
    copyDate(bestDate, answer);
}

void printDate(char *date)
{
    for (int i = 0; i < dateSize; ++i)
    {
        printf("%c", date[i]);
    }
    printf("\n");
}

int main() {
    FILE *file = fopen("test.txt", "r");
    int errorCode = 0;
    char answer[dateSize] = "xx.xx.xxxx";
    task1(file, answer, &errorCode);
    switch (errorCode)
    {
        case -1:
            printf("Your opened file is empty!\n");
            break;
        default:
            printf("All correct!\n");
            break;
    }
    printDate(answer);
}
