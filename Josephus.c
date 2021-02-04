#include <stdio.h>
void josephusHelper(int n);
void josephus(int n, int arr[], int max);
void shift(int n, int arr[], int index);
int main() {
  int a;
  printf("How many soldiers are there: ");
  scanf("%d", &a);
  josephusHelper(a);
  return 0;
}
void josephusHelper(int n) {
  int arr[n];
  for (int i = 0; i < n; i++) {
    arr[i] = i + 1;
  }
  josephus(n, arr, n);
}
void josephus(int n, int arr[], int max) {
  if (n == 1) {
    printf("Soldier %d survived. \n", arr[0]);
    int j = 1, k = 0;
    while ((j <= max) && (k < n)) {
      if (j == arr[k]) {
        printf("|");
        k++;
      } else {
        printf(" ");
      }
      j++;
    }
    printf("\n");
    return;
  } else {
    for (int i = 0; i < n; i++) {
      if (i == n - 1) {
        printf("Soldier %d killed soldier %d. \n", arr[i], arr[0]);
        shift(n--, arr, 0);
      } else {
        printf("Soldier %d killed soldier %d. \n", arr[i], arr[i + 1]);
        shift(n--, arr, i + 1);
      }
      int j = 1, k = 0;
      while ((j <= max) && (k < n)) {
        if (j == arr[k]) {
          printf("|");
          k++;
        } else {
          printf(" ");
        }
        j++;
      }
      printf("\n");
    }
    josephus(n, arr, max);
  }
}
void shift(int n, int arr[], int index) {
  for (int i = index; i < n - 1; i++) {
    arr[i] = arr[i + 1];
  }
}
