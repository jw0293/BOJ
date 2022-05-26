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

string to_N;
int N, K, answer;
vector<int> st, temp;

void input() {
	cin >> N >> K;
	st = vector<int>(K, 0);
	for (int i = 0; i < K; i++) {
		cin >> st[i];
	}
}

int returnValue() {
	int value = 0;
	for (int i = 0; i < temp.size(); i++) {
		value *= 10;
		value += temp[i];
	}
	return value;
}

void func() {
	int tempInteger = returnValue();
	if (temp.size() < to_N.size()) {
		answer = max(answer, tempInteger);
	}
	if (temp.size() == to_N.size()) {
		if (tempInteger <= stoi(to_N)) {
			answer = max(answer, tempInteger);
		}
		return;
	}

	for (int i = 0; i < K; i++) {
		temp.push_back(st[i]);

		func();

		temp.pop_back();
	}
}

void solution() {
	to_N = to_string(N);
	sort(st.begin(), st.end());
	for (int i = 0; i < K; i++) {
		temp.push_back(st[i]);

		func();

		temp.pop_back();
	}
	cout << answer << endl;
}

int main() {
	fastio;
	input();
	solution();

	return 0;
}