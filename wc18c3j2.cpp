#include <bits/stdc++.h>
using namespace std;
const int NN = 105;
int N, a[NN];

int main (){
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> a[i];
    }
    sort(a+1, a+N+1);
    for(int i = N; i >= 0; i--){
        if(i == 0) {
            cout << 0 << endl;
            return 0;
        }
        else if(a[i] <= 100) {
            if(i == 1) {
                cout << a[i] << endl;
            }
            else {
                cout << a[i]+a[i-1] << endl;
            }
            return 0;
        }
    }
}
