#include <bits/stdc++.h>
using namespace std;
const int MM = 6;
int N, a[MM];

int distinctSum () {
    int sum=0, cnt=0;
    for(int i = 0; i < N; i++) {
        sum += a[i];
    }
    bool dp[N+1][sum+1];
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i <= N; i++) {
        dp[i][0] = true;
    }
    for(int i = 1; i <= N; i++) {
        dp[i][a[i-1]] = true;
        for(int j = 1; j <= sum; j++) {
            if(dp[i-1][j] == true) {
                dp[i][j] = true;
                dp[i][j + a[i-1]] = true;
            }
        }
    }
    for(int i = 0; i <= sum; i++) {
        if(dp[N][i]) {
            cnt++;
//            cout << i << "\n";
        }
    }
    return cnt;
}

int main () {
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }
    cout << distinctSum() << "\n";
}
