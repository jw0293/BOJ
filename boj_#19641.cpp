#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e6 + 3
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int N, cnt=1;
bool visited[200000 + 1];
pair<int, int> result[200000 + 1];
map<int, vector<int>> adj;

void input(){
	cin >> N;
	for(int i=0;i<N;i++){
		int root; cin >> root;
		while(1){
			int x; cin >> x;
			if(x == -1) break;
			adj[root].push_back(x);
		}
	}
}

bool isCanProcessing(int root){
	for(int i=0;i<adj[root].size();i++){
		if(!visited[adj[root][i]]) return true;
	}
	return false;
}

void dfs(int root){
	visited[root] = true;
	result[root].first = ++cnt;

	if(!isCanProcessing(root)) {
		result[root].second = ++cnt;
		return;
	}

	sort(adj[root].begin(), adj[root].end());
	for(int i=0;i<adj[root].size();i++){
		if(visited[adj[root][i]]) continue;
		dfs(adj[root][i]);
	}
	result[root].second = ++cnt;
}

void printResult(){
	for(int i=1;i<=N;i++){
		cout << i << " " << result[i].first << " " << result[i].second << endl;
	}
}

void solution(){
	int root;
	cin >> root;

	visited[root] = true;
	result[root].first = cnt;
	sort(adj[root].begin(), adj[root].end());
	for(int i=0;i<adj[root].size();i++){
		dfs(adj[root][i]);
	}
	result[root].second = ++cnt;

	printResult();
}

int main(){
	fastio;
	input();
	solution();

	return 0;
}