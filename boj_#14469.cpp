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

int N;
vector<pair<int, int>> cow;

bool cmp(pair<int, int> lhs, pair<int, int> rhs) {
	if (lhs.first == rhs.first) {
		return lhs.second < rhs.second;
	}
	return lhs.first < rhs.first;
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int arriveTime, checkTime;
		cin >> arriveTime >> checkTime;
		cow.push_back({ arriveTime, checkTime });
	}
}

int solution() {
	int curTime = 0;
	sort(cow.begin(), cow.end(), cmp);

	for (auto& t : cow) {
		if (t.first < curTime) {
			curTime = max(curTime, curTime + t.second);
		}
		else {
			curTime = max(curTime, t.first + t.second);
		}
	}

	return curTime;
}

int main() {
	fastio;
	input();
	cout << solution() << endl;

	return 0;
}