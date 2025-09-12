#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
typedef long long ll;
 
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<vector<ll>> g;

pair<ll, ll> bfs(ll start, ll n) {
	vector<ll> dist(n+1, -1);
	queue<ll> q;
	q.push(start);
	dist[start] = 0;
	ll farthest = start;

	while (!q.empty()) {
		ll u = q.front();
		q.pop();
		for (ll v : g[u]) {
			if (dist[v] == -1) {
				dist[v] = dist[u] + 1;
				q.push(v);
				if (dist[v] > dist[farthest])
					farthest = v;
			}
		}
	}
	return {farthest, dist[farthest]};
}

void solution() {
	ll n;
	cin >> n;
	g.assign(n+1, {});
	for (int i=0 ; i<n-1 ; i++) {
		ll a1, a2;
		cin >> a1 >> a2;
		g[a1].pb(a2);
		g[a2].pb(a1);
	}

	auto [u, _] = bfs(1, n);
	auto [v, resp] = bfs(u, n);
	cout << resp << endl;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	solution();
 
	return 0;
}

