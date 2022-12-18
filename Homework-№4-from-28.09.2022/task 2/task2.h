#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool checker(int *firstArray, int *secondArray);
// this function will verify for a match two arrays
// and return the result of this verifying

void tests(void);
// runs a test of the program on various
// input data and compares the obtained
// values with the answer

void printArr(int *array, int lenOfArray);
// this function will print on your screen
// an array of integer numbers

void swap(int *firstElement, int *secondElement);
// this function will transfer element x on
// a y element's place and element y on
// a x element's place

int divide(int *array, int left, int right);
// this function will split your array
// into two parts: in first part will be elements,
// which is less than rightmost element in this array,
// and in the second part will be elements, which
// is more or equal to rightmost element

void quickSortRec(int *array, int left, int right);
// this is a recursion function which calls itself two times
// and one times calls a divide function

void quickSort(int *array, int lenOfArray);
// this function is the head of the quick sort algorithm,
// which calls a quick sort recursion function

void mostPopularElement(int *array, int lenOfArray, int *subArr);
// this function will find the most popular element
// in this array and count the number of occurrences