#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+ 5;
typedef long long LL;
int N, K;
LL a[MM], psa[MM];

int main () {
    cin >> N >> K;
    for(int i = 1; i <= N; i++) {
        cin >> a[i];
    }
    sort(a+1, a+1+N);
    psa[N+1] = 0;
    for(int i = N; i >= 1; i--) {
        if(a[i] > 0) {
            psa[i] = psa[i+1] + a[i];
        }
        else psa[i] = psa[i+1];
    }
//    for(int i = 1; i <= N; i++) {
//        cout << psa[i] << "\n";
//    }
    for(int i = 1, x; i <= K; i++) {
        cin >> x;
        cout << psa[N-x+1] << "\n";
    }
}
