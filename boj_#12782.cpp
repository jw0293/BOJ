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
#define ENDL cout << endl
#define ll long long	
#define ull unsigned long long
#define INF LLONG_MAX-1
#define Mod 1234567
#define endl '\n'
#define pil pair<int,int>

using namespace std;

int N;

int solution(string& s1, string& s2) {
	int oneToZero = 0;
	int zeroToOne = 0;
	for (int i = 0; i < s1.size(); i++) {
		if (s1[i] == s2[i]) continue;
		if (s1[i] == '1') oneToZero++;
		else zeroToOne++;
	}

	if (oneToZero < zeroToOne) return oneToZero + (zeroToOne - oneToZero);
	else if (oneToZero > zeroToOne) return zeroToOne + (oneToZero - zeroToOne);
	else return oneToZero;
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		string s1, s2;
		cin >> s1 >> s2;
		cout << solution(s1, s2) << endl;
	}
}

int main() {
	fastio;
	input();
	
	return 0;
}