#include <bits/stdc++.h>
using namespace std;

int arr[4];

int main () {
  for(int i = 0; i < 4; i++) {
    scanf("%d", &arr[i]);
  }
  sort(arr, arr+4);
  printf("%d\n", arr[0]*arr[2]);
}