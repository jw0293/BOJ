#include <algorithm>
#include <iostream>
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
#define ENDL cout << endl
#define ll long long	
#define ull unsigned long long
#define INF 987654321
#define Mod 1000000
#define endl '\n'
#define pil pair<int,int>

using namespace std;

typedef struct {
	int red;
	int green;
	int blue;
}Information;

int N;
int cache[1000 + 1][4][4];
Information ps[1000 + 1];

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> ps[i].red >> ps[i].green >> ps[i].blue;
	}
}

int path(int index, int prev, int color, int op) {
	if (index == N && color == op) return INF;
	if (index > N) return 0;
	int& ret = cache[index][prev][color];
	if (ret != -1) return ret;

	ret = INF;
	int value;
	if (color == 1) value = ps[index].red;
	else {
		value = color == 2 ? ps[index].green : ps[index].blue;
	}

	for (int i = 1; i <= 3; i++) {
		if (index == N) {
			if (color == i || op == i) continue;
			ret = min(ret, path(index + 1, color, i, op) + value);
		}
		else {
			if (color == i) continue;
			ret = min(ret, path(index + 1, color, i, op) + value);
		}
	}
	return ret;
}

int solution() {
	int answer = INF;
	for (int i = 1; i <= 3; i++) {
		memset(cache, -1, sizeof(cache));
		answer = min(answer, path(1, 0, i, i));
	}
	return answer;
}

int main() {
	fastio;
	input();
	cout << solution() << endl;

	return 0;
}