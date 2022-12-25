#include "list.h"

/*
 * The task is to write a list that is an abstract data structure,
 * and built without the use of arrays. To this ADS list, write a
 * program that would expand this list.
 */

int main()
{
    printf("Hello! Please, enter the natural number N - a quantity\n");
    printf("of adding elements in the list, and after this a N integer\n");
    printf("numbers - elements of the list.\n");
    printf("I will reverse your list!\n");
    int quantityOfElements = 0, addingElement = 0;
    printf("Your N is:");
    scanf("%d", &quantityOfElements);
    List *currentList = NULL;
    int errorCode = listCreation(&currentList);
    errorDispenser(errorCode);
    if (errorCode)
    {
        return errorCode;
    }
    printf("Now enter, please, the %d integer elements\n", quantityOfElements);
    for (int i = 0; i < quantityOfElements; ++i)
    {
        errorCode = scanf("%d", &addingElement);
        if (!errorCode)
        {
            printf("You entered not an integer number!\n");
            return -6;
        }
        errorCode = listAdd(currentList, &addingElement);
        errorDispenser(errorCode);
        if (errorCode)
        {
            return errorCode;
        }
    }
    printf("Reversed list is:\n");
    errorCode = listPrint(currentList);
    errorDispenser(errorCode);
    if (errorCode)
    {
        return errorCode;
    }
    List* reversedList = NULL;
    errorCode = listCreation(&reversedList);
    errorDispenser(errorCode);
    if (errorCode)
    {
        return errorCode;
    }
    errorCode = listReverse(currentList, reversedList);
    errorDispenser(errorCode);
    if (errorCode)
    {
        return errorCode;
    }
    printf("Reversed reversed list is:\n");
    errorCode = listPrint(reversedList);
    errorDispenser(errorCode);
    if (errorCode)
    {
        return errorCode;
    }
}