#include <bits/stdc++.h>
using namespace std;
const int MM = 1e4 + 5, NN = 15;
int N, K, bitmask[MM];

int main () {
    cin >> N >> K;
    for(int i = 0; i < N; i++) {
        char s[MM];
        cin >> s;
        for(int j = 0; j < K; j++) {
            bitmask[i] = bitmask[i] * 2 + (s[j] == 'T');
        }
    }
    int ans = 0;
    for(int i = 0; i < (1 << K); i++) {
        int minscore = K;
        for(int j = 0; j < N; j++) {
            minscore = min(minscore, __builtin_popcount(i^bitmask[j]));
        }
        ans = max(ans, minscore);
    }
    cout << ans << "\n";
}
