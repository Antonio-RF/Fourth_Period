#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
typedef long long ll;
 
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	ll count = 0;
	ll k, l;
	for (int i=0 ; i<t/2 ; i++) {
		cin >> k >> l;
		if (l < k)
			count += k-l;
	}
	ll u;
	if (t % 2 != 0) {
		cin >> u;
	}
	if (l > u)
		count += l-u;

	cout << count << endl;

	return 0;
}

