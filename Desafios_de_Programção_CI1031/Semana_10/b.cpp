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

#include <bits/stdc++.h>
using namespace std;

int solution() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> graph(N + 1);
    vector<int> inDegree(N + 1, 0);

    for (int i = 0; i < M; i++) {
        int U, V;
        cin >> U >> V;
        graph[U].push_back(V);
        inDegree[V]++;
    }

	vector<int> sources;
    for (int i = 1; i <= N; i++) {
        if (inDegree[i] == 0) {
            sources.push_back(i);
        }
    }

    if (sources.size() <= 1) {
        return 0;
    }

    vector<int> sourceInfo(N + 1, 0);
    queue<int> q;

    for (int src : sources) {
        sourceInfo[src] = src;
        q.push(src);
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : graph[u]) {
            if (sourceInfo[v] == 0) {
                sourceInfo[v] = sourceInfo[u];
                q.push(v);
            } else if (sourceInfo[v] != sourceInfo[u] && sourceInfo[v] != -1) {
                sourceInfo[v] = -1;
                q.push(v);
            }
        }
    }

    int count = 0;
    for (int i = 1; i <= N; i++) {
        if (sourceInfo[i] == -1) {
            count++;
        }
    }

    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << solution() << endl;
    return 0;
}
