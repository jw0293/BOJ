#include <algorithm>
#include <iostream>
#include <numeric>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <climits>
#include <set>
#include <map> 
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ENDL cout << endl
#define ll long long	
#define ull unsigned long long
#define INF LLONG_MAX-1
#define Mod 1234567
#define endl '\n'
#define pil pair<int,int>

using namespace std;

int N, K, root;
int parent[1000000 + 1];
vector<int> tree[1000000 + 1];

void clear(vector<int> &t) {
	for (auto& ptr : t) {
		tree[ptr].clear();
	}
}

int solution() {
	int upRoot = parent[K];
	int dfsRoot = parent[upRoot];

	int answer = 0;
	for (auto& ptr : tree[dfsRoot]) {
		if (ptr == upRoot) continue;
		answer += tree[ptr].size();
	}

	return answer;
}

void init_Tree(vector<int>& ps) {
	int prev, curParent;
	bool start = false;
	priority_queue<int, vector<int>, greater<int>> pq;
	
	root = ps[0];
	parent[root] = -1;

	pq.push(root);
	for (int i = 1; i < N; i++) {
		if (!start) {
			start = true;
			curParent = pq.top(); pq.pop();
		}
		else {
			// 연속적으로 증가하는 부분 수열이 아닐 경우 재 시작 해야함
			if (ps[i] - prev != 1) {
				curParent = pq.top(); pq.pop();
			}
		}
		prev = ps[i];
		tree[curParent].push_back(ps[i]);
		parent[ps[i]] = curParent;
		pq.push(ps[i]);
	}
}

void input() {
	while (1) {
		cin >> N >> K;
		if (!N && !K) break;

		vector<int> ps(N, 0);
		for (int i = 0; i < N; i++) {
			cin >> ps[i];
		}

		init_Tree(ps);
		cout << solution() << endl;
		clear(ps);
	}
}

int main() {
	fastio;
	input();
	
	return 0;
}