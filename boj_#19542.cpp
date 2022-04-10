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

int N, S, D, answerDist;
int cache[100000 + 1];
int ndist[100000 + 1];
bool visited[100000 + 1];
vector<int> adj[100000 + 1];

void input() {
	cin >> N >> S >> D;
	for (int i = 1; i < N; i++) {
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
}

int path(int node) {
	queue<int> q;
	visited[node] = true;
	for (auto &next : adj[node]) {
		if (visited[next]) continue;
		q.push(next);
	}
	if (q.empty()) {
		ndist[node] = 1;
		return 1;
	}

	int& ret = ndist[node];
	while (!q.empty()) {
		int next = q.front(); 
		q.pop();

		ret = max(ret, path(next) + 1);
	}
	return ret;
}

void cacheDist(int n) {
	queue<int> q;
	visited[n] = true;

	answerDist++;
	for (auto next : adj[n]) {
		if (visited[next] || ndist[next] <= D) continue;
		q.push(next);
	}
	if (q.empty()) return;

	while (!q.empty()) {
		int ny = q.front(); q.pop();

		cacheDist(ny);
		answerDist++;
	}
}

void solution() {
	path(S);
	memset(visited, false, sizeof(visited));
	cacheDist(S);
	cout << answerDist - 1 << endl;
}

int main() {
	fastio;
	input();
	solution();

	return 0;
}