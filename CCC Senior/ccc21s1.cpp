#include <bits/stdc++.h>
using namespace std;

const int MM = 10005;
int N;
double area=0.0, h[MM], w[MM];

int main () {
    cin >> N;
    for(int i = 1; i <= N+1; i++) {
        cin >> h[i];
    }
    for(int i = 1; i <= N; i++) {
        cin >> w[i];
    }
    for(int i = 1; i <= N; i++) {
        double cur = 0.5*(h[i]+h[i+1])*w[i];
        area += cur;
    }
    cout << fixed;
    cout << setprecision(1);
    cout << area << "\n";
}
