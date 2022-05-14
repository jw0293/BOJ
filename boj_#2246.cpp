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

int N;
vector<pair<int, int>> information;

void input() {
	cin >> N;
	int dist, pay;
	for (int i = 0; i < N; i++) {
		cin >> dist >> pay;
		information.push_back({ dist, pay });
	}
}

bool isFirstCondition(int index) {
	for (int i = 0; i < N; i++) {
		if (i == index) continue;
		if (information[i].first < information[index].first) {
			if (information[i].second <= information[index].second) {
				return false;
			}
		}
	}
	return true;
}

bool isSecondCondition(int index) {
	for (int i = 0; i < N; i++) {
		if (i == index) continue;
		if (information[i].second < information[index].second) {
			if (information[i].first <= information[index].first) {
				return false;
			}
		}
	}
	return true;
}

int solution() {
	int answer = 0;
	for (int i = 0; i < information.size(); i++) {
		if (!isFirstCondition(i)) continue;
		if (!isSecondCondition(i)) continue;
		answer++;
	}
	return answer;
}

int main() {
	fastio;
	input();
	cout << solution() << endl;

	return 0;
}