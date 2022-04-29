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

int N, M, answer;
vector<int> v[30 + 1];
int prefer[30 + 1][30 + 1];

void input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> prefer[i][j];
		}
	}
}

void path(int index, int count) {
	if (count == 3) {
		int total = 0;
		for (int i = 1; i <= N; i++) {
			int s = 0;
			for (int j = 0; j < 3; j++) {
				s = max(s, v[i][j]);
			}
			total += s;
		}
		answer = max(answer, total);
		return;
	}

	for (int next = index + 1; next <= M; ++next) {
		for (int j = 1; j <= N; j++) {
			v[j].push_back(prefer[j][next]);
		}

		path(next, count + 1);

		for (int j = 1; j <= N; j++) {
			v[j].pop_back();
		}
	}
}

void solution() {
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			v[j].push_back(prefer[j][i]);
		}
		
		path(i, 1);
	
		for (int j = 1; j <= N; j++) {
			v[j].pop_back();
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