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

#define FACTOR(sz) sz

const int MAXN = 200005;

struct Node {
    int balance;
    int min_prefix;
};

Node t[4 * MAXN];

Node OP(const Node &a, const Node &b) {
    Node res;
    res.balance = a.balance + b.balance;
    res.min_prefix = min(a.min_prefix, a.balance + b.min_prefix);
    return res;
}

const Node NEUTRAL = {0, 0};

void build(const vector<char> &src, int ti, int tl, int tr) {
    if (tl == tr) {
        if (src[tl] == '(') {
            t[ti].balance = 1;
            t[ti].min_prefix = 0;
        } else {
            t[ti].balance = -1;
            t[ti].min_prefix = -1;
        }
        return;
    }
    int tm = (tl + tr) / 2;
    build(src, ti * 2, tl, tm);
    build(src, ti * 2 + 1, tm + 1, tr);
    t[ti] = OP(t[ti * 2], t[ti * 2 + 1]);
}

Node query(int l, int r, int ti, int tl, int tr) {
    if (l > r) return NEUTRAL;
    if (l <= tl && tr <= r) return t[ti];
    int tm = (tl + tr) / 2;
    if (r <= tm) return query(l, r, ti * 2, tl, tm);
    if (l > tm) return query(l, r, ti * 2 + 1, tm + 1, tr);
    return OP(query(l, tm, ti * 2, tl, tm), query(tm + 1, r, ti * 2 + 1, tm + 1, tr));
}

void update(int pos, char val, int ti, int tl, int tr) {
    if (tl == tr) {
        if (val == '(') {
            t[ti].balance = 1;
            t[ti].min_prefix = 0;
        } else {
            t[ti].balance = -1;
            t[ti].min_prefix = -1;
        }
        return;
    }
    int tm = (tl + tr) / 2;
    if (pos <= tm) update(pos, val, ti * 2, tl, tm);
    else update(pos, val, ti * 2 + 1, tm + 1, tr);
    t[ti] = OP(t[ti * 2], t[ti * 2 + 1]);
}

void solution() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    string str;
    cin >> str;

    vector<char> v(n + 1);
    for (int i = 1; i <= n; i++) v[i] = str[i - 1];

    build(v, 1, 1, n);

    while (q--) {
        int type, l, r;
        cin >> type >> l >> r;

        if (type == 1) {
            swap(v[l], v[r]);
            update(l, v[l], 1, 1, n);
            update(r, v[r], 1, 1, n);
        } else {
            Node res = query(l, r, 1, 1, n);
            if (res.balance == 0 && res.min_prefix >= 0)
                cout << "Yes\n";
            else
                cout << "No\n";
        }
    }
}

int main() {
    solution();
    return 0;
}


