#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL N, B, S, G, cur;

int main () {
    cin >> N >> B >> S >> G;
    cur = 1*B + 3*S + 5*G;
    if(N < cur) {
        cout << 0 << "\n";
    }
    else {
        cout << (N-cur)/5 + 1 << "\n";
    }
}
