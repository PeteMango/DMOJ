#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define NINF -INF
#define mp make_pair
#define boost() cin.tie(0); cin.sync_with_stdio(0)
#define For(i, a, b) for(int i=a; i<b; i++)
#define FOR(i, a, b) for(int i=a; i<=b; i++)
#define Rev(i, a, b) for(int i=a; i>b; i--)
#define REV(i, a, b) for(int i=a; i>=b; i--)
typedef long long ll;
typedef long double ld;
typedef int64_t l;
typedef pair<int, int> pii;
typedef pair<int, ll> pil;
typedef pair<ll, ll> pll;
const int MOD = 1000000007;
const int MAXN = 1e7 + 5, MAXQ = 100005;
ll gcd(ll a, ll b){return b == 0 ? a : gcd(b, a % b);}
ll lcm(ll a, ll b){return a*b/gcd(a,b);}
ll fpow(ll  b, ll exp, ll mod){if(exp == 0) return 1;ll t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}
ll divmod(ll i, ll j, ll mod){i%=mod,j%=mod;return i*fpow(j,mod-2,mod)%mod;}

int N, mx=-1, mxT=-1, conv[MAXN], D[MAXN];
void update (int L, int R) {
    D[L]++;
    D[R+1]--;
}

void convertBack () {
    for(int i = 1; i <= mxT; i++) {
        if(i == 1) {
            conv[i] = D[i];
        }
        else {
            conv[i] = D[i] + conv[i-1];
        }
    }
}

int main () {
    scanf("%d", &N);
    memset(D, 0, sizeof(D));
    for(int i = 1, s, f; i <= N; i++) {
        cin >> s >> f;
        update(s, f-1);
        if(f > mxT) {
            mxT = f;
        }
    }
    convertBack();
    for(int i = 1; i < mxT; i++) {
        if(conv[i] > mx) {
            mx = conv[i];
        }
    }
//    for(int i = 1; i <= N; i++) {
//        cout << i << ": " << conv[i] << "\n";
//    }
    printf("%d\n", mx);
}
