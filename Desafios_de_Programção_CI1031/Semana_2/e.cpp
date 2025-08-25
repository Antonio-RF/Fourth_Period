#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solution() {
	ll l, n;
	cin >> l >> n;

	vector <ll> v(n);
	for (ll &i: v)
		cin >> i;

	sort(v.begin(), v.end());

	ll menor = 0;
	ll maior = 0;
	for (int i=0 ; i<n ; i++) {
		menor = max(menor, min(v[i], l - v[i]));
		maior = max(maior, max(v[i], l-v[i]));
	}

	cout << menor << " " << maior << endl;


}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--)
		solution();

	return 0;
}

