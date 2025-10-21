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

const int N = 1e5+15;
int tk = 0; vector<int> tin (N, -1), low (N);
stack<int> st; vector<int> rep (N), onst (N);
vector<int> vis (N); int cts = 1;
vector<vector<int>> g (N);
vector<set<int>> cg (N);

void dfs_tarjan(int u) {
	tin[u] = low[u] = ++tk;
	onst[u] = 1;
	st.push(u);

	for (int v : g[u]) {
		if (tin[v] == -1) {
			dfs_tarjan(v);
			low[u] = min(low[u], low[v]);
		}
		else if (onst[v])
			low[u] = min(low[u], tin[v]);
	}
	if (low[u] == tin[u]) {
		int v;
		do {
			v = st.top(); st.pop(); onst[v] = 0;
			rep[v] = u;
		} while (u != v);
	}
}
void tarjan(int n) {
	tk = 0;
	for (int u = 0; u < n; u++) {
	if (tin[u] == -1)
		dfs_tarjan(u);
	}
}

void solution(){
	int n, m;
	cin >> n >> m;

	g.assign(n, {});
	cg.assign(n, {});
	tin.assign(n, -1);
	low.assign(n, 0);
	rep.assign(n, 0);
	onst.assign(n, 0);

	while (m--) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		g[u].pb(v);
	}

	tarjan(n);

	for (int u = 0; u < n; u++)
		for (int v : g[u])
			if (rep[u] != rep[v])
				cg[rep[u]].insert(rep[v]);

	vector<int> comps;
	for (int u = 0; u < n; u++)
		if (rep[u] == u)
			comps.pb(u);

	int k = comps.size();
	if (k == 1) {
		cout << 0 << endl;
		return;
    }
	
	unordered_map<int,int> indeg, outdeg;
	for (int u : comps) {
		for (int v : cg[u]) {
			outdeg[u]++;
			indeg[v]++;
		}
	}


	int fontes = 0, sumidouros = 0;
	for (int u : comps) {
		if (indeg[u] == 0) fontes++;
		if (outdeg[u] == 0) sumidouros++;
	}
	cout << max(fontes, sumidouros) << endl;
}

int main() {
    IO io;
	solution();
	return 0;
}









