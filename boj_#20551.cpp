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
vector<int> initArray;

void input() {
	cin >> N >> M;
	initArray = vector<int>(N, 0);
	for (int i = 0; i < N; i++) {
		cin >> initArray[i];
	}
}

void solution() {
	sort(initArray.begin(), initArray.end());
	for (int i = 0; i < M; i++) {
		int findNum; 
		cin >> findNum;

		if (!binary_search(initArray.begin(), initArray.end(), findNum)) {
			cout << -1 << endl;
		}
		else {
			cout << lower_bound(initArray.begin(), initArray.end(), findNum) - initArray.begin() << endl;
		}
	}
}

int main() {
	fastio;
	input();
	solution();

	return 0;
}