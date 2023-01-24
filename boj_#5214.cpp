#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 123456789
#define endl '\n'

using namespace std;

typedef long long ll;
int N, K, M;
vector<vector<int>> hypertube;
vector<vector<int>> station;

void input(){
	cin >> N >> K >> M;
	station.resize(N + 1); 
	hypertube.resize(M + 1);

	for(int i=1;i<=M;i++){
		for(int j=0;j<K;j++){
			int node;
			cin >> node;

			hypertube[i].push_back(node);
			station[node].push_back(i);
		}
	}
}

int solution(){
	vector<int> visited(N + 1, -1);
	vector<int> visitedTube(M + 1, -1);
	queue<pair<int, int>> q;
	q.push({1, 1});
	visited[1] = 1;
	
	while(!q.empty()){
		int node = q.front().first;
		int dist = q.front().second;
		q.pop();

		if(node == N) return dist;

		for(int next=0;next<station[node].size();next++){
			int nextTube = station[node][next];
			if(visitedTube[nextTube] == -1){
				visitedTube[nextTube] = 1;
				for(int station=0;station<hypertube[nextTube].size();station++){
					int nextStation = hypertube[nextTube][station];
					if(visited[nextStation] == -1){
						visited[nextStation] = visited[node] + 1;
						q.push({nextStation, visited[nextStation]});
					}
				}
			}
		}
	}
	return -1;
}

int main() {
	fastio;
	input();
	cout << solution() << endl;

	return 0;
}