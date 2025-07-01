#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);

  int nums[n], num;
  for (int i = 0; i < n; i++) {
    scanf("%d", &num);
    nums[i] = num;
  }

  int a, b;
  scanf("%d %d", &a, &b);

  int c = 0;
  for (int i = 0; i < n; i++) {
    if (nums[i] >= a && nums[i] <= b) {
      c++;
    }
  }

  printf("%d %d", c, n-c);
  return 0;
}
