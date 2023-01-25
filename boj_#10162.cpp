#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 123456789
#define endl '\n'

using namespace std;

typedef long long ll;

int T;

void input(){
	cin >> T;
}

vector<int> solution(){
	vector<int> answer;

	answer.push_back(T / 300);
	T %= 300;

	answer.push_back(T / 60);
	T %= 60;

	answer.push_back(T / 10);
	T %= 10;

	return answer;
}

int main() {
	fastio;
	input();
	if(T % 10 != 0) cout << -1 << endl;
	else{
		vector<int> result = solution();
		for(auto &p : result) cout << p << " ";
		cout << endl;
	}

	return 0;
}