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

int N, K;
vector<int> ps;
bool visited[1000000 + 1];
int parent[3];

void input() {
	cin >> N >> K;
	ps = vector<int>(N, 0);
	for (int i = 0; i < N; i++) {
		cin >> ps[i];
	}
}

int solution() {
	int answer = INF;
	if (N == 1) {
		return (K == 1 && ps[0] == 1) ? 1 : -1;
	}
	int pl = 0, pr = 1;
	visited[0] = visited[1] = true;
	parent[ps[pl]]++;
	parent[ps[pr]]++;

	while (pl < pr) {
		if (parent[1] >= K) {
			answer = min(answer, pr - pl + 1);
			parent[ps[pl]]--;
			pl++;
			if (!visited[pl]) {
				visited[pl] = true;
				parent[ps[pl]]++;
			}
		}
		else {
			pr++;
			if (pr == N) break;
			if (!visited[pr]) {
				visited[pr] = true;
				parent[ps[pr]]++;
			}
		}
	}

	return answer == INF ? -1 : answer;
}

int main() {
	fastio;
	input();
	cout << solution() << endl;

	return 0;
}