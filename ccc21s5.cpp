#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MM = 150005;

int N, M, diff[17][MM], t[17], x[MM], y[MM], z[MM], seg[2*MM];
LL a[MM];

void buildSegTree () {
    for(int i = N-1; i > 0; i--) {
        seg[i] = __gcd(seg[i << 1], seg[i << 1 | 1]);
    }
}

int query (int L, int R) {
    int ret = 720720;
    for(L += N, R += N; L < R; L >>= 1, R >>= 1) {
        if(L & 1) {
            ret = __gcd(ret, seg[L++]);
        }
        if(R & 1) {
            ret = __gcd(ret, seg[--R]);
        }
    }
    return ret;
}

int main () {
    scanf("%d %d", &N, &M);
    fill_n(a+1, N, 1);
    for(int i = 0; i < M; i++) {
        scanf("%d %d %d", &x[i], &y[i], &z[i]);
        diff[z[i]][x[i]]++;
        diff[z[i]][y[i] + 1]--;
    }
    for(int i = 1; i <= N; i++) {
        for(LL j = 1; j <= 16; j++) {
            t[j] += diff[j][i];
            if(t[j]) {
                LL d = __gcd(j, a[i]);
                a[i] = a[i] * j / d;
            }
        }
    }
    for(int i = 1; i <= N; i++) {
        if(a[i] > 1e9   ) {
            cout << "Impossible\n";
            return 0;
        }
    }
    for(int i = 0; i < N; i++) {
        seg[i+N] = a[i+1];
    }
    buildSegTree();
    for(int i = 0; i < M; i++) {
        if(query(x[i]-1, y[i]) != z[i]) {
            cout << "Impossible\n";
            return 0;
        }
    }
    for(int i = 1; i <= N; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
}
