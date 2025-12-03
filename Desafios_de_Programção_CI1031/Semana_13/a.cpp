#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

double distancia_max(vector <pair<int, int>>& pontos, double xl) {
	double maxD = 0.0;
	for (auto& h : pontos) {
		double dx = xl - h.first;
		double dy = h.second;
		double d = sqrt(dx*dx + dy*dy);
		if (d > maxD) maxD = d;
	}
	return maxD;
}

void solution() {
	int n,x;
	cin >> n >> x;
	vector<pair<int, int>> pontos(n);
	for (int i=0 ; i<n ; i++) {
		int xi, yi;
		cin >> xi >> yi;
		pontos[i] = {xi, yi};
	}

	double esq = 0.0, dir = x;
	for (int i=0; i<100 ; i++) {
		double m1 = esq + (dir-esq) / 3.0;
		double m2 = dir - (dir-esq) / 3.0;
		double d1 = distancia_max(pontos, m1);
		double d2 = distancia_max(pontos, m2);

		if (d1 < d2)
			dir = m2;
		else
			esq = m1;
	}

	double xl = (esq + dir) / 2.0;
	double d = distancia_max(pontos, xl);

	cout << fixed << setprecision(2) << xl << " " << d << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	solution();

	return 0;
}

