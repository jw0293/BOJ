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
#define INF LLONG_MAX-1
#define Mod 1234567
#define endl '\n'
#define ENDL cout << endl

using namespace std;

int N, M, K;
ll cache[100 + 1][100 + 1];
bool isGo[100 + 1][100 + 1][3];

void input() {
	cin >> N >> M;
	cin >> K;
	for (int i = 0; i < K; i++) {
		int x1, y1, x2, y2;
		cin >> y1 >> x1 >> y2 >> x2;
		if (y1 > y2) swap(y1, y2);
		else if (x1 > x2) swap(x1, x2);

		if (y1 < y2) isGo[y1][x1][1] = true;
		else if (x1 < x2) isGo[y1][x1][2] = true;
	}
}

bool isValid(int y, int x) {
	return (0 <= y && y <= N && 0 <= x && x <= M);
}

ll path(int y, int x) {
	if (!isValid(y, x)) return 0;
	if (y == N && x == M) return 1;
	ll& ret = cache[y][x];
	if (ret != -1) return ret;

	ret = 0;
	if (!isGo[y][x][1]) ret += path(y + 1, x);
	if (!isGo[y][x][2]) ret += path(y, x + 1);
	return ret;
}

ll solution() {
	memset(cache, -1, sizeof(cache));
	return path(0, 0);
}

int main() {
	fastio;
	input();
	cout << solution() << endl;
	
	return 0;
}
//i want to sex ........
// System.out.print("섹스하고싶다");
// print("섹스하고싶다")
// printf("섹스하고싶다");
