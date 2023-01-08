#include <iostream>
#include <utility>
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
const int MAXN = 105, MAXQ = 100005;
ll gcd(ll a, ll b){return b == 0 ? a : gcd(b, a % b);}
ll lcm(ll a, ll b){return a*b/gcd(a,b);}
ll fpow(ll  b, ll exp, ll mod){if(exp == 0) return 1;ll t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}
ll divmod(ll i, ll j, ll mod){i%=mod,j%=mod;return i*fpow(j,mod-2,mod)%mod;}


/*
let boolean value determine the direction of turning:
 
true = left
false = right
*/

/*
57234 did not store the instructions for this case
00123
*/

bool calculateInstruction (int x, bool prevInstruction) {
    int firstDigit = x/10000, secondDigit = (x/1000)%10;
    if(firstDigit + secondDigit == 0) {
        return prevInstruction;
    }
    else if((firstDigit + secondDigit) % 2 == 0) {
        return false;
    }
    return true;
}

int calculateDistance (int x) {
    int firstDigit = x/10000, secondDigit = (x/1000)%10;
    return (x - (10000 * firstDigit + 1000 * secondDigit));
}

int N;
bool prevInstruction = NULL, curInstruction = NULL;
int main() {
    cin >> N;
    prevInstruction = calculateInstruction(N, prevInstruction);
    if(prevInstruction == true) {
        cout << "left " << calculateDistance(N) << endl;
    }
    else cout << "right " << calculateDistance(N) << endl;
    
    while(N != 99999) {
        cin >> N;
        if(N == 99999) break;
        curInstruction = calculateInstruction(N, prevInstruction);
        if(curInstruction == true) {
            cout << "left " << calculateDistance(N) << endl;
        }
        else cout << "right " << calculateDistance(N) << endl;
        prevInstruction = curInstruction;
    }
}
