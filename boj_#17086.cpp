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
#define Mod 1000000009
#define endl '\n'
#define ENDL cout << endl

using namespace std; 

int N, M, sharkCnt;
int board[50 + 1][50 + 1];
int visited[50 + 1][50 + 1];
const int dy[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
const int dx[] = { 0, 1, 1, 1, 0, -1, -1, -1 };

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

int findMinDistance(int y, int x) {
	queue<pair<int, int>> q;
	memset(visited, 0, sizeof(visited));

	q.push({ y, x });
	visited[y][x] = 1;
	while (!q.empty()) {
		int curY = q.front().first;
		int curX = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++) {
			int ny = curY + dy[i];
			int nx = curX + dx[i];

			if (visited[ny][nx] != 0 || !isValid(ny, nx)) continue;
			if (board[ny][nx] == 1) return visited[curY][curX];
			visited[ny][nx] = visited[curY][curX] + 1;
			q.push({ ny, nx });
		}
	}
	return INF;
}

int solution() {
	int answer = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (board[i][j] == 1) continue;
			answer = max(answer, findMinDistance(i, j));
		}
	}
	return answer;
}

int main() {
	fastio;
	input();
	cout << solution() << endl;

	return 0;
}