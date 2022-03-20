#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <string>
#include <cstring>
#include <sstream>
#include <set>
#include <unordered_set>
#include <map> 
#include <algorithm>
#include <cmath>
#include <numeric>
#include <ctime>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define ENDL cout << endl
#define ll long long
#define ull unsigned long long
#define INF 987654321
#define Mod 1000000007
#define endl '\n'

using namespace std;

int N, M, Q;
vector<int> v;
ll cache[1000 + 1];
vector<int> adj[1000 + 1];

void input() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);

		if (a == 1 || b == 1) {
			a == 1 ? v.push_back(b) : v.push_back(a);
		}
	}
}

ll path(int prev, int node) {
	if (node == 1) return 0;
	ll& ret = cache[node];
	if (ret != INF && ret != -1) return ret;

	ret = INF;
	for (auto& t : adj[node]) {
		if (t == prev) continue;
		ret = min(ret, path(node, t) + 1);
	}
	return ret;
}

void init() {
	for (auto t : v) cache[t] = 1;
}

void solution() {
	cin >> Q;
	while (Q--) {
		int node1, node2;
		cin >> node1 >> node2;
		adj[node1].push_back(node2);
		adj[node2].push_back(node1);

		memset(cache, -1, sizeof(cache));
		init();

		int dist;
		for (int node = 1; node <= N; node++) {
			if (node == 1) {
				cache[node] = 0;
				cout << 0 << " ";
				continue;
			}
			path(-1, node);
			cache[node] == INF ? cout << -1 << " " : cout << cache[node] << " ";
		}
		ENDL;
	}
}

int main() {
	fastio;
	input();
	solution();

	return 0;
}