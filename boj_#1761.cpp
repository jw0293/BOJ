#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e6 + 3
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int ROOT = 1;
const int MAX_N = 40000 + 1;

int N, M;
int depth[MAX_N];
bool visited[MAX_N];
int parent[MAX_N][16];
ll dist[MAX_N];
vector<pair<int, int>> adj[MAX_N];

void input(){
	cin >> N;
	for(int i=0;i<N-1;i++){
		int x, y, cost;
		cin >> x >> y >> cost;
		adj[x].push_back({y, cost});
		adj[y].push_back({x, cost});
	}
}

void dfs(int node, int dpth, ll cost){
	dist[node] = cost;
	visited[node] = true;
	depth[node] = dpth;

	for(auto &next : adj[node]){
		if(!visited[next.first]) {
			parent[next.first][0] = node;
			dfs(next.first, dpth+1, cost + next.second);
		}
	}
}

void cache(){
	for(int j=1;j<16;j++){
		for(int i=1;i<=N;i++){
			parent[i][j] = parent[parent[i][j-1]][j-1];
		}
	}
}

void init(){
	dfs(1, 0, 0);
	cache();
}

int LCA(int u, int v){
	if(depth[u] < depth[v]) swap(u, v);
	int diff = (depth[u] - depth[v]);
	for(int i=0;diff;i++){
		if(diff & 1) u = parent[u][i];
		diff >>= 1;
	}
	
	if(u == v) return u;

	for(int i=15;i>=0;i--){
		if(parent[u][i] != parent[v][i]) u = parent[u][i], v = parent[v][i];
	}

	return parent[u][0];
}

void solution(){
	init();

	cin >> M;
	while(M--){
		int x, y;
		cin >> x >> y;

		int lca = LCA(x, y);
		cout << (dist[x] - dist[lca]) + (dist[y] - dist[lca]) << endl;
	}
}

int main(){
	fastio;
	input();
	solution();

	return 0;
}