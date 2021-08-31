#include <bits/stdc++.h>
using namespace std;
int T;

int main () {
  cin >> T;
  for(int i = 1, N, K; i <= T; i++) {
    cin >> N >> K;
    int sum=0, cnt=0;
    for(int j = 1, x; j <= N; j++) {
      cin >> x;
      sum += x;
      if(sum >= K) {
        sum = 0;
        cnt++;
      }
    }
    cout << cnt << "\n";
  }
}
