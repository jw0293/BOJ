#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e9+3
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

struct compare{
	bool operator()(pair<int, int> &lhs, pair<int, int> &rhs){
		return lhs.first > rhs.first;
	}
};

int N, M, s, t;
int distances[5000 + 1];
vector<pair<int, int>> adj[5000 + 1];
priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;

void input(){
	cin >> N >> M;
	for(int i=0;i<M;i++){
		int from, to, cost;
		cin >> from >> to >> cost;
		adj[from].push_back({to, cost});
		adj[to].push_back({from, cost});
	}
	cin >> s >> t;
}

int solution(){
	memset(distances, INF, sizeof(distances));
	distances[s] = 0;
	pq.push({s, 0});

	while(!pq.empty()){
		int curNode = pq.top().first;
		int cost = pq.top().second;
		pq.pop();

		for(auto &next : adj[curNode]){
			if(cost + next.second < distances[next.first]){
				distances[next.first] = cost + next.second;
				pq.push({next.first, distances[next.first]});
			}
		}
	}
	return distances[t];
}

int main(){
	fastio;
	input();
	cout << solution() << endl;

	return 0;
}