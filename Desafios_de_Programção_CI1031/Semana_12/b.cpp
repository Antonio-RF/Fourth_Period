#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;


const ll b = 31;
const ll P = 1e9+7;

struct hash_str {
vector<ll> h, p;
	hash_str(string &s) : h(s.size()), p(s.size()) {
		int n = s.size();
		h[0] = s[0];
		for (int i = 1; i < n; i++)
			h[i] = (h[i - 1] * b + s[i]) % P;
		p[0] = 1;
		for (int i = 1; i < n; i++)
			p[i] = (p[i - 1] * b) % P;
	}
	ll substr(int l, int r) { // <- 4 3 2 1 0
		if (l == 0) return h[r];
		ll ans = (h[r] - h[l - 1] * p[r - l + 1]) % P;
		if (ans < 0) ans += P;
		return ans;
	}
};

void solution() {
	string s;
	cin >> s;
	int n = s.size();

	string rev_s = s;
	reverse(rev_s.begin(), rev_s.end());

	hash_str hs(s);
	hash_str hrs(rev_s);

    int max_len = 1;
    int ans_l = 0;

     for (int center = 0; center < n; center++) {
        // Palíndromos de tamanho ímpar
        int l = 0, r = min(center, n-center-1);
        while (l <= r) {
            int len = (l + r) / 2;
            int left = center - len;
            int right = center + len;
            int rev_left = n-1 - right;
            int rev_right = n-1 - left;
            if (hs.substr(left, right) == hrs.substr(rev_left, rev_right)) {
                if (2*len + 1 > max_len) {
                    max_len = 2*len + 1;
                    ans_l = left;
                }
                l = len + 1;
            } 
			else
                r = len - 1;
        }
        // Palíndromos de tamanho par (centro entre center e center+1)
        l = 0, r = min(center, n-center-2);
        while (l <= r) {
            int len = (l + r) / 2;
            int left = center - len;
            int right = center + 1 + len;
            int rev_left = n-1 - right;
            int rev_right = n-1 - left;
            if (hs.substr(left, right) == hrs.substr(rev_left, rev_right)) {
                if (2*len + 2 > max_len) {
                    max_len = 2*len + 2;
                    ans_l = left;
                }
                l = len + 1;
            } else {
                r = len - 1;
            }
        }
    }
    cout << s.substr(ans_l, max_len) << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	solution();

	return 0;
}

