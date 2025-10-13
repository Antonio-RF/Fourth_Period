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
const ll PHI = MOD - 1;

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
#define endl '\n'

// Fast I/O
struct IO {
	IO() {
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
	}
} io;

long long mod_pow(long long base, long long exp, long long mod) {
	long long res = 1;
	base %= mod;
	while (exp > 0) {
		if (exp & 1) res = res * base % mod;
		base = base * base % mod;
		exp >>= 1;
	}
	return res;
}

long long mod_inv(long long a, long long mod) {
    return mod_pow(a, mod-2, mod);
}

void solution() {
    int t;
    cin >> t;

	vector<ll> primes(t), powers(t);
	for (int i=0 ; i<t ; i++) {
		cin >> primes[i] >> powers[i];
	}

	ll num_div = 1;
	for (int i=0 ; i<t ; i++)
		num_div = num_div * (powers[i] + 1) % MOD;

	ll sum_div = 1;
	for (int i=0 ; i<t ; i++) {
		ll p = primes[i], k = powers[i];
		ll numerator = (mod_pow(p, k+1, MOD) - 1 + MOD) % MOD;
		ll denominator = (p - 1 + MOD) % MOD;
		sum_div = sum_div * numerator % MOD * mod_inv(denominator, MOD) % MOD;
	}

	ll prod_div = 1;


    ll num_div_mod_2phi = 1;
    for (int i = 0; i < t; i++) {
        num_div_mod_2phi = num_div_mod_2phi * ((powers[i] + 1) % (2 * PHI)) % (2 * PHI);
    }
    
    bool num_div_is_even = false;
    for (int i = 0; i < t; i++) {
        if (powers[i] % 2 == 1) {
            num_div_is_even = true;
            break;
        }
    }
    
   if (!num_div_is_even) {
        for (int i = 0; i < t; i++) {
            ll p = primes[i], k = powers[i];
            ll exp = (k % (2 * PHI)) * (num_div_mod_2phi) % (2 * PHI);
            exp = (exp + 1) % (2 * PHI);
            exp = exp / 2;
			prod_div = prod_div * mod_pow(p, exp, MOD) % MOD;
        }
    } else {

        for (int i = 0; i < t; i++) {
            ll p = primes[i], k = powers[i];
            ll exp = (k % (2 * PHI)) * (num_div_mod_2phi) % (2 * PHI);
            exp = exp / 2; 
            prod_div = prod_div * mod_pow(p, exp, MOD) % MOD;
        }
    }

	cout << num_div << " " << sum_div << " " << prod_div << endl;

}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solution();
}








