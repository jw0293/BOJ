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
#define Mod 1234567
#define endl '\n'
#define pil pair<int,int>

using namespace std;

int N;
ll cache[1000 + 1][10 + 1];

bool isValid(int x, int y) {
	if (x == 1) {
		if (y == 2 || y == 4) return true;
		return false;
	}
	else if (x == 2) {
		if (y == 1 || y == 3 || y == 5) return true;
		return false;
	}
	else if (x == 3) {
		if (y == 2 || y == 6) return true;
		return false;
	}
	else if (x == 4) {
		if (y == 1 || y == 5 || y == 7) return true;
		return false;
	}
	else if (x == 5) {
		if (y == 2 || y == 4 || y == 6 || y == 8) return true;
		return false;
	}
	else if (x == 6) {
		if (y == 3 || y == 5 || y == 9) return true;
		return false;
	}
	else if (x == 7) {
		if (y == 4 || y == 8 || y == 0) return true;
		return false;
	}
	else if (x == 8) {
		if (y == 5 || y == 7 || y == 9) return true;
		return false;
	}
	else if (x == 9) {
		if (y == 6 || y == 8) return true;
		return false;
	}
	else {
		if (y == 7) return true;
		return false;
	}
}

ll path(int index, int value) {
	if (index == N) return 1;
	ll& ret = cache[index][value];
	if (ret != -1) return ret;

	ret = 0;
	for (int next = 0; next <= 9; next++) {
		if (!isValid(value, next)) continue;
		ret += path(index + 1, next) % Mod;
	}
	return ret;
}

void input() {
	int testCase;
	cin >> testCase;
	for (int tc = 0; tc < testCase; ++tc) {
		cin >> N;
		memset(cache, -1, sizeof(cache));

		ll answer = 0;
		for (int number = 0; number <= 9; number++) {
			answer += path(1, number);
			answer %= Mod;
		}
		cout << answer << endl;
	}
}

int main() {
	fastio;
	input();
	
	return 0;
}