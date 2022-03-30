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
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define endl cout << endl
#define ll long long
#define ull unsigned long long
#define inf 987654321
#define mod 1000000007
#define endl '\n'

using namespace std;

int N, M;
int board[300 + 1][300 + 1];
int cache[300 + 1][300 + 1];

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int y, x; cin >> y >> x;
		board[y][x] = M;
	}
}

bool isValid(int y, int x) {
	return (0 <= y && y < 300 && 0 <= x && x < 300);
}

int path(int y, int x, int ctime) {
	if (ctime >= M) return 0;
	if (!isValid(y, x)) return 0;
	int& ret = cache[y][x];
	if (ret != -1) return ret;

	ret = 0;
	if (board[y][x] != 0) ret += (board[y][x] - ctime);
	return ret += max(path(y + 1, x, ctime + 1), path(y, x + 1, ctime + 1));
}

int solution() {
	memset(cache, -1, sizeof(cache));
	return path(0, 0, 0);
}

int main() {
	fastio;
	input();
	cout << solution();

	return 0;
}