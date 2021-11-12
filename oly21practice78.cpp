#include <bits/stdc++.h>
using namespace std;
const int MM = 105;
int N, sum=0, h=0, c=0, a[MM];

int main () {
    scanf("%d", &N);
    for(int i = 1; i <= N; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    h = round((double)(sum)/(double)(N));
    for(int i = 1; i <= N; i++) {
        c += pow((a[i]-h), 2);
    }
    printf("%d\n", c);
}
