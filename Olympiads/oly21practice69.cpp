#include <bits/stdc++.h>
using namespace std;
const int MM = 105;
int N, M, mx=-1, ans=0, G[MM][MM];

int main () {
    cin >> N >> M;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            cin >> G[i][j];
            if(G[i][j] > mx) {
                mx = G[i][j];
            }
        }
    }
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            ans += (mx - G[i][j]);
        }
    }
    cout << ans << "\n";
}
