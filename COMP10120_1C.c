/*
 * COMP10120_1B.c
 * Agbodesi Imoagene 26/01/21
 * A C program to determine if a year entered by a user is a leap year.
 * Technique gotten from https://www.timeanddate.com/date/leapyear.html
 */

 #include <stdio.h>

 int main(void) {
   int year; // Stores input year from user
   int leapYear = 0; // Flag for leap years (essentially used a boolean value)

   // Input
   printf("Enter year in the Gregorian calender e.g 2021: ");
   scanf("%d", &year);

   // Additional check
   // Year cannot be a negative value
   if (year < 0) {
     printf("The year cannot be negative. \n");
   } else {
     // Changes leapYear to 1 only if year is evenly divisible by 4 or 400 but not 100
     if (year % 4 == 0) {
       if (year % 100 == 0) {
         if (year % 400 == 0) {
           leapYear = 1;
         }
       } else {
         leapYear = 1;
       }
     }

     // Print appropriate output
     if (leapYear == 0) {
       printf("%d is not a leap year. \n", year);
     } else {
       printf("%d is a leap year. \n", year);
     }
   }
   printf("Thank you for using this program. \n");
   return 0;
 }
