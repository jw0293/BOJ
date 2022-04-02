#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
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

int N, M;
int board[300 + 1][300 + 1];
int cache[300 + 1][300 + 1];

void input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> board[i][j];
		}
	}
}

bool isValid(int y, int x) {
	return (1 <= y && y <= N && 1 <= x && x <= M);
}

int path(int y, int x) {
	if (!isValid(y, x)) return INF;
	if (y == N && x == M) return 0;
	int& ret = cache[y][x];
	if (ret != -1) return ret;

	ret = INF;
	for (int i = 1; i <= board[y][x]; i++) {
		ret = min(ret, path(y + i, x)+1);
		ret = min(ret, path(y, x + i)+1);
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