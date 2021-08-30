#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL a, b, dp[10][10][20][2];
string s;

LL func (int F, int S, int L, bool flag) {
    if(L >= s.length()) {
        return 1;
    }
    else {
        if(dp[F][S][L][flag] == -1) {
            LL tmp = 0;
            if(flag) {
                for(int i = 0; i <= 9; i++) {
                    if(i != F && i != S) {
                        tmp += func(S, i, L+1, true);
                    }
                }
            }
            else {
                int lmt = s[L] - '0';
                for(int i = 0; i < lmt; i++) {
                    if(i != F && i != S) {
                        tmp += func(S, i, L+1, true);
                    }
                }
                if(lmt != F && lmt != S) {
                    tmp += func(S, lmt, L+1, false);
                }
            }
            dp[F][S][L][flag] = tmp;
        }
    }
    return dp[F][S][L][flag];
}

LL count (LL x) {
    if(x < 0) {
        return 0;
    }
    stringstream ss;
    ss << x;
    s = ss.str();
    memset(dp, -1, sizeof(dp));
    int f = s[0] - '0';
    LL ret=1;
    for(int i = 1; i <= f; i++) {
        ret += func(i, i, 1, i!= f);
    }
    for(int i = 2; i <= s.length(); i++) {
        for(int j = 1; j < 10; j++) {
            ret += func(j, j, i, true);
        }
    }
    return ret;
}

int main () {
    cin >> a >> b;
    cout << count(b) - count(a-1) << "\n";
}
