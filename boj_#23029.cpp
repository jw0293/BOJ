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
vector<int> food;
int cache[100000 + 1];

void input() {
	cin >> N;
	food = vector<int>(N + 1, 0);
	for (int i = 1; i <= N; i++) {
		cin >> food[i];
	}
}

int path(int index, int ps) {
	if (index > N) return 0;
	int& ret = cache[index];

	ret = 0;
	if (food[index] == 0) ret = path(index + 1, 0);
	else {
		if (ps == 0) {
			ret = path(index + 1, 0);
			ret = max(ret, path(index + 1, 1) + food[index]);
		}
		else if (ps == 1) {
			ret = path(index + 1, 0);
			ret = max(ret, path(index + 1, 2) + int(food[index] / 2));
		}
		else {
			ret = max(ret, path(index + 1, 0));
		}
	}
	return ret;
}

int solution() {
	memset(cache, -1, sizeof(cache));
	return path(1, 0);
}

int main() {
	fastio;
	input();
	cout << solution() << endl;

	return 0;
}