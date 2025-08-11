#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solution() {
	ll n, q;
	cin >> n >> q;

	string text;
	cin >> text;

	ll pont_ini = 0;

	while(q--) {
		int t, x;
		cin >> t >> x;

		if (t==2) {
			ll resultado = (pont_ini + (x-1)) % n;
			cout << text[resultado] << endl;
		}
		if (t==1) {
			x = x % n;
			pont_ini = (pont_ini - x + n) % n;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	solution();

	return 0;
}
