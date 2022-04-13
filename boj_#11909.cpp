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
#define INF 987654321
#define Mod 1234567
#define endl '\n'
#define ENDL cout << endl

using namespace std;

int N;
int board[2222 + 1][2222 + 1];
int cache[2222 + 1][2222 + 1];

const int dy[] = { 1, 0 };
const int dx[] = { 0, 1 };

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> board[i][j];
		}
	}
}

bool isValid(int y, int x) {
	return (1 <= y && y <= N && 1 <= x && x <= N);
}

int path(int y, int x) {
	if (y == N && x == N) return 0;
	int& ret = cache[y][x];
	if (ret != -1) return ret;

	ret = INF;
	for (int i = 0; i < 2; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (!isValid(ny, nx)) continue;

		if (board[ny][nx] < board[y][x]) {
			ret = min(ret, path(ny, nx));
		}
		else {
			int power = board[ny][nx] - board[y][x] + 1;
			ret = min(ret, path(ny, nx) + power);
		}
	}
	return ret;
}

int solution() {
	memset(cache, -1, sizeof(cache));
	return path(1, 1);
}

int main() {
	fastio;
	input();
	cout << solution() << endl;
	
	return 0;
}