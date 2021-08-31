#include <bits/stdc++.h>
using namespace std;
int N;
string s;

void func(int N, string s) {
    int start, end, mx=1;

    // odd palidrome
    for(int i = 0; i < s.length(); i++) {
        int mxLen = min(i-0, (int)(s.length()-i)), tmpStart=0, tmpEnd=0;
        for(int j = 1; j <= mxLen; j++) {
            if(s[i-j] != s[i+j]) {
                break;
            }
            tmpStart = i-j;
            tmpEnd = i+j;
        }
        if(tmpEnd-tmpStart > mx) {
            mx = tmpEnd - tmpStart;
            start = tmpStart;
            end = tmpEnd;
        }
    }

    // even palidrome
    for(int i = 0; i < s.length()-1; i++) {
        if(s[i] == s[i+1]) {
            int mxLen = min(i-0, (int)(s.length()-i-1)), tmpStart=0, tmpEnd=0;
            for(int j = 1; j <= mxLen; j++) {
                if(s[i-j] != s[i+1+j]) {
                    break;
                }
                tmpStart = i-j;
                tmpEnd = i+1+j;
            }
            if(tmpEnd-tmpStart > mx) {
                mx = tmpEnd-tmpStart;
                start = tmpStart;
                end = tmpEnd;
            }
        }
    }
    for(int i = start; i <= end; i++) {
        cout << s[i];
    }
    cout << "\n" << (end-start+1) << "\n";
}

int main () {
    cin >> N >> s;
    func(N, s);
}
