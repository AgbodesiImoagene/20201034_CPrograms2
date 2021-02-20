/*
 * COMP10120_3B.c
 * Agbodesi Imoagene 11/02/21
 * A C program which creates 2 two-dimensional integer arrays: arrayA and arrayB.
 * The size of the arrays are equal and specified by user input (maximum 20 rows and 20 columns).
 * Each array is filled with random numbers between 100 and 1500 with no duplicate numbers in a single array.
 * The program creates new arrays for each of the following situations:
 * • An array containing the product of corresponding cells in arrayA and arrayB
 * • An array containing the sum of corresponding cells in arrayA and arrayB
 * • An array containing the sum of corresponding rows in arrayA and arrayB
 * • An array containing the sum of corresponding columns in arrayA and arrayB
 * The program also
 * • Prints the contents of all arrays.
 * • Print the number of total number of numbers that occur in both arrays (if any)
 * • Print the word Wow if the same number appears in the same cell in the two arrays
 */

#include <stdio.h>
#include <stdlib.h> //For the rand and srand functions
#include <time.h> //For the time function

int main(void) {
  srand(time(NULL)); //Seeds the rand function only once

  //Variables to hold the number of rows and columns of the arrays respectively
  int x, y;

  //User input
  printf("Enter the number of rows in the arrays: ");
  scanf("%d", &x);
  while ((x > 20) || (x <= 0)) { //Check to make sure x is positive and not greater thasn 20
    printf("Enter a positive number not greater than 20. \n");
    scanf("%d", &x);
  }
  printf("Enter the number of columns in the arrays: ");
  scanf("%d", &y);
  while ((y > 20) || (y <= 0)) {
    printf("Enter a positive number not greater than 20. \n");
    scanf("%d", &y);
  }

  int arrayA[x][y], arrayB[x][y];
  //Temp holds the variables before they are added to the arrays
  //Duplicates is a flag for identical values
  int temp, duplicates;

  for (size_t i = 0; i < x; i++) {
    for (size_t j = 0; j < y; j++) {
      int z = (i * y) + j; //Allows one for loop to iterate through array

      do { //Check for duplicates
        temp = (rand() % 1401) + 100; //Assigns random integer between and including 100 & 1500 to temp
        duplicates = 0;
        for (size_t k = 0; k < z; k++) { //I chose to use one loop to check for duplicates to reduce the size of the code
          if (arrayA[k / y][k % y] == temp) {
            duplicates = 1;
            break;
          }
        }
      } while(duplicates == 1);
      arrayA[i][j] = temp;


      do { //Do same for second array
        temp = (rand() % 1401) + 100;
        duplicates = 0;
        for (size_t k = 0; k < z; k++) {
          if (arrayB[k / y][k % y] == temp) {
            duplicates = 1;
            break;
          }
        }
      } while(duplicates == 1);
      arrayB[i][j] = temp;
    }
  }

  printf("arrayA: \n"); //Print arrayA
  for (size_t i = 0; i < x; i++) {
    for (size_t j = 0; j < y; j++) {
      printf("%04d ", arrayA[i][j]);
    }
    printf("\n");
  }

  printf("\n\n");

  printf("arrayB: \n"); //Print arrayA
  for (size_t i = 0; i < x; i++) {
    for (size_t j = 0; j < y; j++) {
      printf("%04d ", arrayB[i][j]);
    }
    printf("\n");
  }

  printf("\n\n");

  //Print number of numbers and number of numbers in both arrays
  printf("Both arrays contain %d numbers each so there are %d numbers in total. \n", x * y, 2 * x * y);
  int count = 0;
  for (size_t i = 0; i < x; i++) {
    for (size_t j = 0; j < y; j++) {
      int z = x * y; //Allows one for loop to iterate through array
      for (size_t k = 0; k < z; k++) { //I chose to use one loop to check for duplicates to reduce the size of the code
        if (arrayA[i][j] == arrayB[k / y][k % y]) {
          count++;
          printf("%04d appears in both arrays. \n", arrayA[i][j]);
          break;
        }
      }
    }
  }
  printf("%d numbers appear in both arrays. \n", count);

  printf("\n\n");

  //Check if any corresponding cells in both arrays contain the same value
  for (size_t i = 0; i < x; i++) {
    for (size_t j = 0; j < y; j++) {
      if (arrayA[i][j] == arrayB[i][j]) {
        printf("WOW \n");
        printf("Elements (%d, %d) of both arrays are the same. \n", i + 1, j + 1);
      }
    }
  }

  printf("\n\n");

  //Create, fill and print an array containing the product of corresponding cells in arrayA and arrayB
  printf("An array containing the product of corresponding cells in arrayA and arrayB: \n");
  int productOfCells[x][y];
  for (size_t i = 0; i < x; i++) {
    for (size_t j = 0; j < y; j++) {
      productOfCells[i][j] = arrayA[i][j] * arrayB[i][j];
      printf("%07d ", productOfCells[i][j]);
    }
    printf("\n");
  }

  printf("\n\n");

  //Create, fill and print an array containing the sum of corresponding cells in arrayA and arrayB
  printf("An array containing the sum of corresponding cells in arrayA and arrayB: \n");
  int sumOfCells[x][y];
  for (size_t i = 0; i < x; i++) {
    for (size_t j = 0; j < y; j++) {
      sumOfCells[i][j] = arrayA[i][j] + arrayB[i][j];
      printf("%04d ", sumOfCells[i][j]);
    }
    printf("\n");
  }

  printf("\n\n");

  //Create, fill and print an array containing the sum of corresponding rows in arrayA and arrayB
  printf("An array containing the sum of corresponding rows in arrayA and arrayB: \n");
  int sumOfRows[x], sum;
  for (size_t i = 0; i < x; i++) {
    sum = 0;
    for (size_t j = 0; j < y; j++) {
      sum += arrayA[i][j] + arrayB[i][j];
    }
    sumOfRows[i] = sum;
    printf("%05d ", sumOfRows[i]);
    printf("\n");
  }

  printf("\n\n");

  //Create, fill and print an array containing the sum of corresponding columns in arrayA and arrayB
  printf("An array containing the sum of corresponding columns in arrayA and arrayB: \n");
  int sumOfColumns[x];
  for (size_t i = 0; i < y; i++) {
    sum = 0;
    for (size_t j = 0; j < x; j++) {
      sum += arrayA[j][i] + arrayB[j][i];
    }
    sumOfColumns[i] = sum;
    printf("%05d ", sumOfColumns[i]);
  }

  return 0;
}
