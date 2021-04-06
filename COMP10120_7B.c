/*
 * COMP10120_7B.c
 * Agbodesi Imoagene 26/03/21
 * A C program that adds all the numbers from 1 to 50000 while ignoring all numbers
 * which are evenly divisible by 3 and 5 and prints the answer to the console.
 * It also contains a function that allows the user to enter the range of numbers
 * to sum and the numbers (evenly divisible by) to ignore.
 */

#include <stdio.h>

int extraFunct(int min, int max, int a, int b); //Extra function to repeat summation for different values

int main(void) {
  int choice; //Holds user decision
  int sum = 0; //Holds sum of permitted numbers

  for (int i = 1; i <= 50000; i++) { //Iterate through range and add permitted numbers to sum
    if ((i % 3 != 0) && (i % 5 != 0)) {
      sum += i;
    }
  }
  printf("The sum of all numbers from 1 to 50,000 not divisible by 3 and 5 is %d. \n", sum); //Print result

  //Allow user to choose whether to repeat with different numbers
  printf("To calculate the sum of a range of numbers not divisible by two numbers enter 1, else enter any other number: ");
  scanf("%d", &choice);

  if (choice == 1) {
    int result; //Holds result of summation
    int low, high; //Hold limits of range
    int x, y; //Hold numbers to check divisibility by

    //Input from user
    printf("Enter the lower limit of the range: ");
    scanf("%d", &low);
    printf("Enter the upper limit of the range: ");
    scanf("%d", &high);
    printf("Enter the first number: ");
    scanf("%d", &x);
    printf("Enter the second number: ");
    scanf("%d", &y);

    result = extraFunct(low, high, x, y); //Function call

    //Output result
    printf("The sum of all numbers from %d to %d not divisible by %d and %d is %d. \n", low, high, x, y, result);
  }

  puts("Thank you for using this program. ");
  return 0;
}

int extraFunct(int min, int max, int a, int b) {
  int sum = 0;
  for (int i = min; i <= max; i++) {
    if ((i % a != 0) && (i % b != 0)) {
      sum += i;
    }
  }
  return sum;
}
