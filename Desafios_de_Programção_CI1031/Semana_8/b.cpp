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

ll intPow(long long base, long long exp) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1)
            result *= base;
        base *= base;
        exp /= 2;
    }
    return result;
}



ll _sieve_size_;
bitset<10000010> bs;
vector<int> primes;

void sieve(ll upperbound) {
    _sieve_size_ = upperbound+1;
    bs.set();
    bs[0] = bs[1] = 0;
    for (ll i=2 ; i< _sieve_size_ ; i++) {
        if (bs[i]) {
            for (ll j= i*i ; j<=_sieve_size_ ; j += i) bs[j] = 0;
            primes.pb((int)i);
        }
    }
}

vector<pair<int, int>> factorize(ll N) {
    vector<pair<int,int>> factors;
    for (int i = 0; i < (int)primes.size() && 1LL*primes[i]*primes[i] <= N; ++i) {
        int p = primes[i], cnt = 0;
        while (N % p == 0) {
            N /= p;
            cnt++;
        }
        if (cnt > 0)
            factors.push_back({p, cnt});
    }
    if (N > 1)
        factors.push_back({(int)N, 1});
    return factors;
}

void solution(){
    int t;
    cin >> t;
    sieve(10000000);
    while(t--) {
        ll k;
        cin >> k;
        ll x = 1;
        for (int i=0 ; i<k ; i++) {
            ll p, e;
            cin >> p >> e;
            x *= intPow(p, e);
        }
        x--;
        
        auto factors = factorize(x);
        sort(factors.rbegin(), factors.rend());
        for (auto& f : factors) cout << f.first << " " << f.second << endl;
        
        
	}

}

int main() {
	IO io;
	solution();
	return 0;
}
