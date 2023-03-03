#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e9 + 3
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int N, M;
const int MX = 100 + 1;
int board[MX][MX];
int cache[MX][MX];

void input(){
	cin >> N >> M;
	for(int i=1;i<=N;i++)
		fill(board[i], board[i]+1+N, INF);

	while(M--){
		int from, to, cost;
		cin >> from >> to >> cost;
		if(board[from][to] > cost) board[from][to] = cost;
		cache[from][to] = to;
	}
}

void printResult(){
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			if(board[i][j] == INF) cout << 0 << " ";
			else cout << board[i][j]  << " ";
		}
		cout << endl;
	}
}

void printPath(){
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			if(board[i][j] == 0 || board[i][j] == INF){
				cout << 0 << endl;
				continue;
			}

			vector<int> path;
			int st = i;
			while(st != j){
				path.push_back(st);
				st = cache[st][j];
			}
			path.push_back(j);

			cout << path.size() <<  " ";
			for(auto v : path) cout << v << " ";
			cout << endl;
		}
	}
}

void solution(){
	for(int i=1;i<=N;i++) board[i][i] = 0;
	for(int k=1;k<=N;k++){
		for(int i=1;i<=N;i++){
			for(int j=1;j<=N;j++){
				if(board[i][k] + board[k][j] < board[i][j]){
					board[i][j] = board[i][k] + board[k][j];
					cache[i][j] = cache[i][k];
				}
			}
		}
	}

	printResult();
	printPath();
}

int main(){
	fastio;
	input();
	solution();

	return 0;
}
