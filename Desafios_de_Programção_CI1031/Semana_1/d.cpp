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
	vector<ll> v(t);
	for (ll &i:v)
		cin >> i;

	ll count = 0;
	for (int i=0 ; i<t-1 ; i++) {
		if (v[i+1] < v[i]) {
			count += v[i]-v[i+1];
			v[i+1] = v[i];
		}
	}

	cout << count << endl;

	return 0;
}

