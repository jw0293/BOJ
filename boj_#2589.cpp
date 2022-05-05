#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <cmath>
#define INF 9876543210
#define ENDL cout << endl;
#define endl '\n'
#define swap(type, x, y) do{type t=y;y=x;x=t;}while(0)
using namespace std;

typedef long long ll;
typedef pair<int, int> pl;


// BOJ :: https://www.acmicpc.net/problem/2589

int adj[51][51];
int visited[51][51];

const int dy[] = { 1, -1, 0, 0 };
const int dx[] = { 0, 0, 1, -1 };

int Length;
queue<pl> q;

bool isValid(int y, int x, int col, int row) {
	return (1 <= y && y <= col && 1 <= x && x <= row);
}

void BFS(int col, int row) {
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (!isValid(ny, nx, col, row) || visited[ny][nx] != 0) continue;
			if (adj[ny][nx] == 0) {
				q.push({ ny, nx });
				visited[ny][nx] = visited[y][x] + 1;
				Length = max(Length, visited[ny][nx]);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int col, row;
	cin >> col >> row;
	for (int y = 1; y <= col; y++) {
		string s; cin >> s;
		for (int x = 0; x < s.size(); x++) {
			if (s[x] == 'W') adj[y][x + 1] = 1;
			else adj[y][x + 1] = 0;
		}
	}

	int Answer = 0;
	for (int i = 1; i <= col; i++) {
		for (int j = 1; j <= row; j++) {
			if (!adj[i][j]) {
				memset(visited, 0, sizeof(visited));
				q.push({ i, j });
				visited[i][j] = 1;
				Length = 0;
				BFS(col, row);
				Answer = max(Answer, Length);
			}
		}
	}
	cout << Answer - 1 << endl;

	return 0;
}