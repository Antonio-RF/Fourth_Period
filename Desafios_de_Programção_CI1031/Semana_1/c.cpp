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

	ll pont_inicio = 0;
	ll pont_fim = n-1;

	while(q--) {
		int t, x;
		cin >> t >> x;

		if (t==2)
			cout << text[abs(pont_inicio+x-n)] << endl;;
		if (t==1) {
			ll k = x;
			ll u = x;
			if (pont_inicio-x < 0)
				k = n - abs(pont_inicio-x);
			else
				k = pont_inicio-x;
			pont_inicio = k;
			if (pont_fim-x < 0) {
				u = pont_fim-x;
				pont_fim += x;
			}
			else {
				u = pont_fim-x;
				pont_fim -= x;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	solution();

	return 0;
}

