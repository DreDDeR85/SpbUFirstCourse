#include <stdio.h>
#define maxSize 1000

void creation(char *array, int lenOfArray)
{
    for (int i = 0; i < lenOfArray; ++i)
    {
        array[i] = ' ';
    }
}

int lenOfString(char *string, int lenOfString)
{
    int trueLen = 0;
    for (int i = 0; i < lenOfString; ++i)
    {
        if (string[i] != ' ')
        {
            trueLen++;
        }
    }
    return trueLen;
}

int task6(char *firstStr, char *secondStr)
{

    int isItSubstring = 1, answer = 0;
    int lenFirstStr = lenOfString(firstStr, maxSize), lenSecondStr = lenOfString(secondStr, maxSize);
    if (lenFirstStr < lenSecondStr)
    {
        return -1;
    }
    else {
        for (int symbolOfFirstStr = 0; symbolOfFirstStr < lenFirstStr - lenSecondStr + 1; symbolOfFirstStr++)
        {
            isItSubstring = 1;
            for (int symbolOfSecondStr = 0; symbolOfSecondStr < lenSecondStr; symbolOfSecondStr++)
            {
                if (firstStr[symbolOfFirstStr + symbolOfSecondStr] != secondStr[symbolOfSecondStr])
                {
                    isItSubstring = 0;
                    break;
                }
            }
            answer += isItSubstring;
        }
        return answer;
    }
}

int main()
{
    char firstStr[maxSize], secondStr[maxSize];
    int answer = 0;
    creation(firstStr, maxSize);
    creation(secondStr, maxSize);
    printf("Hello! I can count how many times the second string enter in the first string, which means\n");
    printf("how many times the second string is a substruct of the first string.\n");
    printf("Please, enter the first and second strings, which size is lower than 1000, each on a new line,\n");
    printf("Important notice: strings can not contains the space symbols like ' '\n");
    printf("The first string is:");
    scanf("%s", firstStr);
    printf("The second string is:");
    scanf("%s", secondStr);
    answer = task6(firstStr, secondStr);
    if (answer == -1)
    {
        printf("Woops! The length of the first line is less than the length of the second! Answer is 0.");
    }
    else if (answer == 0)
    {
        printf("The second string '%s' never entered in the first string '%s'!", secondStr, firstStr);
    }
    else
    {
        printf("The second string '%s' entered in the first string '%s' for %d times", secondStr, firstStr, answer);
    }
}