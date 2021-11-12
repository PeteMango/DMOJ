#include <bits/stdc++.h>
using namespace std;
int N, A, B;

int main () {
    scanf("%d%d%d", &N, &A, &B);
    if(N%2 == 0) {
        printf("%d\n", N/2*(A+B));
    }
    else {
        printf("%d\n", (N/2+1)*A+(N/2)*B);
    }
}
