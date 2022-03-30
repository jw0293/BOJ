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

int n;
int board[64 + 1][64 + 1];
int cache[64 + 1][64 + 1][64 + 1][64 + 1];

void input() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> board[i][j];
		}
	}
}

int path(int y, int x, int prevy, int prevx) {
	if (y > n || x > n) return 0;
	if (y == n && x == n) return 1;
	int& ret = cache[y][x][prevy][prevx];
	if (ret != -1) return ret;
	int jump = board[y][x];
	ret = 0;
	return ret = max(path(y + jump, x, y, x), path(y, x + jump, y, x));
}

void solution() {
	memset(cache, -1, sizeof(cache));
	path(1, 1, 0, 0) == 1 ? cout << "HaruHaru" : cout << "Hing";
}

int main() {
	fastio;
	input();
	solution();

	return 0;
}