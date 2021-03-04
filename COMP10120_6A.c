/*
 * COMP10120_6A.c
 * Agbodesi Imoagene 04/03/21
 * A C program that uses a structures and a random access file. It contains a sequence of C functions that
 * allow a user to set up a system to record/catalogue the DVDs that they have in a file. It records details
 * such as, a unique ID (key), the title, the genre, the year, but also details like if the DVD has been
 * borrowed and by whom (customer ID) and when. One function provides the functionality to update these
 * borrower details. It also includes a function that displays the IDs of all the DVDs that have been borrowed.
 */

#include <stdio.h>
#include <stdlib.h> //Contains exit function
#include <string.h> //Contains strcpy and strcspn functions
#define STR_LEN 20

typedef struct DVDinfo { //Define type DVDinfo to hold data about DVDs
  unsigned int ID;
  char title[STR_LEN];
  char genre[STR_LEN];
  unsigned int year;
  unsigned int borrowed;
  char customer[STR_LEN];
  char time[12];
} DVDinfo;

//Function declarations
void initialiseFile(void);
void DVDentry(void);
void DVDupdate(void);
void printBorrowedDVDs(void);

int main(void) {
  initialiseFile();

  DVDentry();

  int choice; //Holds user choice
  printf("\nTo update which DVDs have been borrowed enter 1, else enter any other number: ");
  scanf("%d", &choice);
  if (choice == 1) {
    DVDupdate();
  }

  printf("\nTo print which DVDs have been borrowed enter 1, else enter any other number: ");
  scanf("%d", &choice);
  if (choice == 1) {
    printBorrowedDVDs();
  }
  return 0;
}

void initialiseFile(void) {
  FILE *fp; //File pointer declaration

  if ((fp = fopen("DVDrental.dat", "wb")) == NULL) { //Open or create file and check that file could be opened
    puts("File could not be opened. ");
    exit(EXIT_FAILURE);
  }

  DVDinfo DVD = {0, "", "", 0, 0, "", ""}; //Declare and initialise an 'empty' variable of type DVDinfo
  int check; //Holds results of precautionary check

  for (size_t i = 0; i < 1000; i++) {
    check = fwrite(&DVD, sizeof(DVDinfo), 1, fp);
    if (check < 1) { //Check that file was successfully written to
      puts("Write error occured. ");
      exit(EXIT_FAILURE);
    }
  }

  fclose(fp); //Close file
}

void DVDentry(void) {
  FILE *fp;

  if ((fp = fopen("DVDrental.dat", "rb+")) == NULL) { //Open file and check that it was opened successfully
    puts("File could not be opened. ");
    exit(EXIT_FAILURE);
  }

  DVDinfo DVD = {0, "", "", 0, 0, "", ""};
  int seekCheck, writeCheck; //Variables to hold result of checks
  int arr[1000], j = 0, duplicate; //Variables for an extra check if user is about to overwrite data they already entered

  puts("Enter DVD ID");
  printf("DVD ID is a number between 1 and 1000, 0 to end input: ");
  scanf("%u", &DVD.ID);

  while (DVD.ID != 0) {
    if (DVD.ID <= 1000) { //Check that DVD id does not exceed 1000
      getchar(); //Flush keyboard buffer

      //User input
      printf("Enter DVD title: ");
      fgets(DVD.title, STR_LEN, stdin);
      DVD.title[strcspn(DVD.title, "\n")] = '\0'; //Replace '\n' at end of string with '\0'

      printf("Enter DVD genre: ");
      fgets(DVD.genre, STR_LEN, stdin);
      DVD.genre[strcspn(DVD.genre, "\n")] = '\0';

      printf("Enter the year the DVD was released: ");
      scanf("%u", &DVD.year);

      seekCheck = fseek(fp, (DVD.ID - 1) * sizeof(DVDinfo), SEEK_SET); //Set pointer to position indicated by DVD.ID
      if (seekCheck != 0) { //Check that pointer could be set
        puts("Seek error occured. ");
        exit(EXIT_FAILURE);
      }

      writeCheck = fwrite(&DVD, sizeof(DVDinfo), 1, fp); //Write data in DVD to file at position indicated by file pointer
      if (writeCheck < 1) { //Check that data could be written
        puts("Write error occured. ");
        exit(EXIT_FAILURE);
      }

      //Store DVD.ID in array
      arr[j] = DVD.ID;
      j++;
    }

    do { //Loop to let user decide whether or not to overwrite data if DVD.ID matches a previous one
      int choice; //Holds user decision
      printf("\nEnter DVD ID: ");
      scanf("%u", &DVD.ID);

      duplicate = 0;
      for (size_t i = 0; i < j; i++) { //Check if DVD.ID matches a previous one
        if (DVD.ID == arr[i]) {
          duplicate = 1;
          break;
        }
      }

      if (duplicate == 1) { //If it does allow user decide whether to overwrite data stored at that position in the file
        printf("Do you want to overwrite the data for DVD %04d? \n", DVD.ID);
        printf("Enter 1 to overwrite the data or any other value to skip: ");
        scanf("%d", &choice);

        if (choice == 1) {
          duplicate = 0;
        }
      }
    } while(duplicate == 1);
  }

  fclose(fp);
}

