#include <stdio.h>

void primeFactors(void);
int primes(int x, int array[]);
int main(int argc, char const *argv[]) {
  int a;
  primeFactors();
  printf("To use the prime factor calculator again enter 1, else enter any other number: ");
  scanf("%d", &a);
  while (a == 1) {
    primeFactors();
    printf("To use the prime factor calculator again enter 1, else enter any other number: ");
    scanf("%d", &a);
  }
  return 0;
}

void primeFactors(void) {
  int x;
  printf("Enter the integer: ");
  scanf("%d", &x);
  int arr[x];
  int z = primes(x, arr);
  int arr2[z];
  for (size_t i = 0; i < z; i++) {
    arr2[i] = 0;
  }
  for (size_t i = 0; i < z; i++) {
    while (x % arr[i] == 0) {
      arr2[i]++;
      x /= arr[i];
    }
  }
  for (size_t i = 0; i < z; i++) {
    if (arr2[i] != 0) {
      if (arr2[i] == 1) {
        printf("%d \n", arr[i]);
      } else {
        printf("%d^%d \n", arr[i], arr2[i]);
      }
    }
  }
}

int primes(int x, int array[]) {
  array[0] = 2;
  int ind = 1, check;
  for (size_t i = 3; i <= x; i++) {
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
  return ind;
}
