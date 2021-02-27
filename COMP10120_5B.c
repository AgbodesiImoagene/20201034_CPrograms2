/*
 * COMP10120_5B.c
 * Agbodesi Imoagene 25/02/21
 * A C program to demonstrate pointers to functions in a menu-driven program.
 * The program contains four functions: reverseArray, randomiseArray, printArray and sumArray.
 */

#include <stdio.h>
#include <stdlib.h> //Contains rand and srand functions
#include <time.h> //Contains time function

//Function prototypes and array initialisation
void reverseArray(int arraySize, int a[]);
void randomiseArray(int arraySize, int a[]);
void printArray(int arraySize, int a[]);
void sumArray(int arraySize, int a[]);
int myArray[] = {2,4,6,8,10,12,14,16,18,20};

int main(int argc, char const *argv[]) {
  int choice; //Holds user choice
  int size = sizeof(myArray) / sizeof(myArray[0]); //Size of array
  void (*funct[4])(int, int *) = {reverseArray, randomiseArray, printArray, sumArray}; //Pointers to functions
  srand(time(NULL)); //Seeds rand function

  //Prompt user for input
  puts("Enter 1 to reverse the array. ");
  puts("Enter 2 to randomise the array. ");
  puts("Enter 3 to print the array. ");
  puts("Enter 4 to print the sum of the array. ");
  scanf("%d", &choice); //Input

  while (choice > 4 || choice < 1) { //Check for valid input
    puts("Enter a number between 1 and 4. ");
    scanf("%d", &choice);
  }

  while (choice <= 4 && choice >= 1) { //Functions can be called multiple times
    (*funct[choice - 1])(size, myArray); //Function call
    puts("Enter a number between 1 and 4 to use a function, enter another number to exit. ");
    scanf("%d", &choice);
  }
  return 0;
}

void reverseArray(int arraySize, int a[]) {
  //Swap values from beginning of array to midpoint with values from end of array to midpoint
  for (size_t i = 0; i < arraySize / 2; i++) {
    a[i] += a[arraySize - 1 - i];
    a[arraySize - 1 - i] = a[i] - a[arraySize - 1 - i];
    a[i] = a[i] - a[arraySize - 1 - i];
  }
}

void randomiseArray(int arraySize, int a[]) {
  int b[arraySize]; //Temporary array
  int tempSize = arraySize; //Holds size of temporary array

  for (size_t i = 0; i < arraySize; i++) { //Initialise b with a
    b[i] = a[i];
  }

  for (size_t i = 0; i < arraySize; i++) { //randomise array a
    int j = rand() % tempSize; //Pick a random value in array b
    a[i] = b[j]; //Assign the random value to a[i];
    tempSize--; //Reduce the size of b used
    for (size_t k = j; k < tempSize; k++) { //Shift values of b back to avoid repetiiton, effectively deleting b[j]
      b[k] = b[k + 1];
    }
  }
}

void printArray(int arraySize, int a[]) {
  printf("Your array is {");
  for (size_t i = 0; i < arraySize - 1; i++) {
    printf("%d, ", a[i]);
  }
  printf("%d}. \n", a[arraySize - 1]);
}

void sumArray(int arraySize, int a[]) {
  int sum = 0; //Holds sum of values in a
  for (size_t i = 0; i < arraySize; i++) {
    sum += a[i];
  }
  printf("The sum of all the numbers in the array is %d. \n", sum);
}
