#include <stdio.h>
#include <string.h>

int main() {
  char str[50][50], buffer[50];
  fgets(buffer, 50, stdin);
  int i = 0;
  while ((!feof(stdin)) && (i < 50)) {
      strcpy(str[i], buffer);
      if (str[i][strlen(str[i]) - 1] == '\n') {
        str[i][strlen(str[i]) - 1] = '\0';
      }
      puts(str[i]);
      i++;
      fgets(buffer, 50, stdin);
  }
  puts("Enter input: ");
  scanf("%50s", &buffer);
  while ((!feof(stdin)) && (i < 50)) {
      strcpy(str[i], buffer);
      puts(str[i]);
      i++;
      scanf("%50s", &buffer);
  }
  puts("Enter more: ");
  char ch;
  int j = 0;
  while (((ch = getchar()) != EOF) && (i < 50)) {
    if ((ch == '\n') || (j == 49)) {
      str[i][j] = '\0';
      puts(str[i]);
      j = 0;
      i++;
    } else {
      str[i][j] = ch;
      j++;
    }
  }
  puts("Enter even more: ");
  fgets(buffer, 50, stdin);
  while ((!feof(stdin)) && (i < 50)) {
      strcpy(str[i], buffer);
      if (str[i][strlen(str[i]) - 1] == '\n') {
        str[i][strlen(str[i]) - 1] = '\0';
      }
      puts(str[i]);
      i++;
      fgets(buffer, 50, stdin);
  }
  return 0;
}
