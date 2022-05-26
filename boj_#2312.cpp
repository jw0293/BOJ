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
#define Mod 1000000003
#define endl '\n'
#define ENDL cout << endl

using namespace std;

int prime[100000 + 1];
int counting[100000 + 1];

void postInit() {
	for (int i = 1; i <= 100000; i++) {
		prime[i] = i;
	}

	for (int i = 2; i <= 100000; i++) {
		for (int j = i + i; j <= 100000; j += i) {
			if (!prime[j]) continue;
			prime[j] = 0;
		}
	}
}

vector<int> solution(int x) {
	vector<int> chk;
	for (int i = 2; i <= 100000; i++) {
		if (!prime[i] || x % i != 0) continue;
		chk.push_back(i);
		while (1) {
			if (!x || x % i != 0) break;
			x /= i;
			counting[i]++;
		}
	}
	return chk;
}

void sortAndPrint(vector<int> &ps) {
	sort(ps.begin(), ps.end());
	for (auto& ptr : ps) {
		cout << ptr << " " << counting[ptr] << endl;
	}
}

void input() {
	int testCase;
	cin >> testCase;

	postInit();
	int number;
	while (testCase--) {
		cin >> number;

		memset(counting, 0, sizeof(counting));
		vector<int> chkNum = solution(number);
		sortAndPrint(chkNum);
	}
}


int main() {
	fastio;
	input();

	return 0;
}