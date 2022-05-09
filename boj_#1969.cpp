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

int N, M;
int alpha[1000 + 1][1000 + 1];
vector<string> ps;

void input() {
	cin >> N >> M;
	string s;
	for (int i = 0; i < N; i++) {
		cin >> s;
		ps.push_back(s);
	}
}

void solution() {
	string hammingString;
	int answerDistance = 0;
	for (int i = 0; i < M; i++) {
		int tempAlpha = 0;
		vector<char> ch;
		for (int j = 0; j < N; j++) {
			alpha[i][ps[j][i] - 'A']++;
			if (tempAlpha < alpha[i][ps[j][i] - 'A']) {
				tempAlpha = alpha[i][ps[j][i] - 'A'];
				if (!ch.empty()) ch.clear();
				ch.push_back(ps[j][i]);
			}
			else if (tempAlpha == alpha[i][ps[j][i] - 'A']) {
				ch.push_back(ps[j][i]);
			}
		}
		sort(ch.begin(), ch.end());
		hammingString.push_back(ch[0]);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < ps[i].size(); j++) {
			if (hammingString[j] == ps[i][j]) continue;
			answerDistance++;
		}
	}

	cout << hammingString << endl << answerDistance;
}

int main() {
	fastio;
	input();
	solution();

	return 0;
}