#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

ll _sieve_size_;
bitset<10000010> bs;
vector<int> primes;

void sieve(ll upperbound) {
	_sieve_size_ = upperbound + 1;
	bs.set();
	bs[0] = bs[1] = 0;
	for (ll i=2 ; i<= _sieve_size_ ; i++) if (bs[i]) {
		for (ll j = i*i ; j<= _sieve_size_ ; j+= i) bs[j] = 0;
		primes.pb((int)i);
	}
}
bool isPrime(ll n) {
	if (n <= _sieve_size_) return bs[n];
	for (int i=0 ; i< (int)primes.size() ; i++)
		if (n % primes[i] == 0) return false;
	return true;
}

void solution() {
	ll n;
	cin >> n;
	sieve(n);

	ll i=0;
	ll j = primes.size()-1;
	ll resp = 0;
	while (i < j) {
		int soma = primes[i]+primes[j];
		if (soma == n) {
			resp++;
			i++;
			j--;
		}
		else if (soma < n) i++;
		else j--;
	}


	if (n % 2 == 0 && isPrime(n/2))
		resp++;

	cout << resp << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	solution();

	return 0;
}
