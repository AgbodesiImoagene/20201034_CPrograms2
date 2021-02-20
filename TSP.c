//Travelling Salesman Problem

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define iterMax 100000000

int rand_diff(int x);
int main() {
  srand(time(NULL));

  unsigned int N;
  unsigned long long int sum = 0;
  double avg;
  printf("Enter N: ");
  scanf("%d", &N);
  while ((N < 2) || (N > RAND_MAX)) {
    printf("N cannot be less than 2 or greater than %d. \n", RAND_MAX);
    printf("Enter N: ");
    scanf("%d", &N);
  }

  for (size_t i = 0; i < iterMax; i++) {
    sum += rand_diff(N);
  }
  avg = (double) (sum / iterMax);
printf("The average difference between two random values from 1 to %d is %lf. \n", N, avg);
printf("%lf N. \n", avg / N);
  return 0;
}

int rand_diff(int x) {
  int a = rand() % x, b = rand() % x;
  if (a > b) {
    return a - b;
  } else {
    return b - a;
  }
}
