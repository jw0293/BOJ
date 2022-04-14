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

int N, sum;
vector<int> marble;
ll cache[10 + 1][10 + 1][10 + 1][10 + 1][10 + 1][5 + 1][5 + 1];

void input() {
	cin >> N;
	marble = vector<int>(6, 0);
	for (int i = 0; i < N; i++) {
		cin >> marble[i];
		sum += marble[i];
	}
}

ll path(int index, int curColor, int prevColor) {
	if (index == sum) return 1;
	ll& ret = cache[marble[0]][marble[1]][marble[2]][marble[3]][marble[4]][curColor][prevColor];
	if (ret != -1) return ret;

	ret = 0;
	for (int i = 0; i < N; i++) {
		if ((curColor != i && prevColor != i) && marble[i] != 0) {
			marble[i]--;

			ret += path(index + 1, i, curColor);

			marble[i]++;
		}
	}
	return ret;
}

ll solution() {
	memset(cache, -1, sizeof(cache));
	return path(0, 5, 5);
}

int main() {
	fastio;
	input();
	cout << solution() << endl;

	return 0;
}