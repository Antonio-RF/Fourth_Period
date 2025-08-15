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

	vector<pair<int, char>> v(n);
	for (ll i=0 ; i<n ; i++) {
		int k;
		char u;
		cin >> k >> u;
		v[i].first = k;
		v[i].second = u;
	}

	ll pont = 0;
	bool deu = true;
	bool pula = false;
	for (int i=1 ; i<n ; i++) {
		if (pula) {
			pula = false;
			continue;
		}

		//cout << "v[pont]= " << v[pont].second << endl;
		//cout << "v[i]= " << v[i].second << endl;
		if (v[pont].first == v[i].first) {
			if (v[pont].second != v[i].second) {
				pont = i+1;
				pula = true;
			}
			else {
				deu = false;
				break;
			}
		}
		else if (v[pont].first < v[i].first) {
			deu = false;
			break;
		}
		else {
			if (i == n-1) {
				deu = false;
				break;
			}
			continue;
		}
	}

	if (deu)
		cout << "S" << endl;
	else
		cout << "N" << endl;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	solution();
 
	return 0;
}

