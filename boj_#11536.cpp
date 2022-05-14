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

vector<string> input() {
	int N;
	cin >> N;
	vector<string> name;
	for (int i = 0; i < N; i++) {
		string s; cin >> s;
		name.push_back(s);
	}
	return name;
}

string solution(vector<string>& name) {
	int index = 0;
	vector<string> temp = name;
	sort(temp.begin(), temp.end());

	bool isIncreasing = false;
	for (int i = 0; i < temp.size(); i++) {
		if (name[i] != temp[i]) {
			isIncreasing = true;
			break;
		}
	}
	if (!isIncreasing) return "INCREASING";

	bool isDecreasing = false;
	for (int i = temp.size() - 1; i >= 0; i--) {
		if (name[index++] != temp[i]) {
			isDecreasing = true;
			break;
		}
	}
	if (!isDecreasing) return "DECREASING";

	return "NEITHER";
}

int main() {
	fastio;
	vector<string> name = input();
	cout << solution(name) << endl;

	return 0;
}