void DVDupdate(void) {
  FILE *fp;

  if ((fp = fopen("DVDrental.dat", "rb+")) == NULL) {
    puts("File could not be opened. ");
    exit(EXIT_FAILURE);
  }

  DVDinfo DVD;
  int seekCheck, readCheck, writeCheck; //Variables to hold results of checks

  puts("Enter DVD ID");
  printf("DVD ID is a number between 1 and 1000, 0 to end input: ");
  scanf("%u", &DVD.ID);

  while (DVD.ID != 0) {
    if (DVD.ID <= 1000) {
      printf("If the DVD has been borrowed enter 1, if it has been returned enter 0: "); //User indicates if DVD has been borrowed
      scanf("%u", &DVD.borrowed);

      while ((DVD.borrowed != 0) && (DVD.borrowed != 1)) { //Check that user entered appropriate input
        printf("Enter 0 or 1: ");
        scanf("%d", &DVD.borrowed);
      }

      if (DVD.borrowed == 0) { //Update details if DVD has been returned
        seekCheck = fseek(fp, (DVD.ID - 1) * sizeof(DVDinfo), SEEK_SET);
        if (seekCheck != 0) {
          puts("Seek error occured. ");
          exit(EXIT_FAILURE);
        }

        readCheck = fread(&DVD, sizeof(DVDinfo), 1, fp);
        if (readCheck < 1) {
          puts("Read error occured. ");
          exit(EXIT_FAILURE);
        }

        //Update DVD details
        DVD.borrowed = 0;
        strcpy(DVD.customer, "");
        strcpy(DVD.time, "");

        seekCheck = fseek(fp, (DVD.ID - 1) * sizeof(DVDinfo), SEEK_SET);
        if (seekCheck != 0) {
          puts("Seek error occured. ");
          exit(EXIT_FAILURE);
        }

        writeCheck = fwrite(&DVD, sizeof(DVDinfo), 1, fp);
        if (writeCheck < 1) {
          puts("Write error occured. ");
          exit(EXIT_FAILURE);
        }
      } else { //Update details if DVD has been borrowed
        seekCheck = fseek(fp, (DVD.ID - 1) * sizeof(DVDinfo), SEEK_SET);
        if (seekCheck != 0) {
          puts("Seek error occured. ");
          exit(EXIT_FAILURE);
        }

        readCheck = fread(&DVD, sizeof(DVDinfo), 1, fp);
        if (readCheck < 1) {
          puts("Read error occured. ");
          exit(EXIT_FAILURE);
        }

        getchar(); //Flush keyboard buffer

        //Update DVD details
        DVD.borrowed = 1;
        //User input
        printf("Enter the name of the customer that borrowed this DVD: ");
        fgets(DVD.customer, STR_LEN, stdin);
        DVD.customer[strcspn(DVD.customer, "\n")] = '\0';

        printf("Enter the time the DVD was borrowed in the format dd/mm/yyyy: ");
        fgets(DVD.time, 12, stdin);
        DVD.time[strcspn(DVD.time, "\n")] = '\0';

        seekCheck = fseek(fp, (DVD.ID - 1) * sizeof(DVDinfo), SEEK_SET);
        if (seekCheck != 0) {
          puts("Seek error occured. ");
          exit(EXIT_FAILURE);
        }

        writeCheck = fwrite(&DVD, sizeof(DVDinfo), 1, fp);
        if (writeCheck < 1) {
          puts("Write error occured. ");
          exit(EXIT_FAILURE);
        }
      }
    }

    printf("\nEnter DVD ID: ");
    scanf("%u", &DVD.ID);
  }

  fclose(fp);
}

void printBorrowedDVDs(void) {
  FILE *fp;

  if ((fp = fopen("DVDrental.dat", "rb")) == NULL) {
    puts("File could not be opened. ");
    exit(EXIT_FAILURE);
  }

  DVDinfo DVD;
  int check;
  puts("The DVDs that have been borrowed are: ");
  printf("%-7s %-22s %-22s %-8s %-22s %-12s\n", "DVD ID", "Title", "Genre", "Year", "Customer Name", "Time");

  while (!feof(fp)) {
    check = fread(&DVD, sizeof(DVDinfo), 1, fp);

    if (DVD.borrowed == 1) {
      printf("  %04u  %-22s %-22s %-8u %-22s %-12s\n", DVD.ID, DVD.title, DVD.genre, DVD.year, DVD.customer, DVD.time);
    }
  }

  fclose(fp);
}
