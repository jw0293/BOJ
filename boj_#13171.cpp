#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <string>
#include <cstring>
#include <set>
#include <map> 
#include <algorithm>
#include <cmath>
#include <ctime>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ENDL cout << endl
#define ll long long
#define ull unsigned long long
#define INF 987654321
#define Mod 1000000007
#define endl '\n'
#define pil pair<int,int>

using namespace std;

ll A, X;

void input() {
	cin >> A >> X;
}

ll power(ll op, ll exp) {
	if (exp == 1) return op;
	if (exp % 2 != 0) {
		return (op * power(op, exp - 1)) % Mod;
	}
	return (power(op, exp / 2) * power(op, exp / 2)) % Mod;
}

ll solution() {
	A %= Mod;
	return power(A, X) % Mod;
}

int main() {
	fastio;
	input();
	cout << solution() << endl;

	return 0;
}