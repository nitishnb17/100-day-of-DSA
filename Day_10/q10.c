#include <stdio.h>
#include <string.h>

int main() {
  char str[100];
  printf("Enter string: ");
  scanf("%s", str);

  int left = 0;
  int right = strlen(str) - 1;
  int flag = 1;

  while (left < right) {
    if (str[left] != str[right]) {
      flag = 0;
      break;
    }
    left++;
    right--;
  }

  if (flag)
    printf("YES\n");
  else
    printf("NO\n");

  return 0;
}
