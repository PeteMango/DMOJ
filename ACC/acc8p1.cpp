#include <bits/stdc++.h>
using namespace std;
int T;

int main () {
  cin >> T;
  for(int i = 1, N, K; i <= T; i++) {
    cin >> N >> K;
    if(N%K == 0) {
      cout << (N/K) << "\n";
    }
    else if(N < K) {
      cout << 1 << "\n";
    }
    else {
      cout << (N/K)+1 << "\n";
    }
  }
}
