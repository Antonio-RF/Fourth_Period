#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

using pii = pair<int, ll>;
using ii = pair<int, int>;
const int N = 1e5+15;
const int MAXN = 1e5 + 5;
vector<vector<pii>> g;

#define NEUTRAL 0LL
inline ll OP(ll x, ll y) { return x + y; }

int LOG;
vector<int> depth;
vector<vector<ll>> weiop;
vector<vector<int>> up;

void bl_euler_tour(int u, int p, ll w) {
	up[u][0] = p;
	weiop[u][0] = w;
	if (u != p) depth[u] = depth[p] + 1;
	for (auto &ed : g[u]) {
		int v = ed.first;
		ll we = ed.second;
		if (v == p) continue;
		bl_euler_tour(v, u, we);
	}
}

void bl_init(int root, int n) {
    LOG = 0;
    while ((1 << LOG) <= n) ++LOG;
    depth.assign(n, 0);
    up.assign(n, vector<int>(LOG, root));
    weiop.assign(n, vector<ll>(LOG, NEUTRAL));

    depth[root] = 0;
    bl_euler_tour(root, root, 0);

    for (int k = 1; k < LOG; ++k) {
        for (int v = 0; v < n; ++v) {
            int a = up[v][k-1];
            up[v][k] = up[a][k-1];
            weiop[v][k] = OP(weiop[v][k-1], weiop[a][k-1]);
        }
    }
}

ll bl_op(int a, int b) {
    if (a == b) return NEUTRAL;
    if (depth[a] < depth[b]) swap(a, b);

    ll res = NEUTRAL;
    int diff = depth[a] - depth[b];

    for (int k = 0; k < LOG; ++k) {
        if (diff & (1 << k)) {
            res = OP(res, weiop[a][k]);
            a = up[a][k];
        }
    }

    if (a == b) return res;

    for (int k = LOG - 1; k >= 0; --k) {
        if (up[a][k] != up[b][k]) {
            res = OP(res, OP(weiop[a][k], weiop[b][k]));
            a = up[a][k];
            b = up[b][k];
        }
    }

    res = OP(res, OP(weiop[a][0], weiop[b][0]));
    return res;
}

void solution() {
	ll n;
	cin >> n;
	g.assign(n+1, {});
	for (ll i=0 ; i<n-1 ; i++) {
		int u; ll w;
		int filho = i+1;
		cin >> u >> w;
		g[u].pb({filho, w});
		g[filho].pb({u, w});
	}
	int total = n+1;
	bl_init(0, total);

	int q;
	cin >> q;
	while (q--) {
		int u, v;
		cin >> u >> v;
		cout << bl_op(u, v) << endl;
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	solution();

	return 0;
}

