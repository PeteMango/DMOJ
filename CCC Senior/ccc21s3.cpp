#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5 + 5;
int N;
long long ans=LLONG_MAX, idx=0, mnp, mxp, p[MM], w[MM], d[MM];

long long totalDist (int mid) {
    long long tmp = 0;
    for(int j = 1; j <= N; j++) {
        int dist = (abs(p[j] - mid) - d[j]);
        if(dist < 0) dist = 0;
        tmp += dist * w[j];
    }
    return tmp;
}

long long binarySearch(long long l, long long r) {
    if(l == r) {
        return ans;
    }
    long long mid = (l+r)/2;
    idx=mid;
    ans = totalDist(mid);
    if(totalDist(mid) < totalDist(mid+1) && totalDist(mid) < totalDist(mid-1)) return ans;

    if(totalDist(mid) < totalDist(mid+1)) {
        return binarySearch(l, mid-1);
    }
    else return binarySearch(mid+1, r);
}

int main () {
    scanf("%d", &N);
    for(int i = 1; i <= N; i++) {
        scanf("%d%d%d", &p[i], &w[i], &d[i]);
    }
    if(N == 1) {
        cout << 0 << "\n";
        return 0;
    }
    long long ans = binarySearch(0, 1e9+5);
    ans = min(ans, min(totalDist(idx+1), totalDist(idx-1)));
    cout << ans << "\n";
}
