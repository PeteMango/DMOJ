#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5 + 5;
int N;
vector<pair<int, string>> v;

int main () {
    cin >> N;
    for(int i = 1; i <= N; i++) {
        string s; int x;
        cin >> s >> x;
        v.push_back({x, s});
    }
    sort(v.begin(), v.end());
    cout << v[N/2].second << "\n";
}
