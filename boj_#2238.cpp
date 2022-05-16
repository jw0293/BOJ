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

int U, N;
int counting[10000 + 1];
vector<int> priceOp;
bool visited[10000 + 1];
vector<string> User[10000 + 1];

bool cmp(pair<int, int> lhs, pair<int, int> rhs) {
	if (lhs.second == rhs.second) {
		return lhs.first < rhs.first;
	}
	return lhs.second < rhs.second;
}

void input() {
	cin >> U >> N;
	int price;
	string name;
	for (int i = 0; i < N; i++) {
		cin >> name >> price;
		counting[price]++;

		priceOp.push_back(price);
		User[price].push_back(name);
	}
}

pair<string, int> solution() {
	vector<pair<int, int>> information;
	for (int i = 0; i < priceOp.size(); i++) {
		if (visited[priceOp[i]]) continue;

		visited[priceOp[i]] = true;
		information.push_back({ priceOp[i], counting[priceOp[i]] });
	}

	sort(information.begin(), information.end(), cmp);
	return { User[information[0].first][0],information[0].first };
}

int main() {
	fastio;
	input();
	pair<string, int> answer = solution();

	cout << answer.first << " " << answer.second;

	return 0;
}