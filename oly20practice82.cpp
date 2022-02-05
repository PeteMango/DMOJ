#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5 + 5;
int N, Q, a[MM];

int binarySearch (int x) {
    int L = 1, R = N, mid;
    while(L <= R) {
        mid = (L+R)/2;
        if(a[mid] == x) {
            return mid;
        }
        else if(a[mid] > x) {
            R = mid-1;
        }
        else {
            L = mid+1;
        }
    }
    return mid;
}

int main () {
    cin >> N >> Q;
    for(int i = 1; i <= N; i++) {
        cin >> a[i];
    }
    sort(a+1, a+N+1);
    for(int i = 1, L, R; i<= Q; i++) {
        cin >> L >> R;
        int Lft = binarySearch(L), Rgt = binarySearch(R);
        if(a[Lft] < L) Lft++;
        if(a[Rgt] > R) Rgt--;
        cout << (Rgt-Lft+1) << "\n";
    }
}
