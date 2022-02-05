#include <bits/stdc++.h>
using namespace std;

int N, cnt=0;
string s;

int main () {
    cin >> N >> s;
    for(int i = 0; i < 2*N-1; i++) {
        if(s[i] == 'I' && s[i+1] == 'U') {
            cnt++;
            i++;
        }
    }
    cout << N-cnt << "\n";
}
