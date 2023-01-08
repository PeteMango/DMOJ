#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
int N, A[MAXN];

int main () {
    scanf("%d", &N);
    for(int i = 1; i <= N; i++) {
        scanf("%d", &A[i]);
    }
    sort(A+1, A+N+1);
    if(N % 2 == 0) {
        int ans = A[N/2] + A[N/2+1];
        if(ans % 2 == 0) {
            printf("%d\n", ans/2);
        }
        else {
            printf("%d\n", ans/2+1);
        }
    }
    else {
        printf("%d\n", A[N/2+1]);
    }
}
