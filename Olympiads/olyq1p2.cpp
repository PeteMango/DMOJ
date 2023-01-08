#include <bits/stdc++.h>
using namespace std;
const int MM = 2e6 + 5;
int N, a[MM];

int calcLon () {
  int up=1, dwn=1;
  for(int i = 1; i < N; i++) {
    if(a[i] > a[i-1]) up = dwn+1;
    else if(a[i] < a[i-1]) dwn = up+1;
  }
  return max(dwn, up);
}

int main() {
  cin >> N;
  for(int i = 0; i < N; i++) cin >> a[i];
  cout << calcLon() << "\n";
}