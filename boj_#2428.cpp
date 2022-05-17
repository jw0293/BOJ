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
vector<int> file;

void input() {
	cin >> N;
	file = vector<int>(N, 0);
	for (int i = 0; i < N; i++) {
		cin >> file[i];
	}
}

int integerFile(double file) {
	if ((file - (int)file) == 0) return int(file);
	return int(file + 1.0);
}

ll solution() {
	ll answer = 0;
	sort(file.begin(), file.end());
	for (int i = file.size() - 1; i >= 0; i--) {
		int xFile = integerFile(file[i] * 0.9);
		int pos = lower_bound(file.begin(), file.end(), xFile) - file.begin();

		if (!pos) {
			if (file[pos] >= file[i] * 0.9) {
				answer += (i - pos);
			}
		}
		else {
			answer += (i - pos);
		}
	}
	return answer;
}

int main() {
	fastio;
	input();
	cout << solution() << endl;

	return 0;
}