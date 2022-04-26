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
#define Mod 1234567
#define endl '\n'
#define ENDL cout << endl

using namespace std;

int N;
int cache[10][3];

void input() {
	cin >> N;
}

int solve(int index, int number, int sum) {
	if (index == N) {
		if (sum % 3 == 0) return 1;
		return 0;
	}
	int& ret = cache[index][number];
	if (ret != -1) return ret;

	ret = 0;
	for (int i = 0; i < 3; i++) {
		ret += solve(index + 1, i, sum + i);
	}
	return ret;
}

int solution() {
	memset(cache, -1, sizeof(cache));
	return solve(1, 1, 1) + solve(1, 2, 2);
}

int main() {
	fastio;
	input();
	cout << solution() << endl;

	return 0;
}