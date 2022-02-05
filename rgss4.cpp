#include <bits/stdc++.h>
using namespace std;
const int MM = 1e3 + 5;
int N, a[MM], dp[MM];

int main () {
    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> a[i];
        dp[i] = a[i];
    }
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= i; j++) {
            if(a[i] > a[j] && dp[i] < dp[j] + a[i]) {
                dp[i] = dp[j] + a[i];
            }
        }
    }
    sort(dp+1, dp+N+1);
    cout << dp[N] << "\n";
}
