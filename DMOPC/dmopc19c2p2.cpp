#include <bits/stdc++.h>
using namespace std;
const int MM = 505;
int N, M, a[MM][MM], dp[MM][MM];

int main () {
    cin >> N >> M;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            cin >> a[i][j];
        }
    }
    memset(dp, 0x3f3f3f3f, sizeof(dp));
    dp[1][1] = a[1][1];
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            if(i == 1 && j == 1) {
                continue;
            }
            dp[i][j] = a[i][j] + min(dp[i-1][j], dp[i][j-1]);
        }
    }
    cout << dp[N][M] << "\n";
}
