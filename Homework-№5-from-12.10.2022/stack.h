#pragma once

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>

typedef struct stack stack;

/* All error codes for functions:
 * ==============================
 * -1 - Error while allocating memory for the new element!
 * -2 - Stack is a NULL!
 * -3 - Element of the stack is a NULL
 * -4 - Adding element has size NULL
 * -5 - There are no elements in stack, can't pop anything!
 *
 * Error code for programs, which are based on stack:
 * ==================================================
 * -6 - Can't divide any number by zero
 * -7 - stack is not empty
 * */

bool errorDispenser(int codeOfError);
// This function print on your screen an error which
// was happened by some following stack functions


int creationOfTheStack(stack **currentStack, int sizeOfElementsOfStack);
// This command creates a stack with
// the selected amount of memory for elements
/* Error codes: 0, -1, -2, -3 */

int pushingToStack(stack *currentStack, int *addingElement);
// This command pushes the selected element
// onto the top of the stack.
/* Error codes: 0, -1, -2, -3, -4 */

int poppingFromStack(stack *currentStack, int *poppedElement);
// This command removes the element
// at the top of the stack and returns it
/* Error codes: 0, -1, -2, -3, -5 */

int lookingForTheTopElement(stack *currentStack, int *lookedElement);
// This command returns the element at
// the top of the stack without removing it.
/* Error codes: 0, -1, -2, -3, -5 */

int freeMemoryOfTheStack(stack *currentStack);
// This command removes the entire stack
// with all its elements and clears the memory it occupies.
/* Error codes: 0, -2 */

bool isStackNotEmpty(stack *stack);
// This command checks if there are
// any elements on the stack or not
