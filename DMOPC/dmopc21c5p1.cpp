#include <bits/stdc++.h>
using namespace std;
int N;
vector<int> v;

int main () {
    cin >> N;
    if(N == 2 || N == 4 || N == 3) {
        cout << -1 << "\n";
    }
    else if(N == 1) {
        cout << 1 << "\n";
    }
    else {
        for(int i = 1; i <= N; i+=2) {
            if(i == 5) continue;
            v.push_back(i);
        }
        v.push_back(5);
        v.push_back(4);
        for(int i = 2; i <= N; i+=2) {
            if(i == 4) continue;
            v.push_back(i);
        }
        for(int i = 0; i < v.size(); i++) {
            if(i != v.size()-1) cout << v[i] << " ";
            else cout << v[i] << "\n";
        }
    }
}
