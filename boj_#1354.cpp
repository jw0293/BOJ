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

ll N, Q, P, X, Y;
map<ll, ll> m;

void input() {
	cin >> N >> P >> Q >> X >> Y;
}

ll path(ll n, ll p, ll q) {
	if (n <= 0) return 1;
	ll& ret = m[n];
	if (ret != 0) return ret;
	return ret = path((n / p) - X, p, q) + path((n / q) - Y, p, q);
}

ll solution() {
	return path(N, P, Q);
}

int main() {
	fastio;
	input();
	cout << solution() << endl;

	return 0;
}