#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int N, K;
LL prevT, xL, xR, yL, yR, w=0, h=0;

int main () {
    cin >> N >> K;
    cin >> prevT >> xL >> yL;
    xR = xL;
    yR = yL;
    for(int i = 1; i < N; i++) {
        LL curT, x, y;
        cin >> curT >> x >> y;
        LL move = K * (curT - prevT);
        prevT = curT;
        if(x > xR) {
            LL tmp = xR + w + move;
            if(tmp <= x) {
                w += x - tmp;
                xR = x - w;
                xL = xR;
            }
            else {
                xR = min(x, xR + move);
                xL = max(x - w, xL - move);
            }
        }
        else if(x > xL) {
            xR = x;
            xL = max(xL - move, x - w);
        }
        else {
            LL tmp = xL - move;
            if(tmp >= x) {
                w += tmp - x;
                xL = x;
                xR = xL;
            }
            else {
                xL = max(x - w, xL - move);
                xR = x;
            }
        }


        if(y > yR) {
            LL tmp = yR + h + move;
            if(tmp <= y) {
                h += y - tmp;
                yR = y - h;
                yL = yR;
            }
            else {
                yR = min(y, yR + move);
                yL = max(y - h, yL - move);
            }
        }
        else if(y > yL) {
            yR = y;
            yL = max(yL - move, y - h);
        }
        else {
            LL tmp = yL - move;
            if(tmp >= y) {
                h += tmp - y;
                yL = y;
                yR = yL;
            }
            else {
                yL = max(y - h, yL - move);
                yR = y;
            }
        }
    }
    cout << max(w, h) << "\n";
}
