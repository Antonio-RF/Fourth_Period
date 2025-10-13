#include <bits/stdc++.h>
using namespace std;

// Tipos básicos
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi = vector<int>;
using vll = vector<ll>;

// Constantes comuns
const int INF = 1e9+7;
const ll LINF = 1e18;
const int MOD = 1e9+7;

// Direções para grafos/grelhas
const int dx4[4] = {-1,0,1,0};
const int dy4[4] = {0,1,0,-1};

const int dx8[8] = {-1,-1,-1,0,0,1,1,1};
const int dy8[8] = {-1,0,1,-1,1,-1,0,1};

// Macros rápidos
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define f first
#define s second
#define endl '\n'

// Fast I/O
struct IO {
	IO() {
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
	}
} io;

const int N = 1e5 + 5;
#define OP(X, Y) (X * Y)
#define NEUTRAL 1
vector<ll> t(4 * N);

int sign(int x) {
	if (x > 0) return 1;
	if (x < 0) return -1;
	return 0;
}


void build(vector<int>& src, int ti=1, int tl=1, int tr=-1) {
	if (tl == tr) {
		if (tl < (int)src.size()) t[ti] = src[tl];
		return;
	}
	int tm = (tl + tr) / 2;
	build(src, ti*2, tl, tm);
	build(src, ti*2+1, tm+1, tr);
	t[ti] = OP(t[ti*2], t[ti*2+1]);
}

void set_value(int i, int v, int ti=1, int tl=1, int tr=-1) {
	if (tl == tr) {
		t[ti] = v;
		return;
	}
	int tm = (tl + tr) / 2;
	if (i <= tm) set_value(i, v, ti*2, tl, tm);
	else set_value(i, v, ti*2+1, tm+1, tr);
	t[ti] = OP(t[ti*2], t[ti*2+1]);
}

int op_inclusive(int l, int r, int ti=1, int tl=1, int tr=-1) {
	if (l > r) return NEUTRAL;
	if (l == tl && r == tr) return t[ti];
	int tm = (tl + tr) / 2;
	return OP(op_inclusive(l, min(r, tm), ti*2, tl, tm), op_inclusive(max(l, tm+1), r, ti*2+1, tm+1, tr));
}



void solution(){
	ll k, n;
	cin >> n >> k;

	vector<int> src(n+1);
	for (int i=1 ; i<=n ; i++) {
		int x;
		cin >> x;
		src[i] = sign(x);
	}

	build(src, 1, 1, n);

	string saida;
	for (int q=0 ; q<k ; q++) {
		char letra;
		ll i, j;
		cin >> letra >> i >> j;
		if (letra == 'A') {
			set_value(i, sign(j), 1, 1, n);
		}
		else {
			int resp = op_inclusive(i, j, 1, 1, n);
			if (resp == 0) saida += '0';
			else if (resp == 1) saida += '+';
			else saida += '-';
		}
	}
	cout << saida << endl;
}

int main() {
    IO io;
	solution();
	return 0;
}









