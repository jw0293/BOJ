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
int positive[100000 + 1];
vector<int> tree[100000 + 1];

void dfs(int p) {
	for (auto next : tree[p]) {
		positive[next] += positive[p];
		dfs(next);
	}
}

void input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		int p;
		cin >> p;
		if (i == 1) continue;
		tree[p].push_back(i);
	}
	for (int i = 0; i < M; i++) {
		int person, w;
		cin >> person >> w;

		positive[person] += w;
	}

	dfs(1);
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