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

vector<int> rep, rnk, siz;

int ds_find(int u) {
	if (rep[u] != u) rep[u] = ds_find(rep[u]);
	return rep[u];
}
bool ds_union(int u, int v) {
	u = ds_find(u);
	v = ds_find(v);
	if (u == v) return false;
	if (rnk[u] < rnk[v]) swap(u, v);
	if (rnk[u] == rnk[v]) rnk[u]++;
	rep[v] = u;
	siz[u] += siz[v];
	return true;
}

void solution(){
	int n, m, k;
	cin >> n >> m >> k;

	vector<pair<int, int>> edges;
	for (int i=0 ; i<m ; i++) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		if (u > v) swap(u, v);
		edges.pb({u, v});
	}

	vector<pair<int, int>> arrebentados;
	set<pair<int, int>> arrebentados_set;
	for (int i=0 ; i<k ; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		if (u > v) swap(u, v);
		arrebentados.pb({u, v});
		arrebentados_set.insert({u, v});
	}


	rep.resize(n);
	rnk.assign(n,0);
	siz.assign(n,1);
	for (int i=0 ; i<n ; i++) rep[i] = i;

	int comps = n;
	for (auto &e : edges) {
		if (arrebentados_set.count(e)) continue;
		if (ds_union(e.first, e.second)) comps--;
	}

	vector<int> saida;
	for (int i=k-1 ; i>=0 ; i--) {
		saida.pb(comps);
		if (ds_union(arrebentados[i].first, arrebentados[i].second)) comps--;
	}
	reverse(saida.begin(), saida.end());
	for (int v : saida) cout << v << " ";
	cout << endl;

}

int main() {
    IO io;
	solution();
	return 0;
}









