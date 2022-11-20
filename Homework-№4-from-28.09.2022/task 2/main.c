#include "task2.h"

int main()
{
    tests();
    char fileName[100] = {"\0"};
    printf("Hello! Please, enter the filename with an extension on your computer\n");
    printf("in this folder, which contains a natural number N and after N integer numbers\n");
    printf("I will find most popular element in this array faster, than O(n^2)!\n");
    printf("Your filename =");
    scanf("%s", fileName);
    FILE *file = fopen(fileName, "r");
    int number = 0;
    int subArray[] = {0, 0};
    fscanf(file, "%d", &number);
    int *array = calloc(number, sizeof(int));
    if (array == NULL)
    {
        printf("Error while allocating memory for the array!");
        return -1;
    }
    for (int i = 0; i < number; ++i)
    {
        fscanf(file, "%d", &array[i]);
    }
    mostPopularElement(array, number, subArray);
    printf("The most popular element in entered array is %d.\n", subArray[0]);
    printf("In this array this element contains by %d times", subArray[1]);
    free(array);
}