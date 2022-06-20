#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <set>
#include <map> 
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ENDL cout << endl
#define ll long long	
#define ull unsigned long long
#define INF 987654321
#define Mod 100000
#define endl '\n'
#define pil pair<int,int>

using namespace std;

int N;
ll cache[116 + 1];

void input() {
	cin >> N;
}

ll path(int index) {
	if (index == 1 || index == 2 || index == 3) return 1;
	ll& ret = cache[index];
	if (ret != -1) return ret;

	return ret = path(index - 1) + path(index - 3);
}

ll solution() {
	memset(cache, -1, sizeof(cache));
	cache[1] = cache[2] = cache[3] = 1;
	return path(N);
}

int main() {
	fastio;
	input();
	cout << solution() << endl;

	return 0;
}