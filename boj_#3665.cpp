#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 123456789
#define endl '\n'

using namespace std;

typedef long long ll;

int N, M;
int inDegree[500 + 1];
map<int, bool> visited;
vector<int> seen, order;
vector<vector<int>> adj;

void makeGraph(const vector<int> &ps){
	adj.clear();
	adj.resize(N+1, vector<int>(N+1, 0));
	for(int i=0;i<ps.size()-1;i++){
		for(int j=i+1;j<ps.size();j++){
			adj[ps[i]][ps[j]] = 1;
			inDegree[ps[i]]++;
		}
	}
}

void reverseRank(){
	cin >> M;
	for(int i=0;i<M;i++){
		int a, b;
		cin >> a >> b;

		if(adj[a][b]) {
			adj[a][b] = 0;
			inDegree[a]--;
			adj[b][a] = 1;
			inDegree[b]++;
		} else{
			adj[b][a] = 0;
			inDegree[b]--;
			adj[a][b] = 1;
			inDegree[a]++;
		}
	}
}

void solutionQueue(){
	queue<int> q;
	for(int i=1;i<=N;i++){
		if(!inDegree[i]){
			q.push(i);
		}
	}
	
	vector<int> orders;
	while(!q.empty()){
		if(q.size() > 1) {
			cout << "?" << endl;
			return;
		}
		int here = q.front();
		q.pop();
		orders.push_back(here);

		for(int there = 1; there <= N; ++there){
			if(adj[there][here]){
				inDegree[there]--;
				if(!inDegree[there]){
					q.push(there);
				}
			}
		}
	}
	reverse(orders.begin(), orders.end());
	if(orders.size() != N){
		cout << "IMPOSSIBLE" << endl;
		return;
	}

	for(auto &t : orders){
		cout << t << " ";
	}
	cout << endl;
}

void input(){
	int testCase;
	cin >> testCase;

	while(testCase--){
		cin >> N;
		vector<int> ps(N, 0);
		for(int i=0;i<N;i++){
			cin >> ps[i];
		}

		memset(inDegree, 0, sizeof(inDegree));
		makeGraph(ps);
		reverseRank();
		solutionQueue();
	}
}

int main() {
	fastio;
	input();

	return 0;
}