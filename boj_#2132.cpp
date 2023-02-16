#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e6 + 3
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int N, ptr;
ll maxV = -1, ret = -1;
int apple[10000 + 1];
bool visited[10000 + 1];
vector<pair<int, ll>> answer;
vector<int> starts;
vector<int> adj[10000 + 1];

void input(){
	cin >> N;
	for(int i=1;i<=N;i++){
		cin >> apple[i];
	}
	for(int i=0;i<N-1;i++){
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
}

void dfs(int node, ll cost){
	if(maxV < cost){
		maxV = cost;
		starts.clear();
		starts.push_back(node);
	} else if(maxV == cost){
		starts.push_back(node);
	}

	visited[node] = true;
	for(auto &next : adj[node]){
		if(!visited[next]){
			dfs(next, cost + apple[next]);
		}
	}
}

void result(int start, int node, ll cost){
	if(ret < cost){
		ret = cost;
		answer.clear();
		
		if(start > node) answer.push_back({node, start});
		else answer.push_back({start, node});
	} else if(ret == cost){
		if(start > node) answer.push_back({node, start});
		else answer.push_back({start, node});
	}

	visited[node] = true;
	for(auto &next : adj[node]){
		if(!visited[next]) result(start, next, cost + apple[next]);
	}
}

void solution(){
	dfs(1, apple[1]);
	for(auto &cur : starts){
		//cout << "-> " << cur << endl;
		memset(visited, false, sizeof(visited));
		result(cur, cur, apple[cur]);
	}
	sort(answer.begin(), answer.end());
	cout << ret << " " << answer[0].first << endl;
}

int main(){
	fastio;
	input();
	solution();

	return 0;
}