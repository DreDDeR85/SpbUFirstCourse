#include <stdio.h>

double slowPow(double number, int power)
{
    if (power == 0)
    {
        return 1;
    }
    else
    {
        return slowPow(number, power - 1) * number;
    }
}

double fastPow(double number, int power)
{
    if (power == 0)
    {
        return 1;
    }
    if (power % 2 == 1)
    {
        return fastPow(number, (power - 1) / 2) * fastPow(number, (power - 1) / 2) * number;
    }
    else
    {
        return fastPow(number, power / 2) * fastPow(number, power / 2);
    }
}

int main()
{
    double number = 0;
    int power = 0;
    printf("Hello! Please, give me a two number and i will raise the first number to\n");
    printf("the power of the second with a two different methods:\n");
    printf("using degree properties (first method) and without using (second method)!\n");
    printf("The first number is:");
    scanf("%lf", &number);
    printf("The second number must be integer! This number is:");
    scanf("%d", &power);
    if ((number == 0) && (power == 0))
    {
        printf("This is an uncertainty of the form 0 divided by 0!\n");
        printf("Please, try again!");
    }
    else if (power < 0)
    {
        printf("%lf in the power of %d\n", number, power);
        printf("with the first method is %lf\n", (1/(fastPow(number, (-1) * power))));
        printf("%lf in the power of %d\n", number, power);
        printf("with the second method is %lf", (1/(slowPow(number, (-1) * power))));    }
    else
    {
        printf("%lf in the power of %d\n", number, power);
        printf("with the first method is %lf\n", fastPow(number, power));
        printf("%lf in the power of %d\n", number, power);
        printf("with the second method is %lf", (slowPow(number, power)));
    }
}