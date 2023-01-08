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
const int MAXN = 500005, MAXQ = 100005;
ll gcd(ll a, ll b){return b == 0 ? a : gcd(b, a % b);}
ll lcm(ll a, ll b){return a*b/gcd(a,b);}
ll fpow(ll  b, ll exp, ll mod){if(exp == 0) return 1;ll t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}
ll divmod(ll i, ll j, ll mod){i%=mod,j%=mod;return i*fpow(j,mod-2,mod)%mod;}

int T;

void compute (stack<int> s, stack<int> b, int N) {
    int cur=1;
    for(;;) {
        if(cur > N) {
            cout << "Y\n";
            return;
        }
        if(s.top() == cur) {
            s.pop();
            cur++;
        }
        else if(b.top() == cur) {
            b.pop();
            cur++;
        }
        else if(s.top() == 0) {
            cout << "N\n";
            return;
        }
        else {
            b.push(s.top());
            s.pop();
        }
    }
}

int main () {
    cin >> T;
    while(T--) {
        stack<int> tp, b;
        tp.push(0);
        b.push(0);
        int N;
        cin >> N;
        for(int i = 1, x; i <= N; i++) {
            cin >> x;
            tp.push(x);
        }
        compute(tp, b, N);
    }
}
