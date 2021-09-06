#include <bits/stdc++.h>
using namespace std;
vector<string> instructions;

bool f (string s) {
    string tp = s.substr(0, 2);
    int sum = (tp[0] - '0' + tp[1] - '0');
    if(sum % 2 == 0) {
        return true;
    }
    return false;
}

bool func (string s, bool prev) {
    string tp = s.substr(0, 2);
    int sum = (tp[0] - '0' + tp[1] - '0');
    if(tp == "00") {
        return prev;
    }
    else if(sum % 2 == 0) {
        return true;
    }
    return false;
}

int main () {
    while(true) {
        string x;
        cin >> x;
        if(x == "99999") {
            break;
        }
        else instructions.push_back(x);
    }
    bool prev = f(instructions[0]);
    for(int i = 0; i < instructions.size(); i++) {
//        cout << instructions[i] << "\n";
        bool cur = func(instructions[i], prev);
        prev = cur;
        if(cur) {
            cout << "right " <<instructions[i].substr(2, 5) << "\n";
        }
        else {
            cout << "left " << instructions[i].substr(2, 5) << "\n";
        }
    }
}
