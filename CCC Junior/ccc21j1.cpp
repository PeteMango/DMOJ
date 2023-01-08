#include <bits/stdc++.h>
using namespace std;

int B, P;

int main () {
    cin >> B;
    P = 5 * B - 400;
    if(P == 100) {
        cout << P << "\n" << "0\n";
    }
    else if(P > 100) {
        cout << P << "\n" << "-1\n";
    }
    else {
        cout << P << "\n" << "1\n";
    }
}
