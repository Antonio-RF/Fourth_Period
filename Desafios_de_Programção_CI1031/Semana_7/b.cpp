#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

const int INF = 0x3f3f3f3f;

void solution() {
    int n;
    cin >> n;
    vector<int> li(n+1);
    for (int i = 1; i <= n; i++) cin >> li[i];

    int m;
    cin >> m;
    vector<tuple<int,int,int>> edges;
    for (int i = 0; i < m; i++) {
        int k1, k2;
        cin >> k1 >> k2;
        edges.push_back({k1, k2, li[k2] - li[k1]});
    }


    vector<int> dist(n+1, INF);
    dist[1] = 0;
    for (int i = 1; i < n; i++) {
        for (auto [u, v, w] : edges) {
            if (dist[u] < INF && dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
            }
        }
    }

    vector<bool> neg(n+1, false);
    for (int i = 1; i < n; i++) {
        for (auto [u, v, w] : edges) {
            if (dist[u] < INF && dist[v] > dist[u] + w) {
                dist[v] = -INF;
                neg[v] = true;
            }
            if (neg[u]) neg[v] = true;
        }
    }

    int q;
    cin >> q;
    while(q--) {
        int temp;
        cin >> temp;
        if (dist[temp] == INF || neg[temp]) cout << "Não, Edsger..." << endl;
        else if (dist[temp] >= 3) cout << dist[temp] << endl;
        else cout << "Não, Edsger..." << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solution();

    return 0;
}

