#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<ll> pre(string ne) {
	ll n = ne.size();
	vector<ll> pi (n + 1, -1);
	ll i = 0, j = -1;
	while (i < n) {
		while (j >= 0 && ne[i] != ne[j]) j = pi[j];
		++i, ++j;
		pi[i] = j;
	}
	return pi;
}

void solution() {
	string s;
	cin >> s;

	vector<ll> v = pre(s);
	ll k = v[s.size()];

	vector<ll> tam;
	while(k > 0) {
		tam.pb(k);
		k = v[k];
	}

	reverse(tam.begin(), tam.end());
	for (int i=0 ; i<tam.size() ; i++) cout << tam[i] << " ";
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	solution();

	return 0;
}

