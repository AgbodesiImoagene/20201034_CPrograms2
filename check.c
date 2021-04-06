#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  char *st;
  FILE *fp;
  fp = fopen("towns.txt", "r");
  st = (char *) malloc(20 * sizeof(char));

  fgets(st, 20, fp);
  puts(st);
  return 0;
}
