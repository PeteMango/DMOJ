#include <bits/stdc++.h>
using namespace std;

const int MM = 1e6 + 5;
int N, a[MM];
string ans = "";

int main () {
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }
    sort(a, a+N);
    for(int i = 0; i < N; i++) {
        if(i) {
            cout << ' ';
        }
        if(i & 1) {
            cout << a[N-(i/2)-1];
            ans.push_back('S');
        }
        else {
            cout << a[i/2];
            ans.push_back('B');
        }
    }
    cout << "\n";
    if(N & 1) ans.back() = 'E';
    cout << ans << "\n";
}
