#include <algorithm>
#include <iostream>
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
#define INF 987654321
#define Mod 1000000
#define endl '\n'
#define pil pair<int,int>

using namespace std;

vector<int> pos;
int cache[100000 + 1][5][5];

void input() {
	while (1) {
		int x; cin >> x;
		if (!x) break;
		pos.push_back(x);
	}
}

int dist(int cur, int next) {
	if (!cur) return 2;
	if (cur == next) return 1;
	if (cur == 1 && (next == 2 || next == 4)) return 3;
	if (cur == 2 && (next == 1 || next == 3)) return 3;
	if (cur == 3 && (next == 2 || next == 4)) return 3;
	if (cur == 4 && (next == 1 || next == 3)) return 3;
	return 4;
}

int path(int index, int left, int right) {
	if (index == pos.size()) return 0;
	int& ret = cache[index][left][right];
	if (ret != -1) return ret;

	ret = INF;
	return ret = min({ ret, path(index + 1, pos[index], right) + dist(left, pos[index])
			, path(index + 1, left, pos[index]) + dist(right, pos[index]) });
}

int solution() {
	memset(cache, -1, sizeof(cache));
	return path(0, 0, 0);
}

int main() {
	fastio;
	input();
	cout << solution() << endl;

	return 0;
}