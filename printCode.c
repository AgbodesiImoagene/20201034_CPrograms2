#include <stdio.h>
#include <string.h>
#define STR_LEN 1000
int main(int argc, char const *argv[]) {
  if (argc > 2) {
    puts("Format: program.exe file");
  } else if (argc == 2) {
    FILE *file;
    char x[STR_LEN];
    if ((file = fopen(argv[1], "r")) == NULL) {
      printf("%s could not be opened", argv[1]);
    }
    while (!feof(file)) {
      fgets(x, STR_LEN, file);
      x[strcspn(x, "\n")] = '\0';
      puts(x);
    }
    fclose(file);
  } else {
    FILE *file;
    char x[STR_LEN];
    if ((file = fopen("printCode.c", "r")) == NULL) {
      printf("%s could not be opened", argv[1]);
    }
    while (!feof(file)) {
      fgets(x, STR_LEN, file);
      x[strcspn(x, "\n")] = '\0';
      puts(x);
    }
    fclose(file);
  }
  return 0;
}
