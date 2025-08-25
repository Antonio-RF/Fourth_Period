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

	vector <pair<int, char>> v(n);
	for (ll i=0 ; i<n ; i++) {
		int a;
		char d;
		cin >> a >> d;
		v[i].first = a;
		v[i].second = d;
	}

	stack <pair<int, int>> pilha;
	bool deu = true;

	for (ll i=0 ; i<n ; i++) {
		int h = v[i].first;
		int d = v[i].second;
		if (d == 'L')
			pilha.push({h, i});
		else {
			bool achou = false;
			stack <pair<int, int>> temp;
			while (!pilha.empty()) {
				auto [h2, idx2] = pilha.top();
				if (h2 == h) {
					int mx = 0;
					for (ll k = idx2+1 ; k<i ; k++) {
						if (v[k].first > mx)
							mx = v[k].first;
					}
					if (mx < h) {
						pilha.pop();
						achou = true;
						break;
					}
				}
				temp.push(pilha.top());
				pilha.pop();
			}
			while (!temp.empty()) {
				pilha.push(temp.top());
				temp.pop();
			}
			if (!achou) {
				deu = false;
				break;
			}
		}
	}

	if (!pilha.empty())
		deu = false;

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

