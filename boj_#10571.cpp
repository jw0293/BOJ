#include <algorithm>
#include <iostream>
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
#define INF 987654321
#define Mod 1234567
#define endl '\n'
#define pil pair<int,int>

using namespace std;

typedef struct information {
	double first;
	double second;
}Information;

int N;
Information ps[300 + 1];
int cache[300 + 1];

int solution() {
	memset(cache, -1, sizeof(cache));
	int answer = 1;
	for (int index = 1; index <= N; index++) {
		cache[index] = 1;
		for (int prev = 1; prev < index; prev++) {
			if ((ps[prev].first < ps[index].first && ps[prev].second > ps[index].second)) {
				cache[index] = max(cache[index], cache[prev] + 1);
				answer = max(answer, cache[index]);
			}
		}
	}
	return answer;
}

void input() {
	int testCase;
	cin >> testCase;
	for (int tc = 0; tc < testCase; ++tc) {
		cin >> N;
		for (int i = 1; i <= N; i++) {
			cin >> ps[i].first >> ps[i].second;
		}
		
		cout << solution() << endl;
	}
}

int main() {
	fastio;
	input();
	
	return 0;
}