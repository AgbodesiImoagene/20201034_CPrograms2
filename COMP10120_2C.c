/*
 * COMP10120_2C.c
 * Agbodesi Imoagene 03/02/21
 * A C program to convert a decimal integer to a binary one using a recursive
 * function and display it to the user. The conditions for the base cases of the
 * function are 'x == 0' and 'x == 1' where x is the decimal integer and 0 or 1
 * are printed out respectively. In the recursive instance the function is called
 * again for 'x / 2' (integer division) before 'x % 2' is printed out.
 */

#include <stdio.h>

void DecimalToBinary(int x); //Recursive function to compute and print binary conversion

int main() {
  int decimal; //Variable declaration to store integer

  //Input
  printf("Input a decimal number: ");
  scanf("%d", &decimal);
  while (decimal < 0) { //Check to make sure integer is positive
    printf("Decimal number must be positive. \n");
    printf("Input a decimal number: ");
    scanf("%d", &decimal);
  }

  //Output
  printf("Binary number ");
  DecimalToBinary(decimal); //Function call
  return 0;
}

void DecimalToBinary(int x) {
  if (x == 0) { //Base case 1
    printf("0 ");
    return;
  } else if (x == 1) { //Base case 2
    printf("1 ");
    return;
  } else {
    DecimalToBinary(x /  2); //Recursive call
    printf("%d ", x % 2);
    return;
  }
}
