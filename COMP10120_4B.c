/*
 * COMP10120_4B.c
 * Agbodesi Imoagene 17/02/21
 * A C program to copy the contents a one-dimensional character array into
 * another one-dimensional character array. The program includes two functions in
 * your program, one which demonstrates the functionality using pointer notation
 * and one which demonstrates the functionality using array indexing.
 */

#include <stdio.h>

void copyArrayIndexWay(char * const newArray1, const char * const originalArray1);
void copyPointerWay(char *newArray2, const char *originalArray2);

int main(void) {
  //Variable declarations and initialisations
  char originalArray1[] = "COMP10120";
  char originalArray2[] = "COMP10110";
  char newArray1[10];
  char newArray2[10];

  printf("originalArray1 contains the string \"%s\" \n", originalArray1);
  printf("originalArray2 contains the string \"%s\" \n\n", originalArray2);

  //Function calls
  copyArrayIndexWay(newArray1, originalArray1);
  copyPointerWay(newArray2, originalArray2);

  //Output
  printf("newArray1 now contains the string \"%s\" \n", newArray1);
  printf("newArray2 now contains the string \"%s\" \n", newArray2);
  return 0;
}

void copyArrayIndexWay(char * const newArray1, const char * const originalArray1) {
  size_t i = 0;

  printf("Locations in both arrays in the copyArrayIndexWay function are accessed through array indexing. \n");

  while (originalArray1[i] != '\0') {
    newArray1[i] = originalArray1[i];
    i++;
  }

  printf("Characters from originalArray1 are assigned to their corresponding positions in newArray1 \nand the index is incremented until the null terminator is encounterd. \n");

  newArray1[i] = '\0'; //Add null terminator

  printf("The null terminator is added to the end of newArray1. \n\n");
  return;
}

void copyPointerWay(char *newArray2, const char *originalArray2) {
  size_t i = 0; //Allows iteration through loop without changing the pointer values

  printf("Locations in both arrays in the copyPointerWay function are accessed by offsetting the pointers. \n");

  while (*(originalArray2 + i) != '\0') {
    *(newArray2 + i) = *(originalArray2 + i);
    i++;
  }

  printf("Characters from originalArray2 are assigned to their corresponding positions in newArray2 \nand the offset is incremented until the null terminator is encounterd. \n");

  *(newArray2 + i) = '\0'; //Add null terminator

  printf("The null terminator is added to the end of newArray2. \n\n");
  return;
}
