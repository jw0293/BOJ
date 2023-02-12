#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e9+3
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef struct Info{
	int node1;
	int node2;
	int cost;
}Info;
struct cmp{
	bool operator()(Info lhs, Info rhs){
		return lhs.cost > rhs.cost;
	}
};

struct compare{
	bool operator()(Info lhs, Info rhs){
		return lhs.cost < rhs.cost;
	}
};

int N, M, cnt;
int parent[1000 + 1];
priority_queue<Info, vector<Info>, cmp> pq1;
priority_queue<Info, vector<Info>, compare> pq2;
vector<pair<int, int>> adj[1000 + 1];

void input(){
	cin >> N >> M;	
	int start, end, cost;
	for(int i=0;i<=M;i++){
		cin >> start >> end >> cost;
		adj[start].push_back({end, cost});
		adj[end].push_back({start, cost});

		pq1.push({start, end, cost});
		pq2.push({start, end, cost});
	}
}

void init(){
	for(int i=1;i<=N;i++) parent[i] = i;
}

int getParent(int x){
	if(x == parent[x]) return parent[x];
	return parent[x] = getParent(parent[x]);
}

bool isSame(int x, int y){
	return getParent(x) == getParent(y);
}

void unionNode(int x, int y){
	int px = getParent(x);
	int py = getParent(y);
	if(px < py){
		for(int i=1;i<=N;i++){
			if(parent[i] == py) parent[i] = px;
		}
	} else{
		for(int i=1;i<=N;i++){
			if(parent[i] == px) parent[i] = py;
		}
	}
}

int maxValue(){
	int count = 0;
	while(!pq1.empty()){
		Info cur = pq1.top();
		pq1.pop();

		if(isSame(cur.node1, cur.node2)) continue;

		unionNode(cur.node1, cur.node2);
		if(cur.cost == 0) count++;
	}
	return count;
}

int minValue(){
	int count = 0;
	while(!pq2.empty()){
		Info cur = pq2.top();
		pq2.pop();

		if(isSame(cur.node1, cur.node2)) continue;

		unionNode(cur.node1, cur.node2);
		if(cur.cost == 0) count++;
	}
	return count;
}

int solution(){
	init();
	int minV = minValue();
	init();
	int maxV = maxValue();

	return ((maxV * maxV) - (minV * minV));
}

int main(){
	fastio;
	input();
	cout << solution() << endl;

	return 0;
}