#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
typedef long long ll;
 
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int n, m;
ll t;
vector<vector<int>> grid;
int dr[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dc[8] = {0, 1, 0, -1, 1, 1, -1, -1}; //(S, E, N, E, SE, NE, NW, SW)

void solution() {
	cin >> n >> m >> t;
	grid.assign(n, vector<int>(m));
	vector<vector<ll>> queimado(n, vector<ll>(m, -1));
	vector<vector<int>> cnt(n, vector<int>(m, 0));
	queue<tuple<int, int, ll>> q;

	for (int i=0; i<n ; i++) {
		for (int j=0 ; j<m ; j++) {
			cin >> grid[i][j];
			if (grid[i][j] == 0) {
				queimado[i][j] = 0;
				q.emplace(i, j, 0);
			}
		}
	}

	while (!q.empty()) {
		auto[r, c, tempo] = q.front();
		q.pop();
		if (tempo == t) continue;
		for (int k=0 ; k<8 ; k++) {
			int nr = r + dr[k];
			int nc = c + dc[k];
			if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
			if (queimado[nr][nc] != -1) continue;
			if (grid[nr][nc] == 1) {
				queimado[nr][nc] = tempo+1;
				q.emplace(nr, nc, tempo+1);
			}
		}
		for (int k=0 ; k<4 ; k++) {
			int nr = r+dr[k];
			int nc = c+dc[k];
			if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
			if (queimado[nr][nc] != -1) continue;
			if (grid[nr][nc] == 2) {
				cnt[nr][nc]++;
				if (cnt[nr][nc] >= 1) {
					queimado[nr][nc] = tempo+1;
					q.emplace(nr, nc, tempo+1);
				}
			}
			if (grid[nr][nc] == 3) {
				cnt[nr][nc]++;
				if (cnt[nr][nc] >= 2) {
					queimado[nr][nc] = tempo+1;
					q.emplace(nr, nc, tempo+1);
				}
			}
			if (grid[nr][nc] == 4) {
				cnt[nr][nc]++;
				if (cnt[nr][nc] >= 3) {
					queimado[nr][nc] = tempo+1;
					q.emplace(nr, nc, tempo+1);
				}
			}
		}
	}

	ll resp = 0;
	for (int i=0 ; i<n ; i++) {
		for (int j=0 ; j<m ; j++) {
			if (queimado[i][j] != -1 && queimado[i][j] <= t)
				resp++;
		}
	}

	cout << resp << endl;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	solution();
 
	return 0;
}

