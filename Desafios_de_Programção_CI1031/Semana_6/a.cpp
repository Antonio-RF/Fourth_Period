#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<vector<int>> g;
vector<bool> visited;

int explore(int u) {
	if (visited[u])
		return 0;

	stack<int> s;
	s.push(u);
	visited[u] = true;

	while (!s.empty()) {
		int cur = s.top();
		s.pop();
		for (int v : g[cur]) {
			if (!visited[v]) {
				visited[v] = true;
				s.push(v);
			}
		}
	}
	return 1;
}
void solution() {
	int n, m;
	cin >> n >> m;
	g.resize(n);
	visited.resize(n, false);
	for (int i=0 ; i<m ; i++) {
		int a1, a2;
		cin >> a1 >> a2;
		g[a1].pb(a2);
		g[a2].pb(a1);
	}

	int resp = 0;
	for (int i=0 ; i<n ; i++) resp += explore(i);
	cout << resp << endl;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	solution();
 
	return 0;
}

