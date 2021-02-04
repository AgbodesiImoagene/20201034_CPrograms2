/*
 * COMP10120_2B.c
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
#include <stdlib.h> //Contains functions srand and rand
#include <time.h> //Contains time function

void lotnums(void); //Creates and prints out random lottery numbers
double playsCost(int x); //Calculates cost for number of plays
void summ(void); //Provides a summary of the prizes

int main() {
  //Variable declarations
  int plays, summary = 0;
  double cost;

  srand(time(NULL)); //Seeds the rand function in the lotnums functions

  //Calls summ function if the user wishes
  printf("For a summary of the prices enter 1, else enter any other number: ");
  scanf("%d", &summary);
  if (summary == 1) {
    summ();
  }

  //User input
  printf("How many plays do you want to make: ");
  scanf("%d", &plays);
  while (plays < 1) { //Check to make sure at least 1 play is entered
    printf("You must make at least one play. \n");
    printf("How many plays do you want to make: ");
    scanf("%d", &plays);
  }

  //Output
  cost = playsCost(plays);
  printf("This will cost you $%.2lf. \n", cost);
  printf("Your lottery numbers are: \n");
  for (int i = 0; i < plays; i++) { // Call lotnums 'plays' times
    lotnums();
  }
  return 0;
}

void lotnums(void) {
  //Variable declarations
  int white[5], gold, same, temp;

  //Generate random numbers
  for (int i = 0; i < 5; i++) {
    do { //Check to make sure numbers from white pool are not repeated
      same = 0;
      temp = (rand() % 70) + 1;
      for (int j = 0; j < i; j++) {
        if (temp == white[j]) {
          same = 1;
          break;
        }
      }
    } while(same == 1);
    white[i] = temp;
  }
  gold = (rand() % 25) + 1;

  //Output draws
  for (int i = 0; i < 5; i++) {
    printf("%d ", white[i]);
  }
  printf("from the white balls and %d from the gold balls. \n", gold);
}

double playsCost(int x) {
  return 2 * x;
}

void summ(void) {
  double prizes[6] = {10, 10, 200, 500, 10000, 1000000}; //Some of the prizes to enable iteration
  printf("Mega Millions tickets cost $2.00 per play. \n");
  printf("The starting jackpot will vary based on sales and will be announced before each drawing. \n");
  printf("There are a total of nine ways to win a prize in Mega Millions, ranging from the jackpot down to $2: \n");
  printf("If a draw contains only the winning gold number, you win $2.00. \n");
  printf("If a draw contains only 1 winning white ball and the winning gold ball, you win $4.00. \n");
  for (int i = 0; i < 6; i++) { //Iteration makes it easier to print prizes
    if (i % 2 == 0) {
      printf("If a draw contains only %d winning white balls and the winning gold ball, you win $%.2lf. \n", 2 + (i / 2), prizes[i]);
    } else {
      printf("If a draw contains only %d winning white balls, you win $%.2lf. \n", 3 + (i / 2), prizes[i]);
    }
  }
  printf("If ALL 6 numbers in a draw are winning numbers, you win the JACKPOT!!! \n");
}
