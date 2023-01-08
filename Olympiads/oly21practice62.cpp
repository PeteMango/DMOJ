#include <bits/stdc++.h>
using namespace std;
const int MM = 1005;
int N, mx=-1;
string s;

int digitSum (string s) {
    int ret=0;
    for(int i = 0; i < s.length(); i++) {
        ret += s[i] - '0';
    }
    return ret;
}

int main () {
    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> s;
        if(digitSum(s) > mx) {
            mx = digitSum(s);
        }
    }
    cout << mx << "\n";
}
