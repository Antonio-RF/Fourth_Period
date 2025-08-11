#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
typedef long long ll;
 
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solution() {
	string s;
	cin >> s;

	vector<int> freq(26,0);
	for (char c: s)
		freq[c - 'A']++;

	int impares = 0;
	int indice_meio = -1;

	for (int i=0 ; i<26 ; i++) {
		if (freq[i] % 2 != 0) {
			impares++;
			indice_meio = i;
		}
	}

	if (impares > 1) {
		cout << "NO SOLUTION" << endl;
		return;
	}

	string metade = "";
	string meio = "";
	for (int i=0 ; i<26 ; i++) {
		string temp(freq[i]/2, 'A'+i);
		metade += temp;
	}

	if (indice_meio != -1) {
		meio = string(freq[indice_meio]%2, 'A' + indice_meio);
	}

	string resultado = metade + meio + string(metade.rbegin(), metade.rend());
	cout << resultado << endl;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	solution();

	return 0;
}

