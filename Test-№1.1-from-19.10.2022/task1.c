#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define constSizeStr 10

bool isPalindrome(char *string, int length)
{
    bool soFarFit = true;
    for (int i = 0; i < length / 2; ++i)
    {
        if (string[i] != string[length - 1 - i])
        {
            soFarFit = false;
            break;
        }
    }
    return soFarFit;
}

void tests(int *resultOfTest)
{
    char string1[constSizeStr] = "Ehehehehhe";
    *resultOfTest = *resultOfTest * (false == isPalindrome(string1, constSizeStr));

    char string2[constSizeStr] = "AAAAAAAAAA";
    *resultOfTest = *resultOfTest * (true == isPalindrome(string2, constSizeStr));

    char string3[0] = "";
    *resultOfTest = *resultOfTest * (true == isPalindrome(string3, 0));

    char string4[constSizeStr] = "HobbiibboH";
    *resultOfTest = *resultOfTest * (true == isPalindrome(string4, constSizeStr));

    char string5[constSizeStr + 1] = "HobbitibboH";
    *resultOfTest = *resultOfTest * (true == isPalindrome(string5, constSizeStr + 1));
}

int main()
{
    int length = 0, resultOfTest = 1;
    tests(&resultOfTest);
    if (resultOfTest == 0)
    {
        printf("Tests failed! Code needs fixing!\n");
    }
    else
    {
        printf("Tests passed! The code works correctly!\n");
    }
    printf("Hello! Please, give me a string, which not\n");
    printf("contains any spaces, and I will check if this\n");
    printf("string is a palindrome or not.\n");
    printf("First, you must give me a non-negative length of\n");
    printf("string, and only after this you give a this string.\n");
    printf("The length of string:");
    scanf("%d", &length);
    if (length == 0)
    {
        printf("This string is a palindrome!");
    }
    else
    {
        char *string = calloc(length, sizeof(char));
        printf("The string:");
        scanf("%s", string);
        bool answer = isPalindrome(string, length);
        if (answer)
        {
            printf("This string is a palindrome!");
        }
        else
        {
            printf("This string is not a palindrome.");
        }
    }
}