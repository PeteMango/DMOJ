#include <bits/stdc++.h>
using namespace std;

int L=0, M=0, S=0, mL=0, sL=0, sM=0, mS=0;
string s;

int main () {
    cin >> s;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == 'L') {
            L++;
        }
        else if(s[i] == 'M') {
            M++;
        }
        else {
            S++;
        }
    }
    for(int i = 0; i < L; i++) {
        if(s[i] == 'M') mL++;
        if(s[i] == 'S') sL++;
    }
    for(int i = L; i < L+M; i++) {
        if(s[i] == 'S') sM++;
    }
    for(int i = L+M; i < s.length(); i++) {
        if(s[i] == 'M') mS++;
    }
    cout << mL + sL + max(mS, sM) << "\n";
}
