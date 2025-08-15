#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
typedef long long ll;
 
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solution() {
	int tam;
	cin >> tam;

	vector<ll> v(2e5+5, LLONG_MIN);
	bool deu = true;
	for (int i=0 ; i<tam ; i++) {
		ll k;
		int u;
		cin >> k >> u;
		if (v[u] != LLONG_MIN) {
			if (k >= v[u]) {
				v[u] = k;
				continue;
			}
			else {
				deu = false;
			}
		}
		v[u] = k;
	}

	if (deu)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	solution();
 
	return 0;
}

