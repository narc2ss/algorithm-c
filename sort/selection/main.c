#include <stdio.h>

int main(void) {
  int arr[10] = {10, 3, 6, 2, 5, 7, 8, 9, 4, 1};
  int min, index, temp;

  for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {
    min = 11;
    for (int j = i; j < sizeof(arr) / sizeof(int); j++) {
      if (arr[j] < min) {
        min = arr[j];
        index = j;
      }
    }
    temp = arr[index];
    arr[index] = arr[i];
    arr[i] = temp;
  }

  for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}