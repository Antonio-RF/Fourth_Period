#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

list<ll> l;
ll iterador = 0;

void solution() {

	char comando;
	cin >> comando;

	if (comando == 'i') {
		ll q, t;
		cin >> q >> t;
		auto it = l.begin();
		advance(it, iterador);
		for (ll i=0 ; i<q ; i++) {
			l.insert(it, t);
		}
	}
	else if (comando == 'm') {
		ll qntd;
		cin >> qntd;
		iterador += qntd;
	}
	else if (comando == 'd') {
		auto it = l.begin();
		advance(it, iterador);
		it = l.erase(it);
	}
	else if (comando == 'q') {
		auto it = l.begin();
		advance(it, iterador);
		cout << *it << endl;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	ll t;
	cin >> t;
	while(t--)
		solution();
 
	return 0;
}

