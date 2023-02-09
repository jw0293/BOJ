#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e9+3
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int N, Q;
bool visited[300 + 1];
vector<int> adj[300 + 1];
vector<pair<int, int>> line;

void init(){
	for(int i=1;i<line.size();i++){
		int stdStart = line[i].first, stdEnd = line[i].second;
		for(int j=1;j<line.size();j++){
			if(i==j) continue;
			if((line[j].first <= stdStart && stdStart <= line[j].second)
				|| (line[j].first <= stdEnd && stdEnd <= line[j].second)){
					adj[i].push_back(j);
					adj[j].push_back(i);
				}
		}
	}
}

void input(){
	cin >> N;
	line.resize(N+1);
	for(int i=1;i<=N;i++){
		cin >> line[i].first >> line[i].second;
	}
}

int getDepth(int start, int end){
	queue<pair<int, int>> q;
	q.push({start, 0});
	memset(visited, false, sizeof(visited));
	visited[start] = true;

	while(!q.empty()){
		int cur = q.front().first;
		int depth = q.front().second;
		q.pop();

		if(cur == end) return depth;

		for(auto &next : adj[cur]){
			if(!visited[next]){
				visited[next] = true;
				q.push({next, depth+1});
			}
		}
	}
	return -1;
}

void solution(){
	init();
	cin >> Q;
	while(Q--){
		int A, B;
		
		cin >> A >> B;
		cout << getDepth(A, B) << endl;
	}
}

int main(){
	fastio;
	input();
	solution();

	return 0;
}