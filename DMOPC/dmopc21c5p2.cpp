#include <bits/stdc++.h>
using namespace std;
int N;
vector <int> v;

int main () {
    cin >> N;
    if(N == 1) {
        cout << 1 << endl;
        return 0;
    }
    else if(N == 3) {
        cout << "1 3 2\n";
        return 0;
    }
    else if(N == 4) {
        cout << "1 3 2 4\n";
        return 0;
    }
    else if(N == 2) {
        cout << "-1\n";
        return 0;
    }
    v.push_back(4); v.push_back(5);
    for(int i = 1; i <= N; i++) {
        if(i != 5 && i != 4) {
            v.push_back(i);
        }
    }
    for(int i = 0; i < v.size(); i++) {
        if(i == N-1) {
            cout << v[i] << endl;
            return 0;
        }
        else {
            cout << v[i] << ' ';
        }
    }
}
