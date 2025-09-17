#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
typedef long long ll;
 
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int dr[8] = {-1,1,0,0};
int dc[8] = {0,0,-1,1};
string dir[8] = {"U", "D", "L", "R"};

vector<vector<char>> grid;
vector<vector<int>> visited;
vector<vector<pair<int, int>>> pais;
int R, C;


void solution() {
	cin >> R >> C;
	grid.assign(R, vector<char>(C));

	pair<int, int> A, B;
	for (int i = 0; i < R; i++) {
		string line;
		cin >> line;
		for (int j = 0; j < C; j++) {
			grid[i][j] = line[j];
			if (grid[i][j] == 'A') A = {i, j};
			if (grid[i][j] == 'B') B = {i, j};
		}
	}

	visited.assign(R, vector<int>(C, false));
	pais.assign(R, vector<pair<int, int>> (C, {-1,-1}));
	queue<pair<int, int>> q;
	q.push({A.first, A.second});
	while (!q.empty()) {
		auto[r, c] = q.front();
		q.pop();
		if (make_pair(r, c) == B) break;
		for (int d=0 ; d<4 ; d++) {
			int nr = r + dr[d];
			int nc = c + dc[d];
			if ((nr >= 0 && nr < R && nc >= 0 && nc < C) && !visited[nr][nc] && grid[nr][nc] != '#') {
				visited[nr][nc] = true;
				pais[nr][nc] = {r, c};
				q.push({nr, nc});
			}
		}
	}

	if (!visited[B.first][B.second]) {
		cout << "NO" << endl;
	}
	else {
		cout << "YES" << endl;

		string caminho;
		pair<int, int> c = B;
		while (c != A) {
			pair<int, int> pai = pais[c.first][c.second];
			for (int d=0 ; d<4 ; d++) {
				if (pai.first + dr[d] == c.first && pai.second + dc[d] == c.second)
					caminho += dir[d];
			}
			c = pai;
		}
		reverse(caminho.begin(), caminho.end());
		cout << caminho.size() << endl << caminho << endl;
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	solution();
 
	return 0;
}

