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

int N, K, Q;
vector<int> ps;
int cache[20 + 1];

void input() {
	cin >> N >> K;
	ps = vector<int>(N + 2, 0);
	for (int i = 1; i <= N; i++) {
		cin >> ps[i];
	}
}

int path(int index, int sum) {
	if (index > N) return 0;
	int& ret = cache[index];
	if (ret != -1) return ret;

	ret = 0;
	if (sum >= K) {
		ret = max(ret, path(index + 1, ps[index + 1]) + sum - K);
	}
	else {
		ret = max(ret, path(index + 1, ps[index + 1]));
		ret = max(ret, path(index + 1, sum + ps[index + 1]));
	}

	return ret;
}

int solution() {
	memset(cache, -1, sizeof(cache));
	return path(1, ps[1]);
}

int main() {
	fastio;
	input();
	cout << solution() << endl;
	
	return 0;
}