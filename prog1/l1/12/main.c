#include <stdio.h>

int main(){
  int n1, n2, n3;
  scanf("%d %d %d", &n1, &n2, &n3);
  int arr[3][2] = {{n1, 1}, {n2, 2}, {n3, 3}};

  while ( !(arr[0][0] < arr[1][0] && arr[1][0] < arr[2][0]) ) {
    for (int i = 0; i < 2; i++) {
      if (arr[i][0] > arr[i+1][0]) {
        int temp[2] = {arr[i+1][0], arr[i+1][1]};
        arr[i+1][0] = arr[i][0]; arr[i+1][1] = arr[i][1];
        arr[i][0] = temp[0]; arr[i][1] = temp[1];
      }
    }
  }

  printf("N%d = %d, ", arr[0][1], arr[0][0]);
  printf("N%d = %d, ", arr[1][1], arr[1][0]);
  printf("N%d = %d", arr[2][1], arr[2][0]);

  return 0;
}
