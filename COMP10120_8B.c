/*
 * COMP10120_8B.c
 * Agbodesi Imoagene 03/04/21
 * A C Program that:
 * Prompts the user to enter the type (integer or float) and number of elements they
 * wish to store in an array
 *
 * Create sufficient memory to store the array
 *
 * Ask the user to enter each of the values they want to store
 *
 * After all elements have been entered and stored in the array, calculate the average
 * and print to the screen
 *
 * Ask the user if there are more elements to be added to the array, if yes, prompt the
 * user to enter the number of additional elements
 *
 * Reallocate sufficient memory to the array to store the new number of elements
 *
 * Ask the user to enter each of the new values they want to store
 *
 * After all the new elements have been entered and stored in the array, calculate the
 * average and print to the screen
 */

#include <stdio.h>
#include <stdlib.h> //Contains memory allocation functions

//Function declarations
void intavg(unsigned int size);
void floatavg(unsigned int size);

int main(void) {
  unsigned int choice, n; //Variables to hold the users decision and the number of values

  //Prompt user decision and assign it to choice
  printf("Enter 0 for an integer array or 1 for a floating point number array: ");
  scanf("%u", &choice);
  while ((choice != 0) && (choice != 1)) { //Check that user enters appropriate values
    printf("Enter a 0 or a 1: ");
    scanf("%u", &choice);
  }

  //Get the number of array elements from the user
  printf("Enter the number of elements in the array: ");
  scanf("%u", &n);

  if (choice == 0) { //Function call
    intavg(n);
  } else {
    floatavg(n);
  }

  return 0;
}

void intavg(unsigned int size) {
  int *ptr = (int *) calloc(size, sizeof(int)), sum = 0; //Declare integer pointer and allocate sufficient memory to it
  float avg; //Variable to hold the average
  int choice; //Holds user decision

  for (size_t i = 0; i < size; i++) { //Get elements from user and addto sum
    printf("Enter element %u: ", i + 1);
    scanf("%d", &ptr[i]);
    sum += ptr[i];
  }

  //Calculate and print average
  avg = (float) sum / size;
  printf("The average of the values enetered is %.2f. \n", avg);

  //Prompt user decision on adding extra elements
  printf("\nTo enter additional elements enter 1, else enter any other number: ");
  scanf("%u", & choice);

  if (choice == 1) {
    unsigned int extra; //Holds number of additional elements

    //Get number of additional elements from user
    printf("Enter the number of additional elements: ");
    scanf("%u", &extra);

    ptr = (int *) realloc(ptr, (size + extra) * sizeof(int)); //Allocate extra memory to pointer

    for (size_t i = 0; i < extra; i++) {//Add new elements to array and sum
      printf("Enter element %u: ", i + 1 + size);
      scanf("%d", &ptr[i + size]);
      sum += ptr[i + size];
    }

    //Calculate and print new average
    avg = (float) sum / (size + extra);
    printf("The new average of the values enetered is %.2f. \n", avg);
  }
}

void floatavg(unsigned int size) {
  float *ptr = (float *) calloc(size, sizeof(float)), sum = 0; //Declare floating point pointer and allocate sufficient memory to it
  float avg;
  int choice;

  for (size_t i = 0; i < size; i++) {
    printf("Enter element %u: ", i + 1);
    scanf("%f", &ptr[i]);
    sum += ptr[i];
  }

  avg = sum / size;
  printf("The average of the values enetered is %.2f. \n", avg);

  printf("\nTo enter additional elements enter 1, else enter any other number: ");
  scanf("%u", & choice);

  if (choice == 1) {
    unsigned int extra;

    printf("Enter the number of additional elements: ");
    scanf("%u", &extra);

    ptr = (float *) realloc(ptr, (size + extra) * sizeof(float));

    for (size_t i = 0; i < extra; i++) {
      printf("Enter element %u: ", i + 1 + size);
      scanf("%f", &ptr[i + size]);
      sum += ptr[i + size];
    }

    avg = sum / (size + extra);
    printf("The new average of the values enetered is %.2f. \n", avg);
  }
}
