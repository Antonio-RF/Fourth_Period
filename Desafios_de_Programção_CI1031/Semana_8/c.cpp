#include <bits/stdc++.h>
using namespace std;

// Tipos básicos
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi = vector<int>;
using vll = vector<ll>;

// Constantes comuns
const int INF = 1e9+7;
const ll LINF = 1e18;
const int MOD = 1e9+7;

// Direções para grafos/grelhas
const int dx4[4] = {-1,0,1,0};
const int dy4[4] = {0,1,0,-1};

const int dx8[8] = {-1,-1,-1,0,0,1,1,1};
const int dy8[8] = {-1,0,1,-1,1,-1,0,1};

// Macros rápidos
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define f first
#define s second

// Fast I/O
struct IO {
	IO() {
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
	}
} io;


void solution(){
	ll a, b, n;
    cin >> a >> b >> n;
    vector<ll> x(n);
    for (int i = 0; i < n; i++) cin >> x[i];
    ll total = b - a + 1;

    ll res = 0;

    for (int mask = 1; mask < (1<<n); mask++) {
        ll lcm = 1;
        bool ok = true;
        int bits = __builtin_popcount(mask);
        for (int i=0; i<n; i++) {
            if (mask & (1<<i)) {
                ll g = __gcd(lcm, x[i]);
                if (lcm > b / (x[i] / g)) {
                    ok = false;
                    break;
                }
                lcm = lcm * (x[i] / g);
            }
        }
        if (!ok || lcm == 0) continue;
        ll cnt = b/lcm - (a-1)/lcm;
        if (bits % 2 == 1) res += cnt;
        else res -= cnt;
    }
    cout << total - res << endl;
}

int main() {
    IO io;
	solution();
	return 0;
}









