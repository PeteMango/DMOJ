#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, ll> pil;
typedef pair<ll, ll> pll;
const int MOD = 1e9 + 7;
const int MAXN = 2003;

int N, T, Q, t[MAXN], dp[MAXN], tmp[MAXN];
ll ans;

int add(int x, int y){
    int ret = x + y;
    if(ret < 0) ret += MOD;
    if(ret >= MOD) ret -= MOD;
    return ret;
}

int main() {
    scanf("%d %d %d", &N, &T, &Q);
    dp[0] = 1;
    for(int i = 1; i <= N; i++){
        scanf("%d", &t[i]);
        for(int j = T; j >= t[i]; j--){
            dp[j] = add(dp[j], dp[j - t[i]]); // Possible time
        }
    }
    for(int i = 1, a, b, q; i <= Q; i++){
        scanf("%d %d %d", &a, &b, &q);
        a = t[a];
        b = t[b];
        q -= a + b;
        if(q < 0){
            printf("%d\n", 0);
            continue;
        }
        memcpy(tmp, dp, sizeof(dp));
        ans = 0;
        for(int j = a; j <= T; j++){
            tmp[j] = add(tmp[j], -tmp[j - a]);
        }
        for(int j = b; j <= T; j++){
            tmp[j] = add(tmp[j], -tmp[j - b]);
        }
        for(int j = 0; j <= q; j++){
            ans += tmp[j];
        }
        printf("%lld\n", ans % MOD);
    }
}
