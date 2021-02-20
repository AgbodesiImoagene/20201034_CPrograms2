/*
 * COMP10120_3C.c
 * Agbodesi Imoagene 11/02/21
 * A C program to find area and circumference of circle.
 */

 #include <stdio.h>

 int main(void) {
   double radius, area, circumference;

   //User input
   printf("Enter the radius of a circle: ");
   scanf("%lf", &radius);
   printf("%lf \n", radius);
   while (radius < 0.0) { //Check to make sure number is positive
     printf("Radius cannot be negative. \n");
     printf("Enter the radius of a circle: ");
     scanf("%Lf", &radius);
   }

   //Calculate area and circumference
   area = 3.142 * (radius * radius);
   circumference = 2 * 3.142 * radius;

   //Print area and circumference
   printf("Area of circle = %.1lf \n", area);
   printf("Circumference of circle = %.1lf \n", circumference);
   return 0;
 }
