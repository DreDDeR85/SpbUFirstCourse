#include "stack.h"

typedef struct elementOfTheStack
{
    void* valueOfTheElement;
    struct elementOfTheStack* nextElement;
} elementOfTheStack;

typedef struct stack
{
    elementOfTheStack* apex;
    int sizeOfStackElement;
} stack;

bool errorDispenser(int codeOfError)
{
    switch (codeOfError)
    {
        case 0:
            return false;
        case -1:
            printf("Error while allocating memory for the new element!\n");
            return true;
        case -2:
            printf("Stack is a NULL!\n");
            return true;
        case -3:
            printf("Element of the stack is a NULL");
            return true;
        case -4:
            printf("Adding element has size NULL");
            return true;
        default: // case -5
            printf("There are no elements in stack, can't pop anything!");
            return true;
    }
}

int creationOfTheStack(stack** currentStack, int sizeOfStackElement)
{
    if (sizeOfStackElement == 0)
    {
        return -3;
    }
    if (currentStack == NULL)
    {
        return -2;
    }
    *currentStack = calloc(1, sizeof(stack));
    if (*currentStack == NULL)
    {
        return -1;
    }
    (*currentStack)->sizeOfStackElement = sizeOfStackElement;
    return 0;
}

int pushingToStack(stack* currentStack, int* addingElement)
{
    if (addingElement == NULL)
    {
        return -4;
    }
    if (currentStack == NULL)
    {
        return -2;
    }
    if (currentStack->sizeOfStackElement == 0)
    {
        return -3;
    }
    elementOfTheStack* newStackElement = calloc(1, sizeof(elementOfTheStack));
    if (newStackElement == NULL)
    {
        return -1;
    }
    void* copyOfElement = calloc(1, currentStack->sizeOfStackElement);
    if (copyOfElement == NULL)
    {
        return -1;
    }
    memcpy(copyOfElement, addingElement, currentStack->sizeOfStackElement);
    newStackElement->nextElement = currentStack->apex;
    newStackElement->valueOfTheElement = copyOfElement;
    currentStack->apex = newStackElement;
    return 0;
}

int poppingFromStack(stack* currentStack, int* poppedElement)
{
    if (currentStack == NULL)
    {
        return -2;
    }
    if (currentStack->sizeOfStackElement == 0)
    {
        return -3;
    }
    if (currentStack->apex == NULL)
    {
        return -5;
    }
    if (poppedElement == NULL)
    {
        return -1;
    }
    elementOfTheStack* apexElement = currentStack->apex;
    memcpy(poppedElement, apexElement->valueOfTheElement, currentStack->sizeOfStackElement);
    currentStack->apex = apexElement->nextElement;
    free(apexElement->valueOfTheElement);
    free(apexElement);
    return 0;
}

int lookingForTheTopElement(stack* currentStack, int* lookedElement)
{
    if (currentStack == NULL)
    {
        return -2;
    }
    if (currentStack->sizeOfStackElement == 0)
    {
        return -3;
    }
    if (currentStack->apex == NULL)
    {
        return -5;
    }
    if (lookedElement == NULL)
    {
        return -1;
    }
    memcpy(lookedElement, currentStack->apex->valueOfTheElement, currentStack->sizeOfStackElement);
    return 0;
}

int freeMemoryOfTheStack(stack* currentStack)
{
    if (currentStack == NULL)
    {
        return -2;
    }
    elementOfTheStack* apexElement = currentStack->apex;
    elementOfTheStack* nextElement = NULL;
    while (apexElement != NULL)
    {
        nextElement = apexElement->nextElement;
        free(apexElement->valueOfTheElement);
        free(apexElement);
        apexElement = nextElement;
    }
    currentStack->apex = NULL;
    return 0;
}

bool isStackNotEmpty(stack *currentStack)
{
    return ((currentStack != NULL) && (currentStack->apex != NULL));
}
