#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5 + 5;
int N, a[MM];

int main () {
    scanf("%d", &N);
    for(int i = 1; i <= N; i++) {
        scanf("%d", &a[i]);
    }
    sort(a+1, a+N+1);
    int mx=-1, cur=a[1],t=0, num;
    for(int i = 1; i <= N; i++){
        if(a[i]==cur) {
            t++;
        }
        else {
            if(t > mx) {
                mx=t;
                num=a[i-1];
            }
            t=1;
            cur=a[i];
        }
    }
    cout << num << "\n";
}
