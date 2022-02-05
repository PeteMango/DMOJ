/*
 * Maximum Bipartite Matching with Ford Fulkerson Algorithm
 */

#include <bits/stdc++.h>
using namespace std;
const int MM = 1e3 + 5;
int N, M, wnt, match[MM], f[MM];
bool wanted[MM];
vector<int> v[MM];

int bipartie (int x) {
    if(f[x] == 1) {
        return 0;
    }
    f[x] = 1; // mark vis
    for(int u : v[x]) {
        if(match[u] == -1) {
            match[u] = x;
            return 1;
        }
        else if(bipartie(match[u])) {
            match[u] = x;
            return 1;
        }
    }
    return 0;
}

int main () {
    cin >> N >> M;
    memset(match, -1, sizeof(match)); // set all unvisited
    memset(wanted, false, sizeof(wanted)); // wanted
    for(int i = 1, x; i <= N; i++) {
        cin >> x;
        for(int j = 1, t; j <= x; j++) {
            cin >> t;
            if(i == 1) {
                wanted[t] = true;
            }
            else {
                if(!wanted[t]) { // if unwanted skip
                    continue;
                }
            }
            v[i].push_back(t);
        }
    }
    wnt = (int) v[1].size();
    for(int i = 2; i <= N; i++) {
        memset(f, 0, sizeof(f));
        wnt -= bipartie(i);
    }
    cout << wnt << "\n";
}
