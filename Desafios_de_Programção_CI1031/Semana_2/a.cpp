#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
typedef long long ll;
 
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solution() {
	int n;
	cin >> n;

	queue <int> fifo_q;
	stack <int> lifo_s;
	priority_queue <int> prio_q;

	bool fifo = true;
	bool lifo = true;
	bool prio = true;
	for (int i=0 ; i<n ; i++) {
		int k, e;
		cin >> k >> e;

		if (k == 0) {
			fifo_q.push(e);
			lifo_s.push(e);
			prio_q.push(e);
		}
		else {
			if (!fifo_q.empty() && fifo_q.front() == e)
				fifo_q.pop();
			else
				fifo = false;

			if (!lifo_s.empty() && lifo_s.top() == e)
				lifo_s.pop();
			else
				lifo = false;

			if (!prio_q.empty() && prio_q.top() == e)
				prio_q.pop();
			else
				prio = false;
		}
	}


	if (fifo and !lifo and !prio)
		cout << "fifo" << endl;
	else if (!fifo and lifo and !prio)
		cout << "lifo" << endl;
	else if (!fifo and !lifo and prio)
		cout << "priority" << endl;
	else if (!fifo and !lifo and !prio)
		cout << "unknown" << endl;
	else
		cout << "ambiguous" << endl;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	solution();
 
	return 0;
}

