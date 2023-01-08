#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
const int MM = 2005;
int N;
LL dp[MM][MM][2], psa[MM], ans=0;
pii a[MM];

int main () {
    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a+1, a+N+1);
    for(int i = 1; i <= N; i++) {
        psa[i] = psa[i-1] + a[i].second;
        if(a[i].first == 0) {
            dp[i][i][0] = dp[i][i][1] = a[i].second;
        }
    }
    for(int i = 1; i <= N; i++) {
        for(int j = 1; i+j <= N; j++) {
            int k = i+j;
            if(dp[j+1][k][0] >= a[j+1].first - a[j].first) {
                dp[j][k][0] = max(dp[j][k][0], dp[j + 1][k][0] + a[j].second - (a[j + 1].first - a[j].first));
            }
            if(dp[j+1][k][1] >= a[k].first - a[j].first) {
                dp[j][k][0] = max(dp[j][k][0], dp[j + 1][k][1] + a[j].second - (a[k].first - a[j].first));
            }
            if(dp[j][k-1][1] >= a[k].first - a[k-1].first) {
                dp[j][k][1] = max(dp[j][k][1], dp[j][k - 1][1] + a[k].second - (a[k].first - a[k - 1].first));
            }
            if(dp[j][k-1][0] >= a[k].first - a[j].first) {
                dp[j][k][1] = max(dp[j][k][1], dp[j][k - 1][0] + a[k].second - (a[k].first - a[j].first));
            }
        }
    }
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            if(dp[i][j][0] || dp[i][j][1]) {
                ans = max(ans, psa[j]-psa[i-1]);
            }
        }
    }
    cout << ans << "\n";
}
