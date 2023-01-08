#include <bits/stdc++.h>
using namespace std;
struct auc{
    int p;
    string name;
};

bool comp (auc a, auc b) {
    if(a.p == b.p) {
        return a.p;
    }
    return a.p < b.p;
}

const int MM = 105;
int N;
auc a[MM];
int main () {
    scanf("%d", &N);
    for(int i = 1; i <= N; i++) {
        cin >> a[i].name >> a[i].p;
    }
    sort(a+1, a+N+1, comp);
    cout << a[N].name << "\n";
}
