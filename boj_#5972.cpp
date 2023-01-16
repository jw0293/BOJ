#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 123456789
#define endl '\n'

using namespace std;

typedef long long ll;

int N, M;
int distances[50000 + 1];
vector<pair<int, int>> adj[50000 + 1];

void input(){
	cin >> N >> M;
	for(int i=0;i<M;i++){
		int nodeA, nodeB, len;
		cin >> nodeA >> nodeB >> len;
		adj[nodeA].push_back({nodeB, len});
		adj[nodeB].push_back({nodeA, len});
	}
}

int solution(int start){
	memset(distances, INF, sizeof(distances));
	priority_queue<pair<int, int>> pq;

	pq.push({0, start});
	distances[start] = 0;

	while(!pq.empty()){
		int dist = -pq.top().first;
		int node = pq.top().second;
		pq.pop();

		
		if(distances[node] < dist) continue;

		for(int i=0;i<adj[node].size();i++){
			int cost = dist + adj[node][i].second;
			if(cost < distances[adj[node][i].first]){
				distances[adj[node][i].first] = cost;
				pq.push({-cost, adj[node][i].first});
			}
		}
	}
}

int main() {
	fastio;
	input();
	solution(1);
	
	return 0;
}