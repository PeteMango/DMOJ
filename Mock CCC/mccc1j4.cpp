#include <bits/stdc++.h>
using namespace std;
const int MN = 1e6 + 5;
long long N, sum=0, a[MN], b[MN];
string s;

int main () {
    cin >> N >> s;
    // Forward
    int prev=-1;
    for(int i = 0; i < N; i++) {
        if(s[i] == '1') {
            a[i] = 0;
            prev = i;
        }
        else {
            if(prev==-1) {
                a[i] = 0x3f3f3f3f;
            }
            else a[i] = i-prev;
        }
    }
    // Backward
    prev=-1;
    for(int i = N; i >= 0; i--) {
        if(s[i] == '1') {
            b[i] = 0;
            prev = i;
        }
        else {
            if(prev==-1) {
                b[i] = 0x3f3f3f3f;
            }
            else b[i] = prev-i;
        }
    }
    for(int i = 0; i < N; i++) {
        sum += min(a[i], b[i]);
//        cout << a[i] << " " << b[i] << endl;
    }
    cout << sum << "\n";
}
