#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 123456789
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
int N, M, K;
int path[300 + 1][300 + 1];
int cache[300 + 1][300 + 1];
vector<int> include[300 + 1];

void input(){
	cin >> N >> M >> K;
	for(int i=0;i<K;i++){
		int from, to, cost;
		cin >> from >> to >> cost;

		include[from].push_back(to);
		path[from][to] = max(path[from][to], cost);
	}
}

int dp(int start, int mid, int end, int cnt){
	if(cnt > M) return -INF;
	if(end == N && cnt <= M) return path[mid][end];
	int &ret = cache[mid][end];
	if(ret != -1) return ret;
	ret = 0;
	for(int i=0;i<include[end].size();i++){
		if(end > include[end][i]) continue;
		ret = max(ret, dp(start, end, include[end][i], cnt+1) + path[mid][end]);
	}
	return ret;
}

int solution(){
	int answer = 0;
	memset(cache, -1, sizeof(cache));
	for(int i=0;i<include[1].size();i++){
		answer = max(answer, dp(1, 1, include[1][i], 2));
	}
	return answer;
}

int main(){
	fastio;
	input();
	cout << solution() << endl;

	return 0;
}