#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MM = 2e5 + 5;
int N;
LL sum=0, a[MM], psa[MM];

struct comp {
    bool operator () (LL const &i, LL const &j) const {
        return i > j;
    }
};

int main () {
    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> a[i];
    }
    sort(a+1, a+N+1, comp());
    for(int i = 1; i <= N; i++) {
        psa[i] = psa[i-1] + a[i];
    }
    for(int i = 1; i <= N; i++) {
        sum += (a[i] * (N-i)) - (psa[N]-psa[i]);
    }
    cout << sum << "\n";
}
