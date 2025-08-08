#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solution() {
	int a,b,c;
	cin >> a >> b >> c;
	vector <int> v(9);
	v[0] = a+b+c;
	v[1] = a-b-c;
	v[2] = a*b*c;
	v[3] = a+b-c;
	v[4] = a-b+c;
	v[5] = a+b*c;
	v[6] = a-b*c;
	v[7] = a*b+c;
	v[8] = a*b-c;

	int resp = 1000000;
	for (int k=0 ; k<9 ; k++)
		if (v[k] < resp)
			resp = v[k];
	cout << resp << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	solution();

	return 0;
}

