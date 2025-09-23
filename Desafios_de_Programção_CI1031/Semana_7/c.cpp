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


void solution(){
	int n, m, c, k;
	cin >> n >> m >> c >> k;

	vector<vector<pair<int, int>>> g(n);
	for (int i=0 ; i<m ; i++) {
		int k1, k2, di;
		cin >> k1 >> k2 >> di;
		g[k1].pb({k2, di});
		g[k2].pb({k1, di});
	}

	vector<int> custo_fixo(c, 0);
	for (int i=c-2 ; i >= 0 ; i--) {
		int custo = 0;
		for (auto& viz : g[i]) {
			if (viz.first == i+1) {
				custo = viz.second;
				break;
			}
		}
		custo_fixo[i] = custo_fixo[i+1] + custo;
	}


	vector<int> dist(n, INF);
	dist[k] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0, k});
	while (!pq.empty()) {
		auto [d, u] = pq.top(); pq.pop();
		if (d > dist[u]) continue;

		if (u < c) {
			dist[c-1] = min(dist[c-1], d + custo_fixo[u]);
			continue;
		}

		for (auto [v, w] : g[u]) {
			if (dist[v] > d + w) {
				dist[v] = d + w;
				pq.push({dist[v], v});
			}
		}
	}

	cout << dist[c-1] << endl;
}

int main() {
    IO io;
	solution();
	return 0;
}











