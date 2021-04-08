/*
 * COMP10120_8A.c
 * Agbodesi Imoagene 03/04/21
 * A C Program which, using structures, can fill and initialise the structures with user data (read from the attached
 * files: towns.txt and counties.txt - you must click into the question to see the attached files) and then print out
 * the name, population, county’s longName, county’s shortName and the county’s population for each of the 5 town records
 * by using struct member reference notation.
 */

#include <stdio.h>
#include <stdlib.h> //Contains memory allocation functions
#include <string.h> //Contains strcmp function
#define STR_LEN 20

//Create aliases for structure types
typedef struct county{
    char *longName;
    char *shortName;
    unsigned int population;
} county;

typedef struct town{
    char *name;
    unsigned int population;
    county aCounty;
} town;

int main(void) {
  FILE *fp1, *fp2; //Declare filepointers for the two files
  town x; //Declare a variable to hold town info town
  county temp; //Declare a variable to temporarily hold county info town

  //Allocate memory to string pointers to hold data
  x.name = (char *) malloc(20 * sizeof(char));
  x.aCounty.longName = (char *) malloc(20 * sizeof(char));
  x.aCounty.shortName = (char *) malloc(20 * sizeof(char));
  temp.longName = (char *) malloc(20 * sizeof(char));
  temp.shortName = (char *) malloc(20 * sizeof(char));

  printf("%-22s %-22s %-22s %-22s %-22s \n\n", "Town Name", "Town Population",
  "County Long Name", "County Short Name", "County Population"); //Print table header

  if ((fp1 = fopen("towns.txt", "r")) == NULL) { //Open towns.txt and check that file could be opened
    puts("File could not be opened. ");
    exit(EXIT_FAILURE);
  };

  while (!feof(fp1)) { //Read data until the end of the first txt file
    fscanf(fp1, "%s %u %s", x.name, &x.population, x.aCounty.longName); //Assign data to x
    if ((fp2 = fopen("counties.txt", "r")) == NULL) { //Open countiess.txt and check that file could be opened
      puts("File could not be opened. ");
      exit(EXIT_FAILURE);
    };

    do { //Read data line by line from county.txt until a line is found that matches the county name in x
      fscanf(fp2, "%s %s %u", temp.longName, temp.shortName, &temp.population);
    } while((strcmp(x.aCounty.longName, temp.longName) != 0) && (!feof(fp2)));

    //Assign data in temp to x
    x.aCounty.shortName = temp.shortName;
    x.aCounty.population = temp.population;

    fclose(fp2);

    printf("%-22s %-22u %-22s %-22s %-22u \n\n", x.name, x.population,
    x.aCounty.longName, x.aCounty.shortName, x.aCounty.population); //Print data
  }

  //Free allocated memory
  free(x.name);
  free(x.aCounty.longName);
  free(x.aCounty.shortName);
  free(temp.longName);
  free(temp.longName);

  fclose(fp1);

  return 0;
}
