#include <stdio.h>

void quickSort(int arr[], int start, int end) {
  if (start >= end) {
    return;
  }

  int pivot = start;
  int left = start + 1;
  int right = end;
  int temp;

  while (left <= right) {
    while (arr[left] <= arr[pivot]) {
      left++;
    }
    while (arr[right] >= arr[pivot] && right > start) {
      right--;
    }
    if (left > right) {
      temp = arr[right];
      arr[right] = arr[pivot];
      arr[pivot] = temp;
    } else {
      temp = arr[right];
      arr[right] = arr[left];
      arr[left] = temp;
    }
  }

  quickSort(arr, start, right - 1);
  quickSort(arr, right + 1, end);
}

int main(void) {
  int arr[10] = {10, 5, 2, 7, 4, 6, 8, 1, 3, 9};

  quickSort(arr, 0, sizeof(arr) / sizeof(int) - 1);

  for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}