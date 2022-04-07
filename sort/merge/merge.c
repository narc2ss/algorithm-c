#include <stdio.h>

int sorted[10];

void merge(int arr[], int start, int middle, int end) {
  int left = start;
  int right = middle + 1;
  int key = start;

  while (left <= middle && right <= end) {
    if (arr[left] < arr[right]) {
      sorted[key] = arr[left];
      left++;
    } else {
      sorted[key] = arr[right];
      right++;
    }
    key++;
  }

  if (left > middle) {
    for (int i = right; i <= end; i++) {
      sorted[key] = arr[i];
      key++;
    }
  } else {
    for (int i = left; i <= middle; i++) {
      sorted[key] = arr[i];
      key++;
    }
  }

  for (int i = 0; i <= end; i++) {
    arr[i] = sorted[i];
  }
}

void mergeSort(int arr[], int start, int end) {
  if (start < end) {
    int middle = (start + end) / 2;
    mergeSort(arr, start, middle);
    mergeSort(arr, middle + 1, end);
    merge(arr, start, middle, end);
  }
}

int main(void) {
  int arr[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

  mergeSort(arr, 0, 10 - 1);

  for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}