#include <bits/stdc++.h>
using namespace std;

const int oo = 987654321;
const int MAX = 1e5+15;

vector<vector<int>> G (MAX);
vector<set<int>> CG (MAX);

int cts = 0;
vector<int> id (MAX), lowlink (MAX);
vector<int> rep (MAX), visited (MAX);
vector<bool> on_stack (MAX);
vector<int> topo_components;
stack<int> S;
int nxtid = 0;
vector<int> indeg (MAX), indegc (MAX), indegcsrc (MAX, -1);

vector<int> cnt (MAX);

void tarjan_dfs (int u) {
    if (visited[u] == cts) { return; }
    visited[u] = cts;
    S.push(u); on_stack[u] = true;
    id[u] = lowlink[u] = nxtid++;

    for (int v : G[u]) {
        tarjan_dfs(v);
        if (on_stack[v]) {
            lowlink[u] = min(lowlink[u], lowlink[v]);
        }
    }

    cnt[u] = 0;
    if (id[u] == lowlink[u]) {
        int v;
        do {
            v = S.top(); S.pop();
            on_stack[v] = false;
            lowlink[v] = id[u];
            rep[v] = u;
            cnt[u]++;
        } while (v != u);
        topo_components.push_back(u);
    }
}

vector<int> tarjan (int n) {
    cts++;
    nxtid = 0;
    topo_components.clear();
    for (int u = 0; u < n; u++) {
        tarjan_dfs(u);
    }
    reverse(topo_components.begin(), topo_components.end());
    return topo_components;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    while (m--) {
        int u, v; cin >> u >> v; u--; v--;
        G[u].push_back(v);
        indeg[v]++;
    }
    vector<int> S = tarjan(n);

    for (int u = 0; u < n; u++) if (indeg[u] == 0) {
        indegc[u] = 1;
        indegcsrc[u] = u;
    }

    for (int u = 0; u < n; u++) {
        for (int v : G[u]) if (rep[u] != rep[v]) {
            CG[rep[u]].insert(rep[v]);
        }
    }

    for (int u : S) {
        for (int v : CG[u]) {
            if (indegc[rep[u]] == 1 && indegc[rep[v]] == 1 && indegcsrc[rep[u]] == indegcsrc[rep[v]]) { continue; }
            indegc[rep[v]] += indegc[rep[u]];
            indegcsrc[rep[v]] = indegcsrc[rep[u]];
        }
    }

    int ans = 0;
    for (int u : S) if (indegc[rep[u]] > 1) {
        ans += cnt[rep[u]];
    }
    cout << ans << "\n";
}
