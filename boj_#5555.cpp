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
string str;

void input() {
	cin >> str;
	cin >> N;
}

bool isIncludeStr(string &ps) {
	for (int i = 0; i < ps.size(); i++) {
		if (str[0] == ps[i]) {
			int index = i;
			bool isFind = true;
			for (int j = 0; j < str.size(); j++) {
				if (str[j] != ps[index]) {
					isFind = false;
					break;
				}
				index++;
				if (index == ps.size()) {
					index = 0;
				}
			}
			if (isFind) return true;
		}
	}
	return false;
}

int solution() {
	string s; 
	int answer = 0;
	for (int i = 0; i < N; i++) {
		cin >> s;
		if (isIncludeStr(s)) {
			answer++;
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