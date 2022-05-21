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

int N, M;
int board[50 + 1][50 + 1];
bool checked[50 + 1][50 + 1];
const int dy[] = { 0, 0, -1, -1, -1, 0, 1, 1, 1 };
const int dx[] = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };
vector<pair<int, int>> cloud;

void init_cloud() {
	cloud.push_back({ N, 1 });
	cloud.push_back({ N, 2 });
	cloud.push_back({ N - 1, 1 });
	cloud.push_back({ N - 1, 2 });
}

void input_init() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> board[i][j];
		}
	}

	init_cloud();
}

void cloudMove(int dir, int move) {
	for (int i = 0; i < move; i++) {
		for (int j = 0; j < cloud.size();j++) {
			int ny = cloud[j].first + dy[dir];
			int nx = cloud[j].second + dx[dir];

			if (ny == 0) ny = N;
			if (ny == N + 1) ny = 1;
			if (nx == 0) nx = N;
			if (nx == N + 1) nx = 1;

			cloud[j].first = ny;
			cloud[j].second = nx;
		}
	}
}

void rain() {
	for (auto& ptr : cloud) {
		board[ptr.first][ptr.second]++;
		checked[ptr.first][ptr.second] = true;
	}
}

void waterCopy() {
	for (auto& ptr : cloud) {
		int nearCount = 0;
		for (int i = 2; i <= 8; i += 2) {
			int ny = ptr.first + dy[i];
			int nx = ptr.second + dx[i];

			if (ny < 1 || ny > N || nx < 1 || nx > N) continue;
			if (board[ny][nx] != 0) nearCount++;
		}
		board[ptr.first][ptr.second] += nearCount;
	}
}

void formCloud() {
	cloud.clear();
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (board[i][j] >= 2 && checked[i][j] == false) {
				cloud.push_back({ i, j });
				board[i][j] -= 2;
			}
		}
	}
}

int sumWater() {
	int answer = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			answer += board[i][j];
		}
	}
	return answer;
}

int solution() {
	int dir, move;
	for (int i = 0; i < M; i++) {
		cin >> dir >> move;
		memset(checked, false, sizeof(checked));

		cloudMove(dir, move);
		rain();
		waterCopy();
		formCloud();
	}

	return sumWater();
}

int main() {
	fastio;
	input_init();
	cout << solution() << endl;

	return 0;
}