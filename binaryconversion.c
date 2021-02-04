/*
 * COMP10120_2C.c
 * Agbodesi Imoagene 03/02/21
 * A C program containing a function which can make a suitable and valid
 * selection of numbers for the Mega Millions Lottery and display them to
 * the user.  The function should generate random numbers and the numbers
 * should be different each time the function is run. It includes functionality
 * to request the number of plays the user wants and output the total cost
 * of the ticket. Include a function that can print a summary of the prizes
 * when the function is called. See the mega millions winning description.
 */

#include <stdio.h>
#include <conio.h> //For the getch function so input can be read without a buffer
int stringToBin(char arr[], int size);
int decToBin(int x);
int binToDec(int x);
int main() {
  int binOrDec, x, y, i = 0;
  char binary[100];
  printf("To convert a binary integer into a decimal integer enter 1, for the opposite enter 2: ");
  scanf("%d", &binOrDec);
  while ((binOrDec != 1) && (binOrDec != 2)) {
    printf("You must enter 1 or 2. \n");
    printf("To convert a binary integer into a decimal integer enter 1, for the opposite enter 2: ");
    scanf("%d", &binOrDec);
  }
  if (binOrDec == 1) {
    printf("Hit the space key when you have finished entering the integer. \n");
    printf("Enter the integer: ");
    do {
      binary[i] = getch();
      if ((binary[i] >= '0') && (binary[i] <= '1')) {
        printf("%c", binary[i]);
        i++;
      }
    } while((binary[i] != ' ') && (i < 100));
    y = stringToBin(binary, i);
    x = binToDec(y);
    printf("Your integer in decimal form is %d. \n", x);
  } else {
    printf("Enter the integer: ");
    scanf("%d", &y);
    x = decToBin(y);
    printf("Your integer in binary form is %d. \n", x);
  }
  return 0;
}
int stringToBin(char arr[], int size) {
  int x = 0;
  for (int i = 0; i < size; i++) {
    x += arr[i] - '0';
    x *= 10;
  }
  printf("%d\n", x / 10);
  return x / 10;
}
int decToBin(int x) {
  int binary = 0, multiple = 1;
  if (x == 0) {
    return 0;
  } else {
    while (x > 1) {
      binary += (x % 2) * multiple;
      multiple *= 10;
      x /= 2;
    }
    binary += multiple;
    return binary;
  }
}
int binToDec(int x) {
  int decimal = 0, multiple = 1;
  if (x == 0) {
    return 0;
  } else {
    while (x > 1) {
      decimal += (x % 10) * multiple;
      multiple *= 2;
      x /= 10;
    }
    decimal += multiple;
    return decimal;
  }
}
