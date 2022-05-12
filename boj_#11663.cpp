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

int N, M;
vector<int> pointq;
vector<pair<int, int>> line;

void input() {
	cin >> N >> M;
	pointq = vector<int>(N, 0);

	for (int i = 0; i < N; i++) {
		cin >> pointq[i];
	}
	
	for (int i = 0; i < M; i++) {
		int startPoint, endPoint;
		cin >> startPoint >> endPoint;
		line.push_back({ startPoint, endPoint });
	}
}

void solution() {
	sort(pointq.begin(), pointq.end());

	for (int i = 0; i < M; i++) {
		cout << upper_bound(pointq.begin(), pointq.end(), line[i].second) - lower_bound(pointq.begin(), pointq.end(), line[i].first) << endl;
	}
}

int main() {
	fastio;
	input();
	solution();

	return 0;
}