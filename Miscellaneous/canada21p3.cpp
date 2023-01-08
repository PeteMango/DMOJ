#include <bits/stdc++.h>
using namespace std;
int T;

string moveDig (string s, int K) {
    vector<char> q;
    if(K >= s.length()) {
        for(int i = 0; i < s.length(); i++) {
            q.push_back(s[i]);
        }
        sort(q.begin(), q.end());
        string tmp = "";
        for(int i = 0; i < q.size(); i++) {
            tmp.push_back(q[i]);
        }
        return tmp;
    }
    for(int x = 1; x <= K; x++) {
        bool f = false;
        for(int j = 0; j < s.length() - 1; j++) {
            if(s[j] - '0' > s[j + 1] - '0') {
                q.insert(q.begin(), s[j]);
//                cout << "Before Erase: " << s << "\n";
                s.erase(j, 1);
//                cout << "After Erase: " << s << "\n";
                f = true;
                break;
            }
        }
        if(!f && s.length() >= 0) {
            q.insert(q.begin(), s[s.length()-1]);
            s = s.substr(0, s.size() - 1);
        }
    }
    sort(q.begin(), q.end());
    for(int i = 0; i < q.size(); i++) {
        s.push_back(q[i]);
    }
    return s;
}

void testEraseFunc (string s) {
    cout << "Erased: " << s.erase(0, 1) << "\n";
    s.push_back('8');
    cout << "Push Back: " << s << "\n";
}

int main () {
    cin >> T;
//    testEraseFunc("891");
    for(int i = 1, K; i <= T; i++){
        string s;
        cin >> s >> K;
        cout << moveDig(s, K) << "\n";
    }
}
