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

const int N = 1e5 + 5;
vector<vector<int>> g;
vector<int> dfs_num, dfs_low, dfs_parent, articulation_vertex;
int dfsNumberCounter, dfsRoot, rootChildren, bridgesCount;
vector<pair<int, int>> bridges;
void articulationPointAndBridge(int u) {
	dfs_low[u] = dfs_num[u] = dfsNumberCounter++;

	for (int v: g[u]) {
		if (dfs_num[v] == -1) {
			dfs_parent[v] = u;
			if (u == dfsRoot) rootChildren++;

			articulationPointAndBridge(v);

			if (dfs_low[v] >= dfs_num[u])
				articulation_vertex[u] = true;
			if (dfs_low[v] > dfs_num[u])
				bridgesCount++;

			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		}
		else if (v != dfs_parent[u])
			dfs_low[u] = min(dfs_low[u], dfs_num[v]);
	}
}

void solution(){
	int n, m;
	cin >> n >> m;
	g.assign(n, {});
	while(m--) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	dfsNumberCounter = 0; 
	dfs_num.assign(n, -1); 
	dfs_low.assign(n, 0); 
	dfs_parent.assign(n,-1); 
	articulation_vertex.assign(n, 0);
	
	bridgesCount = 0;
	for (int i=0 ; i<n ; i++) {
		if (dfs_num[i] == -1)
			articulationPointAndBridge(i);
	}
	cout << bridgesCount << endl;
}

int main() {
    IO io;
	int T = 1;
	cin >> T;
	while(T--)
		solution();
	return 0;
}









