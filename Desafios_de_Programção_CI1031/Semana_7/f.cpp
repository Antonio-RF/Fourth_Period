#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pli;
const ll INF = 1e18;

void solution() {
    ll n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> g(n);
    vector<tuple<int, int, int>> trilhas;

    for (int i = 0; i < m; i++) {
        int k1, k2, dis;
        cin >> k1 >> k2 >> dis;
        g[k1].emplace_back(k2, dis);
        g[k2].emplace_back(k1, dis);
        trilhas.emplace_back(k1, k2, dis);
    }


    vector<ll> dist0(n, INF);
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    dist0[0] = 0;
    pq.push({0, 0});
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist0[u]) continue;
        for (auto [v, w] : g[u]) {
            if (dist0[v] > dist0[u] + w) {
                dist0[v] = dist0[u] + w;
                pq.push({dist0[v], v});
            }
        }
    }


    vector<ll> distP(n, INF);
    distP[n-1] = 0;
    pq.push({0, n-1});
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > distP[u]) continue;
        for (auto [v, w] : g[u]) {
            if (distP[v] > distP[u] + w) {
                distP[v] = distP[u] + w;
                pq.push({distP[v], v});
            }
        }
    }

    ll minDist = dist0[n-1];
    ll resp = 0;
    for (auto [a, b, l] : trilhas) {
        if (dist0[a] + l + distP[b] == minDist ||
            dist0[b] + l + distP[a] == minDist) {
            resp += l;
        }
    }
    cout << resp * 2 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solution();

    return 0;
}
