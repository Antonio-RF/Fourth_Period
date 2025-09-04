#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

ll n, k, c;
vector<ll> v;

void solution() {
    cin >> n >> k >> c;
	v.resize(n);
    for (ll &i: v)
        cin >> i;

	vector<ll> dp(k+1, LLONG_MIN);
	dp[0] = 0;

	vector<ll> pref(n+1, 0);
	for (int i=0 ; i<n ; i++)
		pref[i+1] = pref[i] + v[i];

	for (int i=0 ; i<n ; i++) {
		for (int j=k ; j >= 1 ; j--) {
			if (i+c >= n) {
				ll val = dp[j-1];
				if (val != LLONG_MIN)
					dp[j] = max(dp[j], val);
			}
		}
		for (int j=0 ; j<=k ; j++)
			if (dp[j] != LLONG_MIN)
				dp[j] += v[i];
	}

	cout << dp[k] << endl;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	solution();

	return 0;
}
