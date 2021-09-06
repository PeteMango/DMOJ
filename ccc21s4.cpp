#include <bits/stdc++.h>
using namespace std;

const int MM = 2e5 + 5, INF = 0x3f3f3f3f;
int N, M, Q, a[MM], dist[MM];
vector<int> adj[MM];
queue<int> q;
multiset<int> s;

void func (int cur, int t, int opt) {
    int x = t + dist[cur];
    if(opt == 0) {
        s.insert(x);
    }
    else {
        s.erase(s.find(x));
    }
}

int main () {
    scanf("%d %d %d", &N, &M, &Q);
    for(int i = 1, u, v; i <= M; i++) {
        scanf("%d %d", &u, &v);
        adj[v].push_back(u);
    }
    memset(dist, INF, sizeof (dist));
    dist[N] = 0;
    q.push(N);
    while(!q.empty()) {
        int cur = q.front(), x = dist[cur]+1;
        q.pop();
        for(auto u : adj[cur]) {
            if(x < dist[u]) {
                dist[u] = x;
                q.push(u);
            }
        }
    }
    for(int i = 1; i <= N; i++) {
        cin >> a[i];
        func(a[i], i-1, 0);
    }
    for(int i = 1, u, v; i <= Q; i++) {
        scanf("%d %d", &u, &v);
        func(a[u], u-1, 1);
        func(a[v], v-1, 1);
        swap(a[u], a[v]);
        func(a[u], u-1, 0);
        func(a[v], v-1, 0);
        cout << *s.begin() << "\n";
    }
}
