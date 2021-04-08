/*
 * COMP10120_9A.c
 * Agbodesi Imoagene 08/04/21
 * A C Program that creates 7 structs from the integer array
 * (myStock) and writes each struct to a binary file named stockUpdate.dat.
 * Each struct is defined with the members shown below. It also allows a
 * user to update the stock of a given item. The integer array (myStock)
 * has 2 columns.  Column 0 contains the item code code and column 1
 * contains the number of items of that code in stock.
 */

#include <stdio.h>
#include <stdlib.h> //Contains exit function

int myStock [7][2] = {{86956, 1}, {36568, 3}, {6565, 0}, {999555, 22},
                      {85446, 12}, {84291, 88}, {78103, 10}};

typedef struct item{ //Define type Item to hold data about stock
   int item_code;
   int item_count;
} Item;

//Function prototypes
void initialise(FILE **fp);
void update(FILE **fp);
void print(FILE **fp);

int main(void) {
  //Check if file exists or can be opened, if not create file
  FILE *ptr = fopen("stockUpdate.dat", "rb+");
  if (ptr == NULL) {
    initialise(&ptr);
  }

  //Get user decision
  unsigned int choice;
  puts("To update stock enter 1. ");
  puts("To print stock enter 2. ");
  puts("To end the program enter any other number. ");
  scanf("%u", &choice);

  while ((choice == 1) || (choice == 2)) { //Call appropriate funtion and prompt decision until user decide to end program
    if (choice == 1) {
      update(&ptr);
    } else if (choice == 2) {
      print(&ptr);
    }

    puts("To update stock enter 1. ");
    puts("To print stock enter 2. ");
    puts("To end the program enter any other number. ");
    scanf("%u", &choice);
  }

  puts("Thank you for using this program. ");
  return 0;
}

void initialise(FILE **fp) {
   Item stock[7]; //Declare struct array
   for (size_t i = 0; i < 7; i++) { //Initialise struct array with data from myStock
    stock[i].item_code = myStock[i][0];
    stock[i].item_count = myStock[i][1];
   }

   if ((*fp = fopen("stockUpdate.dat", "wb+")) == NULL) { //Create file and check it was opened
     puts("File could not be opened. ");
     exit(EXIT_FAILURE);
   }

   int check = fwrite(stock, sizeof(stock), 1, *fp); //Write data in stock to file
   if (check < 1) { //Check that file was successfully written to
     puts("Write error occured. ");
     exit(EXIT_FAILURE);
   }
 }

void update(FILE **fp) {
   int x; //Holds stock to be updated
   Item temp; //Holds data to update file with

   //Get user input
   printf("Enter the item code or index(number from 1-7), enter 0 to stop updating: ");
   scanf("%d", &x);

   while (x != 0) { //Repeat until user decided to stop updating
     if ((x <= 7) && (x >= 1)) { //Case that user entered index

       //Assign appropriate data to temp and update item count from user
       temp.item_code = myStock[x - 1][0];
       printf("Enter the new item count: ");
       scanf("%d", &temp.item_count);

       //Find correct position in file
       int seekCheck = fseek(*fp, (x - 1) * sizeof(Item), SEEK_SET); //Set pointer to position indicated by x
       if (seekCheck != 0) { //Check that pointer could be set
         puts("Seek error occured. ");
         exit(EXIT_FAILURE);
       }

       int writeCheck = fwrite(&temp, sizeof(Item), 1, *fp); //Write data in temp to file at position indicated by file pointer
       if (writeCheck < 1) { //Check that data could be written
         puts("Write error occured. ");
         exit(EXIT_FAILURE);
       }

     } else { //Case that user entered item code
       int check = 0; //Holds value of 0 or 1 to indicate valid item code
       int index; //Holds position of item in array

       for (size_t i = 0; i < 7; i++) {
         if (x == myStock[i][0]) { //Check if value user entered is in myStock
           check = 1;
           index = i; //Set index to correct array index
           break;
         }
       }

       if (check == 0) { //Case for invalid item code
         puts("There is no item with this code. ");
       } else { //Case for valid item code
         //Set appropriate values of temp
         temp.item_code = x;
         printf("Enter the new item count: ");
         scanf("%d", &temp.item_count);

         int seekCheck = fseek(*fp, (index) * sizeof(Item), SEEK_SET); //Set pointer to position indicated by index
         if (seekCheck != 0) { //Check that pointer could be set
           puts("Seek error occured. ");
           exit(EXIT_FAILURE);
         }

         int writeCheck = fwrite(&temp, sizeof(Item), 1, *fp); //Write data in temp to file at position indicated by file pointer
         if (writeCheck < 1) { //Check that data could be written
           puts("Write error occured. ");
           exit(EXIT_FAILURE);
         }
       }
     }

     printf("Enter the item code or index(number from 1-7), enter 0 to stop updating: ");
     scanf("%u", &x);
   }
 }

void print(FILE **fp) {
   rewind(*fp); //Set pointer to beginning of file
   Item temp; //Holds data to be printed

   while (fread(&temp, sizeof(Item), 1, *fp) == 1) { //Print until data cannot be read from file correctly
    printf("%d %d\n", temp.item_code, temp.item_count);
   }
 }
