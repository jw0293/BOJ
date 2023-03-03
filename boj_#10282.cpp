#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e9 + 3
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int MX = 10000 + 3;

int N, D, C;
int d[MX];
vector<pair<int, int>> adj[MX];
bool visited[MX];

struct cmp{
	bool operator()(pair<int, int> &lhs, pair<int, int> &rhs){
		return lhs.second > rhs.second;
	}
};

void init(){
	memset(visited, false, sizeof(visited));
	for(int i=0;i<=N;i++){
		d[i] = INF;
	}
	for(int i=0;i<MX;i++){
		adj[i].clear();
	}
}

pair<int, int> solution(){
	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
	pq.push({C, 0});
	visited[C] = true;
	d[C] = 0;

	while(!pq.empty()){
		int cur = pq.top().first;
		int cost = pq.top().second;
		pq.pop();

		for(auto &nxt : adj[cur]){
			if(nxt.second + cost < d[nxt.first]){
				d[nxt.first] = nxt.second + cost;
				pq.push({nxt.first, d[nxt.first]});
			}
		}
	}

	int cnt = 0, ctime = 0;
	for(int i=1;i<=N;i++){
		if(d[i] != INF){
			cnt++;

			if(d[i] > ctime) ctime = d[i];
		}
	}

	return {cnt, ctime};
}

void input(){
	int testCase;
	cin >> testCase;
	while(testCase--){
		cin >> N >> D >> C;

		init();
		for(int i=0;i<D;i++){
			int a, b, cost;
			cin >> a >> b >> cost;

			adj[b].push_back({a, cost});
		}
		pair<int, int> answer = solution();
		cout << answer.first << " " << answer.second << endl;
	}
}

int main(){
	fastio;
	input();
	//solution();

	return 0;
}
