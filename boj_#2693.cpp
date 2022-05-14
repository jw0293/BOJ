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
#define Mod 1000000009
#define endl '\n'
#define pil pair<int,int>

using namespace std;

void input() {
	int testCase;
	cin >> testCase;
	
	while (testCase--) {
		vector<int> ps(10, 0);
		for (int i = 0; i < 10; i++) {
			cin >> ps[i];
		}
		sort(ps.begin(), ps.end());

		cout << ps[10 - 3] << endl;
	}
}

int main() {
	fastio;
	input();

	return 0;
}