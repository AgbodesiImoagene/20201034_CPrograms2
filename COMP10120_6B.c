/*
 * COMP10120_6B.c
 * Agbodesi Imoagene 04/03/21
 * A C program that has the following functions:
 * A function called addme which has a variable number of integers as arguments and returns the sum of the integers.
 * A function called multiplyme which has a variable number of integers as arguments and returns the product of the integers.
 * A function myPrinter which takes in a variable number of arguments of any type and prints each one a separate line.
 */

#include <stdio.h>
#include <stdarg.h> //Contains definitions and macros to handle variable length arguments
#include <conio.h> //Contains getch function
#include <string.h> //Contains strcspn function
#define STR_LEN 100

//Function declarations
int addme(int num, ...);
int multiplyme(int num, ...);
void printme(int type, int num, ...);

int main(void) {
  unsigned int choice; //Holds user decision
  unsigned int size; //Holds number of arguments
  int result; //Holds result of addition and subtraction
  int a[10] = {0}; //Holds integer arguments

  //User prompts and input
  puts("To add integers enter 1. ");
  puts("To multiply integers enter 2. ");
  puts("To print variables enter 3. ");
  scanf("%u", &choice);
  while ((choice < 1) || (choice > 3)) { //Check for appropriate input
    puts("Enter a number between 1 and 3. ");
    scanf("%u", &choice);
  }
  if (choice == 1) {
    //User input
    printf("Enter the number of integers to be added: ");
    scanf("%u", &size);

    while (size > 10) { //Check that number of arguments does not exceed array size
      puts("The number of integers cannot be greater than 10. ");
      printf("Enter the number of integers to be added: ");
      scanf("%u", &size);
    }

    for (size_t i = 0; i < size; i++) {
      printf("Enter integer %u: ", i + 1);
      scanf("%d", &a[i]);
    }

    //Call function addme and assign its output to result
    result = addme(size, a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8], a[9]);

    //Output
    printf("The sum of your integers is %d. \n", result);
  } else if (choice == 2) {
    printf("Enter the number of integers to be multiplied: ");
    scanf("%u", &size);

    while (size > 10) {
      puts("The number of integers cannot be greater than 10. ");
      printf("Enter the number of integers to be multiplied: ");
      scanf("%u", &size);
    }

    for (size_t i = 0; i < size; i++) {
      printf("Enter integer %u: ", i + 1);
      scanf("%d", &a[i]);
    }

    result = multiplyme(size, a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8], a[9]);

    printf("The product of your integers is %d. \n", result);
  } else {
    int type; //Holds integer to indicate type of variable
    //Arrays to hold different data types
    double b[10] = {0};
    char c[10];
    char d[10][STR_LEN];

    //User prompts and input
    puts("To print integers enter 1. ");
    puts("To print floating point numbers enter 2. ");
    puts("To print characters enter 3. ");
    puts("To print strings enter 4. ");
    scanf("%d", &type);

    while ((type < 1) || (type > 4)) { //Check for appropriate input
      puts("Enter a number between 1 and 4. ");
      scanf("%d", &type);
    }
    switch (type) {
      case 1: //Case for integer variables
      //User input
      printf("Enter the number of integers to be printed: ");
      scanf("%u", &size);

      while (size > 10) { //Check that number of arguments does not exceed array size
        puts("The number of integers cannot be greater than 10. ");
        printf("Enter the number of integers to be printed: ");
        scanf("%u", &size);
      }

      for (size_t i = 0; i < size; i++) { //Get intigers from user
        printf("Enter integer %u: ", i + 1);
        scanf("%d", &a[i]);
      }

      //Function call and output
      puts("Your integers are: ");
      printme(type, size, a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8], a[9]);
      break;

      case 2: //Case for floating point variables
      printf("Enter the number of floating point numbers to be printed: ");
      scanf("%u", &size);

      while (size > 10) {
        puts("The number of floating point numbers cannot be greater than 10. ");
        printf("Enter the number of floating point numbers to be printed: ");
        scanf("%u", &size);
      }

      for (size_t i = 0; i < size; i++) { //Get floating point numbers from user
        printf("Enter float %u: ", i + 1);
        scanf("%lf", &b[i]);
      }

      puts("Your floating point numbers are: ");
      printme(type, size, b[0], b[1], b[2], b[3], b[4], b[5], b[6], b[7], b[8], b[9]);
      break;

      case 3: //Case for character variables
      printf("Enter the number of characters to be printed: ");
      scanf("%u", &size);

      while (size > 10) {
        puts("The number of characters cannot be greater than 10. ");
        printf("Enter the number of characters to be printed: ");
        scanf("%u", &size);
      }

      getchar(); //Flush keyboard buffer

      for (size_t i = 0; i < size; i++) { //Get characters from user
        printf("Enter character %u: ", i + 1);
        c[i] = getch();
        printf("%c\n", c[i]);
      }

      puts("Your characters are: ");
      printme(type, size, c[0], c[1], c[2], c[3], c[4], c[5], c[6], c[7], c[8], c[9]);
      break;

      case 4: //Case for strings
      printf("Enter the number of strings to be printed: ");
      scanf("%u", &size);

      while (size > 10) {
        puts("The number of strings cannot be greater than 10. ");
        printf("Enter the number of strings to be printed: ");
        scanf("%u", &size);
      }

      getchar();

      for (size_t i = 0; i < size; i++) { //Get strings from user
        printf("Enter string %u: ", i + 1);
        fgets(d[i], STR_LEN, stdin);
        d[i][strcspn(d[i], "\n")] = '\0'; //Replace '\n' at the end of the string with '\0'
      }

      puts("Your strings are: ");
      printme(type, size, d[0], d[1], d[2], d[3], d[4], d[5], d[6], d[7], d[8], d[9]);
      break;
    }
  }
  return 0;
}

int addme(int num, ...) {
  int sum = 0; //Holds result of addition

  va_list args; //Declare variable args of type va_list

  va_start(args, num); //Initialise args

  for (size_t i = 0; i < num; i++) {
    sum += va_arg(args, int); //Sum arguments
  }

  va_end(args); //Facilitates a normal return to main
  return sum;
}

int multiplyme(int num, ...) {
  int product = 1; //Holds result of multiplication

  va_list args;

  va_start(args, num);

  for (size_t i = 0; i < num; i++) {
    product *= va_arg(args, int); //Multiply arguments
  }

  va_end(args);
  return product;
}

void printme(int type, int num, ...) {
  va_list args;

  va_start(args, num);

  switch (type) { //Print arguments
    case 1: //Print integer arguments
    for (size_t i = 0; i < num; i++) {
      printf("%d\n", va_arg(args, int));
    }
    break;

    case 2: //Print floating point arguments
    for (size_t i = 0; i < num; i++) {
      printf("%lf\n", va_arg(args, double));
    }
    break;

    case 3: //Print characters
    for (size_t i = 0; i < num; i++) {
      printf("%c\n", va_arg(args, int));
    }
    break;

    case 4: //Print strings
    for (size_t i = 0; i < num; i++) {
      printf("%s\n", va_arg(args, char *));
    }
    break;
  }

  va_end(args);
}
