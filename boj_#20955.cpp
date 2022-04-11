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
#define ll long long	
#define ull unsigned long long
#define INF LLONG_MAX-1
#define Mod 1234567
#define endl '\n'
#define pil pair<int,int>
#define ENDL cout << endl

using namespace std;

int N, M, C;
int parent[100000 + 1];
vector<int> adj[100000 + 1];

void init_Parent(int n) {
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
}

int getParent(int x) {
	if (x == parent[x]) return x;
	return parent[x] = getParent(parent[x]);
}

void unionNode(int x, int y) {
	x = getParent(x);
	y = getParent(y);

	if (x < y) {
		parent[y] = x;
	}
	else {
		parent[x] = y;
	}
}

bool isSame(int x, int y) {
	if (getParent(x) == getParent(y)) return true;
	return false;
}

void input() {
	cin >> N >> M;
	init_Parent(N);

	for (int i = 0; i < M; i++) {
		int u, v; cin >> u >> v;

		if (isSame(u, v)) {
			C++;
		}
		else {
			unionNode(u, v);
		}
	}
}

int solution() {
	int answer = 0;
	for (int i = 1; i <= N; i++) {
		if (getParent(i) == i) {
			answer++;
		}
	}
	return answer - 1 + C;
}

int main() {
	fastio;
	input();
	cout << solution() << endl;

	return 0;
}