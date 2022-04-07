#include <stdio.h>

int main(void) {
  int arr[10] = {10, 3, 6, 2, 5, 7, 8, 9, 4, 1};
  int temp, j;

  for (int i = 0; i < sizeof(arr) / sizeof(int) - 1; i++) {
    j = i;
    while (arr[j] > arr[j + 1]) {
      temp = arr[j];
      arr[j] = arr[j + 1];
      arr[j + 1] = temp;
      j--;
    }
  }

  for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}