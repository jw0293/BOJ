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

int n, k, answer;
bool visited[10 + 1];
map<string, bool> cache;
vector<string> ps, temp;

void input() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		ps.push_back(s);
	}
}

void solve(int count) {
	if (count == k) {
		string isgoing;
		for (auto& t : temp) {
			isgoing += t;
		}
		if (cache[isgoing] == false) {
			cache[isgoing] = true;
			answer++;
		}
		return;
	}

	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			visited[i] = true;
			temp.push_back(ps[i]);

			solve(count + 1);

			visited[i] = false;
			temp.pop_back();
		}
	}
}

int solution() {
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			visited[i] = true;
			temp.push_back(ps[i]);

			solve(1);

			visited[i] = false;
			temp.pop_back();
		}
	}
	cout << answer << endl;
}

int main() {
	fastio;
	input();
	solution();

	return 0;
}