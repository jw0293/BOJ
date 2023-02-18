#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e6 + 3
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int MAX_N = 50000;
const int ROOT = 1;

int N, M;
bool visited[MAX_N+1];
int parent[MAX_N+1];
int depth[MAX_N+1];
vector<int> adj[MAX_N + 1];

void func(int prev, int cur, int dpth){
	parent[cur] = prev;
	visited[cur] = true;
	depth[cur] = dpth;

	for(auto &next : adj[cur]){
		if(!visited[next]){
			func(cur, next, dpth+1);
		}
	}
}

void init(){
	visited[ROOT] = true;
	for(auto &cur : adj[ROOT]){
		func(ROOT, cur, 2);
	}
}

void input(){
	cin >> N;
	for(int i=0;i<N-1;i++){
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
}

void getParent(int node){
	visited[node] = true;
	if(node == 1) return;

	getParent(parent[node]);
}

int getCommonParent(int node){
	if(visited[node]) return node;
	return getCommonParent(parent[node]);
}

void solution(){
	cin >> M;

	init();
	while(M--){
		int x, y, answer;
		cin >> x >> y;

		memset(visited, false, sizeof(visited));
		if(depth[x] < depth[y]){
			getParent(x);
			answer = getCommonParent(y);
		}
		else {
			getParent(y);
			answer = getCommonParent(x);
		}

		cout << answer << endl;
	}
}

int main(){
	fastio;
	input();
	solution();

	return 0;
}