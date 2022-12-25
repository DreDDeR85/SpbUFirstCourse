#include "List.h"

typedef struct listElement
{
    int* value;
    struct listElement* prev;
} listElement;

typedef struct List
{
    listElement* apex;
} List;

int listCreation(List** currentList)
{
    if (currentList == NULL)
    {
        return -2;
    }
    *currentList = calloc(1, sizeof(List));
    if (*currentList == NULL)
    {
        return -1;
    }
    return 0;
}

int listAdd(List* currentList, int* addingElement)
{
    if (addingElement == NULL)
    {
        return -3;
    }
    if (currentList == NULL)
    {
        return -2;
    }
    listElement* newListElement = calloc(1, sizeof(listElement));
    if (newListElement == NULL)
    {
        return -1;
    }
    int* copyElement = calloc(1, sizeof(int));
    if (copyElement == NULL)
    {
        return -1;
    }
    memcpy(copyElement, addingElement, sizeof(int));
    newListElement->value = copyElement;
    newListElement->prev = currentList->apex;
    currentList->apex = newListElement;
    return 0;
}

int listPop(List* currentList, int* poppedElement)
{
    if (currentList == NULL)
    {
        return -2;
    }
    if (currentList->apex == NULL)
    {
        return -4;
    }
    if (poppedElement == NULL)
    {
        return -5;
    }
    listElement* apexElement = currentList->apex;
    memcpy(poppedElement, apexElement->value, sizeof(int));
    currentList->apex = apexElement->prev;
    free(apexElement->value);
    free(apexElement);
    return 0;
}

int listFree(List* currentList)
{
    if (currentList == NULL)
    {
        return -2;
    }
    listElement* apexElement = currentList->apex;
    listElement* prevElement = NULL;
    while (apexElement != NULL)
    {
        prevElement = apexElement->prev;
        free(apexElement->value);
        free(apexElement);
        apexElement = prevElement;
    }
    currentList->apex = NULL;
    return 0;
}

bool isListIsNotEmpty(List *currentList)
{
    return (currentList->apex != NULL);
}

int listReverse(List* currentList, List* reversedList)
{
    if (currentList == NULL)
    {
        return -2;
    }
    if (reversedList == NULL)
    {
        return -2;
    }
    int errorCode = 0;
    int valueOfTransferElement = 0;
    while (isListIsNotEmpty(currentList))
    {
        errorCode = listPop(currentList, &valueOfTransferElement);
        if (errorCode)
        {
            return errorCode;
        }
        errorCode = listAdd(reversedList, &valueOfTransferElement);
        if (errorCode)
        {
            return errorCode;
        }
    }
    return 0;
}

int listPrint(List *currentList)
{
    if (currentList == NULL)
    {
        return -2;
    }
    listElement* thisElement = currentList->apex;
    while (thisElement != NULL)
    {
        printf("%d ", *thisElement->value);
        thisElement = thisElement->prev;
    }
    printf("\n");
    return 0;
}

void errorDispenser(int errorCode)
{
    switch (errorCode)
    {
        case -1:
            printf("Allocating memory suffered a setback!\n");
            break;
        case -2:
            printf("Given List is a NULL!\n");
            break;
        case -3:
            printf("Adding element is a NULL!\n");
            break;
        case -4:
            printf("Apex element is a NULL!\n");
            break;
        case -5:
            printf("Popped element is a NULL!\n");
            break;
        default:
            break;
        // another case -6:s scanf suffered a setback
        // when trying to scan an integer number
    }
}