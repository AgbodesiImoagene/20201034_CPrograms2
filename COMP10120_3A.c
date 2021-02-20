/*
 * COMP10120_3A.c
 * Agbodesi Imoagene 11/02/21
 * A C program to simulate the die game pig.
 */

#include <stdio.h>
#include <stdlib.h> //For the rand and srand functions
#include <time.h> //For the time function
#include <conio.h> //For the getch function

int dieRoll(void); //Simulates a die roll
void printRules(void); //Prints the rules
void delay(int seconds); //Creates time delay to make the game feel more realistic
int main(void) {

  printRules();
  srand(time(NULL)); //Seeds the rand function only once

  //x and y hold the players scores, die holds the roll,
  //temp holds their decision and sum holds their score for the current run
  int i, x = 0, y = 0, die, temp, sum;

  while(1) { //Infinite loop that is broken once player 1 or player 2 has more than 100 points

    sum = 0;
    //Show player 1 their roll
    printf("Player 1's turn. \n\n");
    printf("You rolled: ");
    die = dieRoll();
    printf("%d \n\n", die);

    while (die != 1) { //If they dont roll a one ask if they want to hold or roll again
      sum += die;
      printf("Enter a 1 to hold or a 2 to roll again: ");
      scanf("%d", &temp);

      while ((temp != 1) && (temp != 2)) { //Check to make sure input is valid
        printf("Enter a 1 or a 2: ");
        scanf("%d", &temp);
      }

      if (temp == 1) { //If they choose to hold display their score
        x += sum;
        printf("Your earned %d points from this run. \n", sum);
        printf("Your current score is %d. \n\n\n", x);
        break;
      } else { //If they decide to roll display their roll
        printf("You rolled: ");
        die = dieRoll();
        printf("%d \n\n", die);
      }
    }

    if (die == 1) { //If they roll a one display their score
      printf("You didn't earn any points from this move. \n");
      printf("Your current score is %d. \n\n\n", x);
    }
    delay(2);

    if (x >= 100) { //If they win exit infinite loop
      break;
    }


    //Repeat for player 2
    sum = 0;
    printf("Player 2's turn. \n\n");
    printf("You rolled: ");
    die = dieRoll();
    printf("%d \n\n", die);

    while (die != 1) {
      sum += die;
      printf("Enter a 1 to hold or a 2 to roll again: ");
      scanf("%d", &temp);

      while ((temp != 1) && (temp != 2)) {
        printf("Enter a 1 or a 2: ");
        scanf("%d", &temp);
      }

      if (temp == 1) {
        y += sum;
        printf("Your earned %d points from this run. \n", sum);
        printf("Your current score is %d. \n\n\n", y);
        break;
      } else {
        printf("You rolled: ");
        die = dieRoll();
        printf("%d \n\n", die);
      }
    }

    if (die == 1) {
      printf("You didn't earn any points from this move. \n");
      printf("Your current score is %d. \n\n\n", y);
    }
    delay(2);

    if (y >= 100) {
      break;
    }
  }

  if (x >= 100) { //Output winner
    printf("Player 1 wins. \n");
  } else {
    printf("Player 2 wins. \n");
  }
  return 0;
}

int dieRoll(void) { //Returns random integer between and including 1 & 6
  delay(2.5); //Add some suspense
  return (rand() % 6) + 1;
}

void printRules(void) {
  printf("Each turn, a player repeatedly rolls a die until either a 1 is rolled or the player decides to \"hold\": \n\n");
  printf("\tIf the player rolls a 1, they score nothing and it becomes the next player's turn. \n");
  printf("\tIf the player rolls any other number, it is added to their turn total and the player's turn continues. \n");
  printf("\tIf a player chooses to \"hold\", their turn total is added to their score, and it becomes the next player's turn. \n\n");
  printf("The first player to score 100 or more points wins. \n\n");
}

void delay(int seconds) {
    int milliseconds = 1000 * seconds; //Converting time into milliseconds
    clock_t start_time = clock(); //Storing start time
    while (clock() < (start_time + milliseconds))
    {} //Looping till required time is achieved
}
