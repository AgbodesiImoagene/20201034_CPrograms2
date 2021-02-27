#include <stdio.h>

int main(void) {
  int N;
  puts("This program prints out the prime numbers from 2 to N. ");
  printf("Enter the number N: ");
  scanf("%d", &N);
  int array[N];
  array[0] = 2;
  int ind = 1, check;
  for (size_t i = 3; i <= N; i++) {
    check = 0;
    for (size_t j = 0; j < ind; j++) {
      if (i % array[j] == 0) {
        check = 1;
      }
    }
    if (check == 0) {
      array[ind] = i;
      ind++;
    }
  }
  for (size_t i = 0; i < ind; i++) {
    printf("%d ", array[i]);
  }
  return 0;
}
