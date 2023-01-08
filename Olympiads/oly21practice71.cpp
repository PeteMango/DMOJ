#include <bits/stdc++.h>
using namespace std;
int N, M;
string s;

int main () {
    cin >> N >> M >> s;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == 'x') {
            M = max(M-1, 0);
        }
        else M++;
    }
    cout << M << "\n";
}
