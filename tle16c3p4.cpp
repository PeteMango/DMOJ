#include <bits/stdc++.h>
using namespace std;
int a, b;

int main() {
    cin >> a >> b;
    if((a+b)%2 == 1 || a == 1 || b == 1) {
        cout << "First\n";
    }
    else {
        cout << "Second\n";
    }
}
