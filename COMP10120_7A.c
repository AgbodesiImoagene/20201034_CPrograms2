/*
 * COMP10120_7A.c
 * Agbodesi Imoagene 26/03/21
 * A C Program which demonstrates the use of an array of pointers and has functions to do the following:
 *
 * Jumble the order of words
 * Print the words
 * Select a random word
 */

#include <stdio.h>
#include <stdlib.h> //Contains rand and srand functions
#include <time.h> //Contains time function
#define SIZE 12

//Function prototypes
void print(char *a[], int size);
void jumble(char *a[], int size);
void random(char *a[], int size);

int main(void) {
  srand(time(NULL)); //Seeds rand function
  void (*funct[3])(char **, int) = {print, jumble, random}; //Pointers to functions
  char *words[SIZE] = {"COMP10120", "is", "my", "favourite", "module", "and",
                      "I", "learn", "lots", "of", "interesting", "things"}; //Array of character pointers
  int choice; //Holds user decision

  //User input
  printf("To print the words enter 1. \n");
  printf("To jumble the words enter 2. \n");
  printf("To get a random word enter 3. \n");
  printf("To end the program enter any other number. \n");
  scanf("%d", &choice);

  while ((choice >= 1) && (choice <= 3)) { //Allow user call functions multiple times
    (*funct[choice - 1])(words, SIZE); //Function call
    puts("");

    //User input
    printf("To print the words enter 1. \n");
    printf("To jumble the words enter 2. \n");
    printf("To get a random word enter 3. \n");
    printf("To end the program enter any other number. \n");
    scanf("%d", &choice);
  }

  puts("Thank you for using this program. ");
  return 0;
}

void print(char *a[], int size) {
  puts("");
  puts("This function iterates through each element in the array(char *) and prints the string indexed by the iterator. ");
  puts("");

  for (size_t i = 0; i < size; i++) { //Iterate through array and print each string(char *)
    printf("%s ", a[i]);
  }
  puts("");
}

void jumble(char *a[], int size) {
  puts("");
  printf("This function iterates through each element, selects a random number less than the size of the array, \n");
  printf("and swaps the element at this index with the element at the index of the iterator. \n");
  puts("");

  char *temp; //Holds pointer during swap
  int x; //Holds random integer
  for (size_t i = 0; i < size; i++) {
    x = rand() % size; //Assign a random integer less than 'size' to x

    //Swap a[i] and a[x]
    temp = a[i];
    a[i] = a[x];
    a[x] = temp;
  }
}

void random(char *a[], int size) {
  puts("");
  puts("This function selects a random number less than the size of the array and prints the element at that index. ");
  puts("");

  int x = rand() % size; //Assign a random integer less than 'size' to x
  puts(a[x]); //Print a[x]
}
