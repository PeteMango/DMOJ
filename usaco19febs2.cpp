#include <bits/stdc++.h>
using namespace std;
const int MM = 1005;
int N, K, cnt=0, a[MM][MM], d[MM][MM];

void updateDifference (int x1, int y1, int x2, int y2) {
    for(int i = x1; i < x2; i++) {
        d[i][y1]++;
        d[i][y2]--;
    }
}

void convertDifferenceArray () {
    for(int i = 0; i < MM; i++) {
        for(int j = 0; j < MM; j++) {
            if(j == 0) {
                a[i][j] = d[i][j];
            }
            else {
                a[i][j] = d[i][j] + a[i][j-1];
            }
        }
    }
}

int main () {
    cin >> N >> K;
    for(int i = 1, x1, y1, x2, y2; i <= N; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        updateDifference(x1, y1, x2, y2);
    }
    convertDifferenceArray();
    for(int i = 0; i < MM; i++) {
        for(int j = 0; j < MM; j++) {
            if(a[i][j] == K) {
                cnt++;
            }
//            cout << a[i][j] << " ";
        }
//        cout << "\n";
    }
    cout << cnt << "\n";
}
