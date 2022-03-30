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
#define INF 987654321
#define mod 1000000007
#define endl '\n'

using namespace std;

int N, M;
int board[1000 + 1][1000 + 1];
ll cache[1000 + 1][1000 + 1];

void input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> board[i][j];
		}
	}
}

bool isValid(int x) {
	return (1 <= x && x <= M);
}

ll path(int y, int x, int prev, int dir) {
	if (!isValid(x)) return 0;
	if (board[y][x] == 0) return 0;
	if (y == 1) return 1;
	ll& ret = cache[y][x];
	if (ret != -1) return ret;

	ret = 0;
	for (int i = 0; i < 3; i++) {
		ret += path(y - 1, x + i - 1, dir, i) % mod;
		ret %= mod;
	}
	return ret;
}

ll solution() {
	ll count = 0;
	memset(cache, -1, sizeof(cache));
	if (N == 1) {
		for (int i = 1; i <= M; i++) {
			if (board[N][i] == 1) count += 1;
		}
	}
	else {
		for (int i = 1; i <= M; i++) {
			for (int dir = 0; dir < 3; dir++) {
				if (board[N][i] == 0) continue;
				count += path(N - 1, i + dir - 1, 3, dir) % mod;
				count %= mod;
			}
		}
	}
	return count;
}

int main() {
	fastio;
	input();
	cout << solution() << endl;

	return 0;
}