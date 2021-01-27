#include <stdio.h>
int main() {
  FILE *file;
  int i = 0;
  char x[10000];
  file = fopen("printCode.c", "r");
  while ((i < 9999) && (x[i] != EOF)) {
    x[i] = fgetc(file);
    i++;
  }
  fclose(file);
  x[i] = '\0';
  printf("%s\n", x);
  return 0;
}
