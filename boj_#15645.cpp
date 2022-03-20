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
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define ENDL cout << endl
#define ll long long
#define ull unsigned long long
#define INF 987654321
#define Mod 1000000007
#define endl '\n'

using namespace std;

int N;
int ps[100000 + 1][4];
int cache1[100000 + 1][4][4];
int cache2[100000 + 1][4][4];

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= 3; j++) {
			cin >> ps[i][j];
		}
	}
}

bool isValid(int cur, int next) {
	if (cur == 1 && (next == 1 || next == 2)) return true;
	if (cur == 2 && (next == 1 || next == 2 || next == 3)) return true;
	if (cur == 3 && (next == 2 || next == 3)) return true;
	return false;
}

int path1(int index, int prev, int cur) {
	if (index > N) return 0;
	int& ret = cache1[index][prev][cur];
	if (ret != -1) return ret;

	ret = INF;
	for (int i = 1; i <= 3; i++) {
		if (!isValid(cur, i)) continue;
		ret = min(ret, path1(index + 1, cur, i) + ps[index][cur]);
	}
	return ret;
}

int path2(int index, int prev, int cur) {
	if (index > N) return 0;
	int& ret = cache2[index][prev][cur];
	if (ret != -1) return ret;

	ret = 0;
	for (int i = 1; i <= 3; i++) {
		if (!isValid(cur, i)) continue;
		ret = max(ret, path2(index + 1, cur, i) + ps[index][cur]);
	}
	return ret;
}

pair<int, int> solution() {
	int answerMax = 0, answerMin = INF;
	for (int i = 1; i <= 3; i++) {
		memset(cache1, -1, sizeof(cache1));
		memset(cache2, -1, sizeof(cache2));
		int val1 = path1(1, 0, i);
		int val2 = path2(1, 0, i);
		answerMax = max(answerMax, val2);
		answerMin = min(answerMin, val1);
	}
	return { answerMax, answerMin };
}

void output(pair<int, int> &answer) {
	cout << answer.first << " " << answer.second << endl;
}

int main() {
	fastio;
	input();
	pair<int, int> answer = solution();
	output(answer);

	return 0;
}