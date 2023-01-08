#include <bits/stdc++.h>
using namespace std;
int N;

vector<int> factors (int x) {
    vector<int> ret;
    for(int i = 1; i <= sqrt(x); i++) {
        if(x % i == 0) {
            ret.push_back(i);
            ret.push_back(x/i);
        }
    }
    sort(ret.begin(), ret.end());
    return ret;
}

int check (string sub, string s) {
    if(s.length() % sub.length() != 0) {
        return -1;
    }
    int cnt = s.length()/sub.length();
    string tmp = "";
    for(int i = 1; i <= cnt; i++) {
        tmp += sub;
    }
    if(s == tmp) {
        return cnt;
    }
    return -1;
}

int func (string s) {
    vector<int> fact = factors(s.length());
    for(int i = 0; i < fact.size(); i++) {
        if(check(s.substr(0, fact[i]), s) != -1) {
            return check(s.substr(0, fact[i]), s);
        }
    }
    return s.length();
}

int main () {
    cin >> N;
    for(int i = 1; i <= N; i++) {
        string s;
        cin >> s;
        cout << func(s) << "\n";
    }
}
