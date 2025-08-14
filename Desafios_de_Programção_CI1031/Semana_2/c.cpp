#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
typedef long long ll;
 
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solution() {
	ll n;
	cin >> n;

	vector<int> v(n);
	for (int&i: v)
		cin >> i;

	sort(v.begin(), v.end());

	ll resp1 = n/2;
	ll resp2 = v[n/2] - v[(n/2)-1];

	cout << resp1 << " " << resp2 << endl;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	solution();
 
	return 0;
}

