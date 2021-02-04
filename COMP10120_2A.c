/*
 * COMP10120_2A.c
 * Agbodesi Imoagene 03/02/21
 * A C program that uses a recursive function to calculate the
 * greatest common divisor (GCD) of two integers x and y.
 * The GCD of x and y is the largest integer that evenly divides
 * both x and y and is defined as follows: If y is equal to 0,
 * then gcd (x,y) is x; otherwise, gcd (x,y) is gcd (y, x%y).
 */

#include <stdio.h>

int GCD(int x, int y); //Returns the GCD of 2 integers
int main() {

  int x, y, result; //Variable declarations

  //User inputs the numbers
  printf("Enter the first number: ");
  scanf("%d", &x);
  printf("Enter the second number: ");
  scanf("%d", &y);
  while ((x < 0) || (y < 0)) { //Check to make sure numbers are positive
    if (x < 0) {
      printf("The first number cannot be negative. \n");
      printf("Enter the first number: ");
      scanf("%d", &x);
    } else {
      printf("The second number cannot be negative. \n");
      printf("Enter the second number: ");
      scanf("%d", &y);
    }
  }

  result = GCD(x, y);

  //Output
  printf("The GCD of %d and %d is %d. \n", x, y, result);
  return 0;
}

int GCD(int x, int y) {
  if (y == 0) { //Base case
    return x;
  } else { //Recursive call
    return GCD(y, x % y);
  }
}
