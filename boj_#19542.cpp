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

int N, M;
int parent[100000 + 1];
int positive[100000 + 1];
vector<int> tree[100000 + 1];

void dfs(int p, int w) {
	if (tree[p].size() == 0)) return;

	for (auto& t : tree[p]) {
		positive[t] += w;
		dfs(t, w);
	}
}

void input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> parent[i];
		if (i == 1) continue;
		tree[parent[i]].push_back(i);
	}
	for (int i = 0; i < M; i++) {
		int person, w;
		cin >> person >> w;

		dfs(person, w);
	}
}

void printAnswer() {
	for (int i = 1; i <= N; i++) {
		cout << positive[i] << " ";
	}
}

int main() {
	fastio;
	input();
	printAnswer();

	return 0;
}