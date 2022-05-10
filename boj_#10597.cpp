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

string str;
int sizeOfstr;
bool visited[51];

void input() {
	cin >> str;
	if (str.size() <= 9) sizeOfstr = str.size();
	else {
		sizeOfstr = 9 + ((str.size() - 9) / 2);
	}
}

bool isValid(int x) {
	return (1 <= x && x <= sizeOfstr);
}

void func(int idx, string s) {
	if (idx == str.size()) {
		cout << s << endl;
		exit(0);
	}

	s += " ";
	string temp = "";
	for (int i = idx; i < str.size(); i++) {
		temp += str[i];
		if (!isValid(stoi(temp))) return;
		if (!visited[stoi(temp)]) {
			visited[stoi(temp)] = true;

			func(i + 1, s + temp);


			visited[stoi(temp)] = false;
		}
	}
}

void solution() {
	string Temp = "";
	for (int i = 0; i < str.size(); i++) {
		Temp += str[i];
		if (isValid(stoi(Temp)) && !visited[stoi(Temp)]) {
			visited[stoi(Temp)] = true;

			func(i + 1, Temp);

			visited[stoi(Temp)] = false;
		}
	}
}

int main() {
	fastio;
	input();
	solution();

	return 0;
}