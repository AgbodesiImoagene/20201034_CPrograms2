/*
 * COMP10120_1B.c
 * Agbodesi Imoagene 26/01/21
 * A C program that allows you to enter your student number
 * from the keyboard and then prints each digit on a new line.
 * It also sums the numbers.
 * The student number should be the same length as a UCD student number (8 digits).
 */

 #include <stdio.h>
 #include <conio.h> //For the getch function so input can be read without a buffer

 int numTotal(char arr[]); //Sums the digits in the number

 int main(void) {
   char num[8]; //Character array to store 8 digits
   int x; //Stores sum

   // Input
   printf("Please enter your 8-digit student number: ");
   // Read 8 numbers from user
   for (int i = 0; i < 8;) {
     num[i] = getch();
     // Additional check
     // Character is added to string and printed only if it's a number character
     if ((num[i] >= '0') && (num[i] <= '9')) {
       printf("%c", num[i]);
       i++;
     }
   }
   //No need for null terminator as array isn't being treated as a string

   // Print each digit on a new line
   printf("\nYour student number is: \n");
   for (int i = 0; i < 8; i++) {
     printf("%c\n", num[i]);
   }

   // Calculate and output sum
   x = numTotal(num);
   printf("The sum of the digits in your student number is %d. \n", x);
   printf("Thank you for using this program. \n");
   return 0;
 }

 // Calculate sum
 int numTotal(char arr[]) {
   int sum = 0;
   for (int i = 0; i < 8; i++) {
     sum += arr[i] - '0';
   }
   return sum;
 }
