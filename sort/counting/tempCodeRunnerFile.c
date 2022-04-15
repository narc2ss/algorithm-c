eof(count) / sizeof(int); i++) {
    if (count[i] != 0) {
      for (int j = 0; j < count[i]; j++) {
        printf("%d ", i + 1);
      }
    }
  }
  printf("\n");