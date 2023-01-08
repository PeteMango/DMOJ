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
const int MAXN = 2e3 + 5, MAXQ = 100005;
ll gcd(ll a, ll b){return b == 0 ? a : gcd(b, a % b);}
ll lcm(ll a, ll b){return a*b/gcd(a,b);}
ll fpow(ll  b, ll exp, ll mod){if(exp == 0) return 1;ll t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}
ll divmod(ll i, ll j, ll mod){i%=mod,j%=mod;return i*fpow(j,mod-2,mod)%mod;}

int a, b, c, T1, T2, T3;

int main () {
    cin >> a >> b >> c;
    T1 = a+b;
    T2 = a+2*b;
    T3 = a+3*b;
    if(T3 < c) {
        cout << "Who knows...\n";
    }
    else if(c <= T3 && c > T2) {
        cout << T3 << "\n";
    }
    else if(c <= T2 && c > T1) {
        cout << T2 << "\n";
    }
    else {
        cout << T1 << "\n";
    }
}
