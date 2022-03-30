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
#define INF 987654321
#define mod 1000000007
#define endl '\n'

using namespace std;

int N;
ll cache[200000 + 1][2][8];

void input() {
	cin >> N;
}

ll path(int day, int yesterday,int today) {
	if (day == N) return 1;
	ll& ret = cache[day][yesterday][today];
	if (ret != -1) return ret;

	ret = 0;
	if (day == 0) {
		ret += path(day + 1, 0, 0) % mod;
		for (int i = 1; i <= 4; i++) {
			ret += path(day + 1, 1, i) % mod;
		}
	}
	else {
		if (yesterday == 1) {
			ret += path(day + 1, 0, today) % mod;
			for (int i = 1; i <= 4; i++) {
				if (i == today || i == today - 1 || i == today + 1) continue;
				ret += path(day + 1, 1, i) % mod;
			}
		}
		else {
			for (int i = 1; i <= 4; i++) {
				ret += path(day + 1, 1, i) % mod;
			}
		}
	}
	return ret % mod;
}

ll solution() {
	memset(cache, -1, sizeof(cache));
	return path(0, 0, 0);
}

int main() {
	fastio;
	input();
	cout << solution() << endl;

	return 0;
}