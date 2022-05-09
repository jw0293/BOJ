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
#define INF 987654321
#define Mod 1000000009
#define endl '\n'
#define ENDL cout << endl

using namespace std;

int N, M;
int cache[10 + 1][30 + 1];

void input() {
	cin >> N;
	cin >> M;
}

int path(int index, int count) {
	if (!count) {
		if (index < N) return 0;
		return 1;
	}
	if (index == N) return 0;
	int& ret = cache[index][count];
	if (ret != -1) return ret;

	ret = 0;
	return ret += path(index, count - 1) + path(index + 1, count - 1);
}

int solution() {
	memset(cache, -1, sizeof(cache));
	return path(0, M);
}

int main() {
	fastio;
	input();
	cout << solution() << endl;

	return 0;
}