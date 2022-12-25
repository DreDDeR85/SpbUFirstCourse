#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdbool.h>

void errorDispenser(int errorCode);
// this function print on your screen the description of the error

typedef struct List List;
// this struct contains a pointer to the top of the List

int listCreation(List** currentList);
// this function makes an empty List

int listAdd(List* currentList, int* addingElement);
// this function inserts element to the List

int listPop(List* currentList, int* poppedElement);
// this function removes front element from the List

int listFree(List* currentList);
// this function erases the List

int listReverse(List* currentList, List* reversedList);
// this function inverts the List

int listPrint(List *currentList);
// this function prints all elements in the list