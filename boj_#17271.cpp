#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <string>
#include <cstring>
#include <climits>
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
#define INF 5000000001
#define mod 1000000007
#define endl '\n'

using namespace std;

int N, M;
ll cache[10000 + 1][2];

void input() {
	cin >> N >> M;
}

ll path(int time, int alpha) {
	if (time == 0) return 1;
	ll& ret = cache[time][alpha];
	if (ret != -1) return ret;
	ret = 0;
	ret += path(time - 1, 1) % mod;
	if (M <= time) ret += path(time - M, 0) % mod;
	return ret % mod;
}

ll solution() {
	memset(cache, -1, sizeof(cache));
	return path(N, 0) % mod;
}

int main() {
	fastio;
	input();
	cout << solution() << endl;

	return 0;
}