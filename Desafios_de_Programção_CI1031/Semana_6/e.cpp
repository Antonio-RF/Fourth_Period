#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<vector<ll>> g;
vector<bool> visited;
vector<bool> certo;
ll n;

ll explore(ll u) {
	visited[u] = true;
	ll c=1;
	for (ll v: g[u]) {
		ll aux = 0;
		if (!visited[v]) {
			aux = explore(v);
			c += aux;
		}
		if (aux > floor(n/2))
			certo[u] = false;
	}
	ll resu = n-c;
	if (resu > floor(n/2)) {
		/*cout << "entrou" << endl;
		cout << "u: " << u << endl;
		cout << "resu: " << resu << " c: " << c << endl;*/
		certo[u] = false;
	}
	return c;
}

void solution() {
	cin >> n;
	g.assign(n+1, {});
	visited.assign(n+1, false);
	certo.assign(n+1, true);

	for (int i=0 ; i<n-1 ; i++) {
		ll a1, a2;
		cin >> a1 >> a2;
		g[a1].pb(a2);
		g[a2].pb(a1);
	}

	explore(1);
	for (ll i=1 ; i<n+1 ; i++) {
		if (certo[i]) {
			cout << i << endl;
			break;
		}
	}

	/*for (int i=0 ; i<certo.size() ; i++) {
		cout << certo[i] << " ";
	}*/
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	solution();

	return 0;
}
