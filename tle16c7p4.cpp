#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int T, ans=0;
LL x;

int main () {
    cin >> T;
    for(int i = 1; i <= T; i++) {
        cin >> x;
        ans=0;
        while(x != 0) {
            if(x == 3) {
                ans += 3;
                break;
            }
            if(x % 4 == 3) {
                x++;
            }
            else if(x % 4 == 1) {
                x--;
            }
            else {
                x /= 2;
            }
            ans++;
        }
        cout << ans << "\n";
    }
}
