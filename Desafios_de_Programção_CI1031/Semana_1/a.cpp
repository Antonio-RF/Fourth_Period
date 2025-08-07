#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
typedef long long ll;
 
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

bool eh_par(string k) {
	return ((k[k.size()-1]-'0' == 0 || k[k.size()-1] == '2' || k[k.size()-1] == '4' || k[k.size()-1] == '6' || k[k.size()-1] == '8'));
}

void solution() {
	string a,b;
	cin >> a >> b;

	if ((eh_par(a) && eh_par(b)) || (!eh_par(a) && !eh_par(b)))
		cout << "PARCEIROS" << endl;
	else
		cout << "NAO PARCEIROS" << endl;
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

