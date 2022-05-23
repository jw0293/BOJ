#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <bitset>

using namespace std;

int N, M, Cnt = 1;
bool visited[101][101], isCan;
int board[101][101];
vector<pair<int, int>> Switch[101][101];
pair<int, int> ps;

const int dy[] = { 1,-1,0,0 };
const int dx[] = { 0,0,1,-1 };

int isValid(int y, int x) {
	return (1 <= y && y <= N && 1 <= x && x <= N);
}

void DFS(int y, int x) {
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (isValid(ny, nx)) {
			if (!visited[ny][nx] && board[ny][nx] == 0) {
				visited[ny][nx] = true;
				ps.first = ny, ps.second = nx;
				for (int j = 0; j < Switch[ny][nx].size(); j++) {
					pair<int, int> Cur = Switch[ny][nx][j];
					if (board[Cur.first][Cur.second] == -1) {
						isCan = true;
						Cnt++;
						board[Cur.first][Cur.second] = 0;
					}
				}
				DFS(ny, nx);
			}
		}
	}
}

void go() {
	memset(board, -1, sizeof(board));
	for (int i = 0; i < Switch[1][1].size(); i++) {
		pair<int, int> Cur = Switch[1][1][i];
		if (board[Cur.first][Cur.second] == -1) {
			Cnt++;
			board[Cur.first][Cur.second] = 0;
		}
	}
	board[1][1] = 0;
	visited[1][1] = true;
	int y = 1, x = 1;
	while (1) {
		isCan = false;
		DFS(y, x);
		y = ps.first;
		x = ps.second;
		if (!isCan) break;
		memset(visited, false, sizeof(visited));
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		Switch[a][b].push_back({ c,d });
	}
	go();
	cout << Cnt << endl;

	return 0;
}