#include <stdio.h>

float task1(float num)
{
    //Formula: x^4 + x^3 + x^2 + x + 1 = x^2(x^2 + x + 1) + x + 1
    float sqNum = num * num;
    float answer = sqNum * (sqNum + num + 1) + num + 1;
    return answer;
}

int main()
{
    float num = 0;
    printf("Hi! Please, give me a number, and i will calculate the value of the expression\n");
    printf("x^4 + x^3 + x^2 + x + 1, where x is your number, with 2 multiplications!\n");
    printf("Your number is:");
    scanf("%f", &num);
    printf("I calculated the value of the formula! The answer is %f", task1(num));
}