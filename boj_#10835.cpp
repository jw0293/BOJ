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
int cache[2000 + 1][2000 + 1];

void split(vector<int>& v, string str) {
	string temp;
	for (auto t : str) {
		if (t == ' ') {
			v.push_back(stoi(temp));
			temp.clear();
		}
		else {
			temp += t;
		}
	}
	v.push_back(stoi(temp));
}

int path(vector<int>& lhs, vector<int>& rhs, int lhsIndex, int rhsIndex) {
	if (lhsIndex == lhs.size() || rhsIndex == rhs.size()) return 0;
	int& ret = cache[lhsIndex][rhsIndex];
	if (ret != -1) return ret;

	ret = 0;
	ret = max({ ret, path(lhs, rhs, lhsIndex + 1, rhsIndex), path(lhs, rhs, lhsIndex + 1, rhsIndex + 1) });
	if (lhs[lhsIndex] > rhs[rhsIndex]) {
		ret = max(ret, path(lhs, rhs, lhsIndex, rhsIndex + 1) + rhs[rhsIndex]);
	}
	return ret;
}

int solution(vector<int>& lhs, vector<int>& rhs) {
	memset(cache, -1, sizeof(cache));
	return path(lhs, rhs, 0, 0);
}

void input() {
	cin >> N;
	cin.ignore();
	string l, r;
	vector<int> lhs, rhs;

	getline(cin, l);
	getline(cin, r);

	split(lhs, l);
	split(rhs, r);

	cout << solution(lhs, rhs) << endl;
}

int main() {
	fastio;
	input();

	return 0;
}