/*
 * COMP10120_5A.c
 * Agbodesi Imoagene 25/02/21
 * A C program to copy the contents a one-dimensional character array into
 * another one-dimensional character array. The program includes two functions in
 * your program, one which demonstrates the functionality using pointer notation
 * and one which demonstrates the functionality using array indexing.
 */

#include <stdio.h>
#include <stdlib.h> //Contains exit function
#include <string.h> //Contains strcmp function
#define STR_LEN 20

int main(void) {
  //Variables to hold data from txt file
  char city[STR_LEN];
  char name[STR_LEN];
  int num;
  int age;
  int consent;

  FILE *fp; //File pointer declaration

  if ((fp = fopen("customers.txt", "r")) == NULL) { //File pointer initialisation and check that file is opened
    fclose(fp); //Close file
    puts("File customers.txt does not exist or is not readable. ");
    exit(EXIT_FAILURE); //Exit program
  } else {
    int i = 0; //Holds number of people who agree to share data to find average
    int sum = 0; //Holds ages of people who agree to share data to find average
    double avg; //contains average
    FILE *fp2 = fopen("customers2.txt", "w"); //File pointer declaration of file to be written to

    while (!feof(fp)) { //Read values until the end of the first txt file and print them to the second txt file
      fscanf(fp, "%s %s %d %d %d", &city, &name, &num, &age, &consent);

      if (consent == 1) { //Check for people who agree to share data
        sum += age; //Add age to sum
        i++;
        if (strcmp("Dublin", city) == 0) { //Check for people who live in Dublin
          fprintf(fp2, "%s\t%s\t%d\t%d\t%d\n", city, name, num, age, consent);
        }
      }
    }

    //Close files
    fclose(fp);
    fclose(fp2);

    //Calculate and print average
    avg = (double) sum / i;
    printf("The average age of the people who agreed to share their data is %.2lf. \n", avg);
  }
  return 0;
}
