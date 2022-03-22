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
#define inf 987654321
#define mod 1000000007
#define endl '\n'

using namespace std;

int N, M;
vector<int> ps;
int cache[2000 + 1][2000 + 1];

void input() {
	cin >> N;
	ps = vector<int>(N + 1, 0);
	for (int i = 1; i <= N; i++) {
		cin >> ps[i];
	}
}

int isPalindrome(int start, int end) {
	int pl = start, pr = end;
	while (pl <= pr) {
		if (ps[pl] != ps[pr]) return 0;
		pl++;
		pr--;
	}
	return 1;
}

void solution() {
	cin >> M;
	memset(cache, -1, sizeof(cache));
	while (M--) {
		int from, to;
		cin >> from >> to;
		int& ret = cache[from][to];
		if (ret == -1) ret = isPalindrome(from, to);
		cout << ret << endl;
	}
}

int main() {
	fastio;
	input();
	solution();

	return 0;
}