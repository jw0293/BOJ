#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e6 + 3
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int MAX_N = 100000 + 1;

int N, M;
int depth[MAX_N];
bool visited[MAX_N];
int parent[MAX_N][30];
vector<int> adj[MAX_N];

void input(){
	cin >> N;
	for(int i=0;i<N-1;i++){
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
}

void dfs(int node, int dpth){
	visited[node] = true;
	depth[node] = dpth;

	for(auto &next : adj[node]){
		if(!visited[next]) {
			parent[next][0] = node;
			dfs(next, dpth+1);
		}
	}
}

void cache(){
	for(int j=1;j<30;j++){
		for(int i=1;i<=N;i++){
			parent[i][j] = parent[parent[i][j-1]][j-1];
		}
	}
}

void init(){
	dfs(1, 0);
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

	for(int i=29;i>=0;i--){
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

		cout << LCA(x, y) << endl;
	}
}

int main(){
	fastio;
	input();
	solution();

	return 0;
}