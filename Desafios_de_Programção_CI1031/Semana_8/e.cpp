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
#define endl '\n'

// Fast I/O
struct IO {
	IO() {
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
	}
} io;

vector<ll> primes;
bitset<10000010> bs;
ll _sieve_size_;
/*
void sieve(ll limit) {
    vector<bool> is_prime(limit + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (ll i = 2; i <= limit; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (ll j = i * i; j <= limit; j += i)
                is_prime[j] = false;
        }
    }
}*/

void sieve(ll upperbound) {
	_sieve_size_ = upperbound + 1;
	bs.set();
	bs[0] = bs[1] = 0;
	for (ll i=2 ; i<= _sieve_size_ ; i++) if (bs[i]) {
		for (ll j = i*i ; j<= _sieve_size_ ; j+= i) bs[j] = 0;
		primes.pb((int)i);
	}
}

void solution(){
	int t;
	cin >> t;
	sieve(2000000);
	while(t--) {
		ll n, k;
		cin >> n >> k;
		ll resp = 0;

		int i =0, j=0;


		ll prod = 1;
		for (j=0 ; j<k ; j++)
			prod *= primes[j];

		resp = prod;

		while(true) {
			prod /= primes[i];
			if (j >= primes.size()) break;
			prod *= primes[j];
			i++;
			j++;

			if (prod > n) break;
			resp = prod;
		}

		cout << resp << endl;
	}
}

int main() {
    IO io;
	solution();
	return 0;
}









