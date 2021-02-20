/*
 * COMP10120_4A.c
 * Agbodesi Imoagene 17/02/21
 * A C program which asks the user to enter a string (max 100 characters)
 * and then prints the number of vowels and consonants in the string using pointers.
 * The program contains a function to convert the string to uppercase.
 */

#include <stdio.h>

int whitespace(const char *string); //Function to check for whitespace in string
void vowelsAndConsonants(const char *string, int *const vowels, int *const consonants); //This function is pass-by-reference
void lowerToUpper(char *const string);

int main(void) {
  //Variable declarations
  char str[100];
  int vowelsCounter = 0, consonantsCounter = 0;
  int choice; //Holds user decision to convert to uppercase

  //User input
  printf("Enter any string (max 100 characters with no spaces): ");
  fgets(str, 100, stdin); //Stored the user input inside str which is an array.

  while (whitespace(str) == 1) { //Check to make sure there are no spaces.
    printf("Enter any string (max 100 characters with NO SPACES): ");
    fgets(str, 100, stdin);
  }

  vowelsAndConsonants(str, &vowelsCounter, &consonantsCounter); //Function call counts vowels and consonants

  //Output
  printf("Number of Vowels in String: %d \n", vowelsCounter);
  printf("Number of Consonants in String: %d \n", consonantsCounter);

  //Make the sring uppercase if the user chooses

  printf("If you want to make the string uppercase enter 1, else enter 2: ");
  scanf("%d", &choice);

  while ((choice != 1) && (choice != 2)) { //Check for appropriate input
    printf("Enter a 1 or a 2: ");
    scanf("%d", &choice);
  }

  if (choice == 1) {
    lowerToUpper(str);
  }

  printf("Thank you for using this program. \n");

  return 0;
}

//Characters in str cannot be modified but pointer is incremented to iterate
//through array (non-constant pointer to constant data)
int whitespace(const char *string) {
  int whitespaceCheck = 0;

  while ((*string != '\0') && (whitespaceCheck == 0)) { //The loop breaks if a space or tab character is found
    if ((*string == ' ') || (*string == '\t')) {
      whitespaceCheck = 1;
    }
    string++; //Pointer value is changed directly
  }

  return whitespaceCheck;
}

//Pointers vowels and consonants cannot be altered but the values referenced
//by the pointers is incremented to keep a running count (constant pointer to non-constant data)
void vowelsAndConsonants(const char *string, int *const vowels, int *const consonants) {
  while (*string != '\0') {
    if ((*string >= 'A') && (*string <= 'Z')) { //Check uppercase alphabets
      if ((*string == 'A') || (*string == 'E') || (*string == 'I') || (*string == 'O') || (*string == 'U')) {
        (*vowels)++; //The value of variables in caller function (main) are altered directly
      } else {
        (*consonants)++;
      }
    }

    if ((*string >= 'a') && (*string <= 'z')) { //Check lowercase alphabets
      if ((*string == 'a') || (*string == 'e') || (*string == 'i') || (*string == 'o') || (*string == 'u')) {
        (*vowels)++;
      } else {
        (*consonants)++;
      }
    }

    string++;
  }

  return;
}

void lowerToUpper(char *const string) {
  size_t i = 0;

  while (*(string + i) != '\0') { //Pointer/offset notation so pointer string is not altered and can be printed
    if ((*(string + i) >= 'a') && (*(string + i) <= 'z')) {
      *(string + i) += 'A' - 'a';
    }
    i++;
  }

  printf("Your string in uppercase is: %s \n", string);

  return;
}
