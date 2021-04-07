#include <stdio.h>
#include <stdlib.h>

int myStock [7][2] = {{86956, 1}, {36568, 3}, {6565, 0}, {999555, 22}, {85446, 12}, {84291, 88}, {78103, 10}};

typedef struct item{
   int item_code;
   int item_count;
} Item;

void initialise(FILE **fp);
void update(FILE **fp);
void print(FILE **fp);

int main(void) {
  FILE *ptr = fopen("stockUpdate.dat", "rb+");
  if (1) {
    initialise(&ptr);
  }

  unsigned int choice;
  puts("To update stock enter 1. ");
  puts("To print stock enter 2. ");
  puts("To end the program enter any other number. ");
  scanf("%u", &choice);

  while ((choice == 1) || (choice == 2)) {
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
   Item stock[7];
   for (size_t i = 0; i < 7; i++) {
    stock[i].item_code = myStock[i][0];
    stock[i].item_count = myStock[i][1];
   }

   if ((*fp = fopen("stockUpdate.dat", "wb+")) == NULL) {
     puts("File could not be opened. ");
     exit(EXIT_FAILURE);
   }

   int check = fwrite(stock, sizeof(stock), 1, *fp);
   if (check < 1) { //Check that file was successfully written to
     puts("Write error occured. ");
     exit(EXIT_FAILURE);
   }
 }

void update(FILE **fp) {
   unsigned int x;
   Item temp;

   printf("Enter the item code or index(number from 1-7), enter 0 to stop updating: ");
   scanf("%u", &x);

   while (x != 0) {
     if ((x <= 7) && (x != 0)) {
       temp.item_code = myStock[x - 1][0];
       printf("Enter the new item count: ");
       scanf("%d", &temp.item_count);

       int seekCheck = fseek(*fp, (x - 1) * sizeof(Item), SEEK_SET); //Set pointer to position indicated by DVD.ID
       if (seekCheck != 0) { //Check that pointer could be set
         puts("Seek error occured. ");
         exit(EXIT_FAILURE);
       }

       printf("%d %d\n", temp.item_code, temp.item_count);
       int writeCheck = fwrite(&temp, sizeof(Item), 1, *fp); //Write data in DVD to file at position indicated by file pointer
       if (writeCheck < 1) { //Check that data could be written
         puts("Write error occured. ");
         exit(EXIT_FAILURE);
       }
     } else {
       int check = 0;
       int index;
       for (size_t i = 0; i < 7; i++) {
         if (x == myStock[i][0]) {
           check = 1;
           index = i;
           break;
         }
       }
       if (check == 0) {
         puts("There is no item with this code. ");
       } else {
         temp.item_code = x;
         printf("Enter the new item count: ");
         scanf("%d", &temp.item_count);

         int seekCheck = fseek(*fp, (index) * sizeof(Item), SEEK_SET); //Set pointer to position indicated by DVD.ID
         if (seekCheck != 0) { //Check that pointer could be set
           puts("Seek error occured. ");
           exit(EXIT_FAILURE);
         }

         int writeCheck = fwrite(&temp, sizeof(Item), 1, *fp); //Write data in DVD to file at position indicated by file pointer
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
   rewind(*fp);
   Item temp;
   while (!feof(*fp)) {
    fread(&temp, sizeof(Item), 1, *fp);
    printf("%d %d\n", temp.item_code, temp.item_count);
   }
 }
