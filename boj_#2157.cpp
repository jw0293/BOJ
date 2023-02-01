#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e9+7;
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
int N, M, K;
int path[300 + 1][300 + 1];
int cache[300 + 1][300 + 1];
vector<pair<int, int>> include[300 + 1];

void input(){
	cin >> N >> M >> K;
	for(int i=0;i<K;i++){
		int from, to, cost;
		cin >> from >> to >> cost;
		if(from > to) continue;
		include[from].push_back({to, cost});
	}
}

int dp(int node, int cnt){
	int &ret = cache[node][cnt];
	if(ret != -1) return ret;
	if(node == N) return ret = 0;
	if(cnt >= M) return ret = -INF;
	ret = -INF;
	for(auto &next : include[node]){
		if(node > next.first) continue;
		ret = max(ret, dp(next.first, cnt+1) + next.second);
	}
	return ret;
}

int solution(){
	memset(cache, -1, sizeof(cache));
	return dp(1, 1);
}

int main(){
	fastio;
	input();
	cout << solution() << endl;

	return 0;
}