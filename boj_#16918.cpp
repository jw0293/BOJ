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

int R, C, N;
int board[200 + 1][200 + 1];

const int dy[] = { 1, -1, 0, 0 };
const int dx[] = { 0, 0, 1, -1 };

void input() {
	cin >> R >> C >> N;
	for (int i = 1; i <= R; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == '.') {
				board[i][j + 1] = 0;
			}
			else {
				board[i][j + 1] = 1;
			}
		}
	}
}

bool isValid(int y, int x) {
	return (1 <= y && y <= R && 1 <= x && x <= C);
}

bool isTimeOut() {
	N--;
	if (!N) return false;
	return true;
}

void timing(vector<pair<int,int>> &v) {
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (board[i][j] == 0) continue;
			board[i][j]++;
			if (board[i][j] >= 3) {
				v.push_back({ i, j });
			}
		}
	}
}

void installBomb(vector<pair<int, int>>& v) {
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (board[i][j] != 0) {
				board[i][j]++;
			}
			else {
				board[i][j] = 1;
			}
		}
	}
}

void explosion(vector<pair<int,int>> &v) {
	for (auto t : v) {
		board[t.first][t.second] = 0;
		for (int i = 0; i < 4; i++) {
			int ny = t.first + dy[i];
			int nx = t.second + dx[i];


			if (!isValid(ny, nx)) continue;
			board[ny][nx] = 0;
		}
	}
	v.clear();
}

void printResult() {
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (board[i][j] == 0) cout << ".";
			else cout << "O";
		}
		ENDL;
	}
}

void solution() {
	vector<pair<int, int>> chk;
	while (1) {
		if (!isTimeOut()) break;
		installBomb(chk);
		explosion(chk);

		if (!isTimeOut()) break;
		timing(chk);
		explosion(chk);
	}
	printResult();
}

int main() {
	fastio;
	input();
	solution();

	return 0;
}