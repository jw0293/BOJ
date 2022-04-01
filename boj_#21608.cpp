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

int N;
const int MAX = 20;
vector<int> ps;
vector<int> student[401];
pair<int, int> position[401];
int board[MAX + 1][MAX + 1];

const int dy[] = { 1, -1, 0, 0 };
const int dx[] = { 0, 0, 1, -1 };

struct cmp {
	bool operator()(pair<pair<int, int>, pair<int, int>> lhs, pair<pair<int, int>, pair<int, int>> rhs) {
		if (lhs.first.first == rhs.first.first) {
			if (lhs.first.second == rhs.first.second) {
				if (lhs.second.first == rhs.second.first) {
					return lhs.second.second > rhs.second.second;
				}
				else {
					return lhs.second.first > rhs.second.first;
				}
			}
			else {
				return lhs.first.second < rhs.first.second;
			}
		}
		else {
			return lhs.first.first < rhs.first.first;
		}
	}
};

void input() {
	cin >> N;
	for (int i = 0; i < N * N; i++) {
		int x; cin >> x;
		ps.push_back(x);
		for (int j = 0; j < 4; j++) {
			int w; cin >> w;
			student[x].push_back(w);
		}
	}
}

bool isValid(int y, int x) {
	return (1 <= y && y <= N && 1 <= x && x <= N);
}

int emptySpace(int y, int x) {
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (!isValid(ny, nx)) continue;
		if (board[ny][nx] == 0) cnt++;
	}
	return cnt;
}

int nearLove(int n, int y, int x) {
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (!isValid(ny, nx)) continue;
		int x = board[ny][nx];
		for (auto& t : student[n]) {
			if (x == t) cnt++;
		}
	}
	return cnt;
}

void sortingPrior(int number, priority_queue<pair<pair<int, int>, pair<int, int>>,
	vector<pair<pair<int, int>, pair<int, int>>>, cmp>& pq) {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (board[i][j] != 0) continue;
			int pfirst = nearLove(number, i, j);
			int psecond = emptySpace(i, j);
			pq.push({ {pfirst, psecond}, {i, j} });
		}
	}
}

int solve() {
	int total = 0;
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			int number = board[y][x];
			int count = nearLove(number, y, x);
			total += (int)pow(10, count - 1);
		}
	}
	return total;
}

int solution() {
	for (auto& t : ps) {
		priority_queue<pair<pair<int, int>, pair<int, int>>,
			vector<pair<pair<int, int>, pair<int, int>>>, cmp> pq;
		sortingPrior(t, pq);
		while (1) {
			pair<pair<int, int>, pair<int, int>> cur = pq.top();
			pq.pop();

			if (board[cur.second.first][cur.second.second] == 0) {
				board[cur.second.first][cur.second.second] = t;
				break;
			}
		}
	}
	return solve();
}

int main() {
	fastio;
	input();
	cout << solution() << endl;

	return 0;
}