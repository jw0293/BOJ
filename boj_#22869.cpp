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

int N, K;
vector<int> stone;
int cache[5000 + 1];

void input() {
	cin >> N >> K;
	stone = vector<int>(N + 1, 0);
	for (int i = 1; i <= N; i++) {
		cin >> stone[i];
	}
}

int path(int prev, int cur) {
	if (cur == N) return 1;
	int& ret = cache[cur];
	if (ret != -1) return ret;
	ret = 0;
	for (int next = cur + 1; next <= N; next++) {
		int power = (next - cur) * (1 + abs(stone[next] - stone[cur]));
		if(power <= K) ret = max(ret, path(cur, next));
	}
	return ret;
}

void solution() {
	memset(cache, -1, sizeof(cache));
	path(0, 1) == 1 ? cout << "YES\n" << endl : cout << "NO\n" << endl;
}

int main() {
	fastio;
	input();
	solution();

	return 0;
}