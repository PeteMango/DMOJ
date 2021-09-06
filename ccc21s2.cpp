#include <bits/stdc++.h>
using namespace std;
int M, N, K, fR=0, fC=0, sum=0;
vector<int> R, C;
unordered_map<int, int> row, col;

void countFreq (vector<int> R, vector<int> C) {
    for(int i = 0; i < R.size(); i++) {
        row[R[i]]++;
    }
    for(int i = 0; i < C.size(); i++) {
        col[C[i]]++;
    }
}

int main () {
    cin >> M >> N >> K;
    for (int i = 1; i <= K; i++) {
        char c;
        int x;
        cin >> c >> x;
        if (c == 'R') {
            R.push_back(x);
        } else C.push_back(x);
    }
    sort(R.begin(), R.end());
    sort(C.begin(), C.end());
    countFreq(R, C);
    for(auto i:row) {
        if(i.second % 2 != 0) fR++;
    }
    for(auto i:col) {
        if(i.second % 2 != 0) fC++;
    }
    sum += max(0, N*fR + M*fC - 2*(fR*fC));
    sum = min(N*M, sum);
    cout << sum << "\n";
}
