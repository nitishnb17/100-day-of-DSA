#include <stdio.h>

int main() {
  int n, pos, x;
  int arr[100];

  printf("Enter number of elements: ");
  scanf("%d", &n);

  printf("Enter %d elements:\n", n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  printf("Enter position to insert (1 to %d): ", n + 1);
  scanf("%d", &pos);

  printf("Enter element to insert: ");
  scanf("%d", &x);

  for (int i = n; i >= pos; i--) {
    arr[i] = arr[i - 1];
  }
  arr[pos - 1] = x;
  n++;
  printf("Array after insertion: ");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}