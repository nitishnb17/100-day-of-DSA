
#include <stdio.h>

int main() {
  int n, i, k, found = 0, comparisons = 0;
  int arr[100];
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  scanf("%d", &k);

  for (i = 0; i < n; i++) {
    comparisons++;
    if (arr[i] == k) {
      found = 1;
      break;
    }
  }

  if (found)
    printf("Found at index %d\n", i);
  else
    printf("Not Found\n");

  printf("Comparisons = %d", comparisons);

  return 0;
}