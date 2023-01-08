#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int MM = 1e5 + 5, INF = 0x3f3f3f3f;
int N, M;
vector<pii> v[MM];

void dijkstra (int s, int e) {
    pii d[MM];
    for(int i = 1; i <= N; i++) {
        d[i].second = INF;
    }
    queue<pii> q;
    q.push({1, 0});
    d[1].first=0;
    d[1].second=0;
    while(!q.empty()) {
        int cur = q.front().first;
        q.pop();
        for(pii u : v[cur]) {
            int newNode = u.first, type = u.second;
            if(type == 1) { // dangerous
                if(d[cur].second + 1 < d[newNode].second) { // unvisited
                    d[newNode].second = d[cur].second + 1;
                    d[newNode].first = d[cur].first + 1;
                    q.push(u);
                }
                else { // visited
                    if(d[cur].first + 1 < d[newNode].first) {
                        d[newNode].second = d[cur].second + 1;
                        d[newNode].first = d[cur].first + 1;
                        q.push(u);
                    }
                }
            }
            else { // safe
                if(d[newNode].second == INF) { // unvisited
                    d[newNode].first = d[cur].first + 1;
                    d[newNode].second = d[cur].second;
                    q.push(u);
                }
                else { // visited
                    if(d[cur].second < d[newNode].second) {
                        d[newNode].second = d[cur].second;
                        d[newNode].first = d[cur].first + 1;
                        q.push(u);
                    }
                }
            }
        }
    }
//    for(int i = 1; i <= N; i++) {
//        cout << d[i].first << " " << d[i].second << endl;
//    }
    if(d[N].second != INF) {
        cout << d[N].second << " " << d[N].first << "\n";
    }
    else {
        cout << -1 << "\n";
    }
}

int main () {
    cin >> N >> M;
    for(int i = 1, x, y, z; i <= M; i++) {
        cin >> x >> y >> z;
        if(x == y) continue;
        v[x].emplace_back(y, z);
        v[y].emplace_back(x, z);
    }
    dijkstra(1, N);
}
