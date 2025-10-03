#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solution() {
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, int>>> g(n);
	for (int i=0 ; i<m ; i++) {
		int k1, k2, dis;
		cin >> k1 >> k2 >> dis;
		g[k1].pb({k2, dis});
		g[k2].pb({k1, dis});
	}

	int resp = INF;
	for(int i=0 ; i<n ; i++) {
		vector<int> dist(n, INF);
		dist[i] = 0;
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		pq.push({0, i});
		while (!pq.empty()) {
			auto[d, u] = pq.top();
			pq.pop();
			if (d > dist[u]) continue;
			for (auto [v, w] : g[u]) {
				if (dist[v] > d+w) {
					dist[v] = d+w;
					pq.push({dist[v], v});
				}
			}
		}
		int maior = *max_element(dist.begin(), dist.end());
		resp = min(resp, maior);
	}
	cout << resp << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	solution();

	return 0;
}
