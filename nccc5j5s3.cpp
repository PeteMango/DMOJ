#include <bits/stdc++.h>
using namespace std;
const int MN = 1e4 + 5;
int N, M, s[MN], e[MN];

bool bfs (int start, int end, vector<int> v[]) {
    queue<int> q;
    bool vis[MN];
    memset(vis, false, sizeof(vis));
    vis[start] = true;
    q.push(start);
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        for(int u : v[cur]) {
            if(!vis[u]) {
                q.push(u);
                vis[u] = true;
            }
        }
    }
    if(vis[end]) {
        return true;
    }
    return false;
}

int main () {
    cin >> N >> M;
    for(int i = 1; i <= M; i++) {
        cin >> s[i] >> e[i];
    }
    for(int i = 1; i <= M; i++) {
        vector<int> v[MN];
        for(int j = 1; j <= M; j++) {
            if(j != i) {
                v[s[j]].push_back(e[j]);
            }
        }
        if(bfs(1, N, v)) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
}
