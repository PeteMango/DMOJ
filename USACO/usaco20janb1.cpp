#include <bits/stdc++.h>
using namespace std;
const int MM = 105;
string s[MM];
int N, K;

int main () {
    cin >> N >> K;
    for(int i = 1; i <= N; i++) {
        cin >> s[i];
    }
    int cur=0;
    for(int i = 1; i <= N; i++) {
        if(cur + s[i].length() > K) {
            cout << "\n" << s[i];
            cur = s[i].length();
        }
        else {
            if(cur > 0) {
                cout << " ";
            }
            cout << s[i];
            cur += s[i].length();
        }
    }
    cout << "\n";
}
