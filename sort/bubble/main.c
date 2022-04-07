#include <stdio.h>

int main(void) {
  int arr[10] = {8, 2, 4, 1, 10, 6, 7, 5, 3, 9};
  int temp;

  for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {
    for (int j = 0; j < sizeof(arr) / sizeof(int) - i; j++) {
      if (arr[j] > arr[j + 1]) {
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }

  for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}