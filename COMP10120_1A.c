/*
 * COMP10120_1A.c
 * Agbodesi Imoagene 26/01/21
 * A C program that requests the weight of 4 gold nuggets in kg
 * and then calculate the value (in US$) for the heaviest and lightest nuggets
 * as well as the total value of the 4 nuggets.
 * My additional features would allow the user input the weight
 * in kilograms or pounds and repeat the program as many times as they like.
 */

#include <stdio.h>

#define GOLD_VALUE_PER_KILOGRAM 59260
#define POUNDS_TO_KILOGRAMS 0.453592

//Function declarations
void goldCalculator(void); //Makes program repeatable
double heaviest(double arr[]);
double lightest(double arr[]);
double sum(double arr[]);

int main(void) {
  goldCalculator();
  printf("Thank you for using this program. \n");
  return 0;
}

//Function declarations
void goldCalculator(void) {
  int a; //Stores user decision on kg or lb input
  int b; //Stores user decision on whether to use the program again
  double arr[4]; //Array to store the 4 values
  double max, min, total; //Store output values

  //Get input from user
  printf("\nTo enter the weight of the gold nuggets \nin lb enter 1, for kg enter any other value: ");
  scanf("%d", &a);
  printf("Enter the weight of 4 gold nuggets. \n");
  for (int i = 0; i < 4; i++) {
    printf("Nugget %d: ", i + 1);
    scanf("%lf", &arr[i]);
  }

  //Converts units if user chose to input the weight in pounds
  if (a == 1) {
    for (int i = 0; i < 4; i++) {
      arr[i] *= POUNDS_TO_KILOGRAMS;
    }
  }

  //Calculates output using functions
  max = heaviest(arr) * GOLD_VALUE_PER_KILOGRAM;
  min = lightest(arr) * GOLD_VALUE_PER_KILOGRAM;
  total = sum(arr) * GOLD_VALUE_PER_KILOGRAM;

  //Output
  printf("The value of the heaviest nugget is $%.2lf . \n", max);
  printf("The value of the lightest nugget is $%.2lf. \n", min);
  printf("The total value of the nuggets is $%.2lf. \n", total);

  printf("To use the program again enter 1, else enter any other value: ");
  scanf("%d", &b);
  if (b == 1) {
    goldCalculator();
  } else {
    return;
  }
}

double heaviest(double arr[]) {
  double max = 0;
  for (int i = 0; i < 4; i++) {
    if (arr[i] > max) {
      max = arr[i];
    }
  }
  return max;
}

double lightest(double arr[]) {
  double min = 2147483647;
  for (int i = 0; i < 4; i++) {
    if (arr[i] < min) {
      min = arr[i];
    }
  }
  return min;
}

double sum(double arr[]) {
  double total = 0;
  for (int i = 0; i < 4; i++) {
    total += arr[i];
  }
  return total;
}
