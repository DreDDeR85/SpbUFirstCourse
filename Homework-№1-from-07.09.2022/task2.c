#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int division(int firstNum, int secondNum)
{
    int incomQuot = 0;
    while (firstNum >= secondNum)
    {
        firstNum -= secondNum;
        incomQuot += 1;
    }
    return incomQuot;
}

bool remainderExist(int firstNum, int secondNum, int incomQuot)
{
    int remainder = firstNum - secondNum * incomQuot;
    return (remainder != 0);
}

int main(){
    int firstNum, secondNum, answer = 0, signOfResult = 0, dop1 = 0;
    printf("Hello! Please, give me a 2 numbers and I will give you incomplete quotient\n");
    printf("when dividing the first number by the second using only the operations of addition, subtraction and multiplication.\n");
    printf("The first number is:");
    scanf("%d", &firstNum);
    printf("The second number is:");
    scanf("%d", &secondNum);

    if (firstNum * secondNum >= 0)
    {
        signOfResult = 1;
    }
    else
    {
        signOfResult = -1;
    }

    if (secondNum == 0)
    {
        printf("Woops! I can't divide any number by zero!\n");
        printf("Please, try enter your numbers again!");
    }
    else
    {
        answer = signOfResult * division(abs(firstNum), abs(secondNum));
        int remainder = remainderExist(firstNum, secondNum, answer);
        if ((firstNum * secondNum >= 0) && (firstNum < 0))
        {
            dop1 = 1 * remainder;
        }
        else if ((firstNum * secondNum < 0) && (firstNum < 0))
        {
            dop1 = -1 * remainder;
        }
        else
        {
            dop1 = 0;
        }
    }
    answer += dop1;
    printf("Incomplete quotient when dividing %d by %d is: %d", firstNum, secondNum, answer);
}