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

const int N = 1000005;
vector<vector<int>> t(4*N);

void build(const vector<int>& src, int ti=1, int tl=1, int tr=N) {
    if (tl == tr) {
        if (tl <= int(src.size())-1) t[ti] = {src[tl]};
        return;
    }
    int tm = (tl + tr) / 2;
    build(src, ti*2, tl, tm);
    build(src, ti*2+1, tm+1, tr);
    merge(t[ti*2].begin(), t[ti*2].end(),
          t[ti*2+1].begin(), t[ti*2+1].end(),
          back_inserter(t[ti]));
}
int count_leq(int l, int r, int x, int ti=1, int tl=1, int tr=N) {
    if (r < tl || tr < l) return 0;
    if (l <= tl && tr <= r) {
        return upper_bound(t[ti].begin(), t[ti].end(), x) - t[ti].begin();
    }
    int tm = (tl + tr) / 2;
    return count_leq(l, r, x, ti*2, tl, tm) +
           count_leq(l, r, x, ti*2+1, tm+1, tr);
}
int kth_inclusive(int l, int r, int k, const vector<int>& vals) {
    int low = 0, high = int(vals.size())-1, ans = -1;
    while (low <= high) {
        int mid = (low + high)/2;
        int cnt = count_leq(l, r, vals[mid]);
        if (cnt >= k) {
            ans = vals[mid];
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}


void solution(){
	ll n, q;
	cin >> n >> q;

	vector<int> v(n+1);
	for (int i=1 ; i<=n ; i++) cin >> v[i];

	vector<int> sorted_v(v.begin()+1, v.end());
	sort(sorted_v.begin(), sorted_v.end());

	build(v);

	while(q--) {
		ll l, r, k;
		cin >> l >> r >> k;
		cout << kth_inclusive(l, r, k, sorted_v) << endl;
	}
} 

int main() {
    IO io;
	solution();
	return 0;
}









