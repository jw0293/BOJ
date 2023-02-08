#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e9+3
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef struct Info{
	int y;
	int x;
	int cost;
}Info;

struct cmp{
	bool operator()(Info &lhs, Info &rhs){
		return lhs.cost > rhs.cost;
	}
};

int N, M;
priority_queue<Info, vector<Info>, cmp> pq;
int board[1000 + 1][1000 + 1];
int cost[1000 + 1][1000 + 1];
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};

void input(){
	cin >> N >> M;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			cin >> board[i][j];
		}
	}
}

bool isValid(int y, int x){
	return (1 <= y && y <= N && 1 <= x && x <= M);
}

void init(){
	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			cost[i][j] = INF;
		}
	}
	pq.push({1, 1, board[1][1]});
}

int solution(){
	if(board[1][1] == -1) return -1;
	
	init();
	while(!pq.empty()){
		int y = pq.top().y;
		int x = pq.top().x;
		int curCost = pq.top().cost;
		pq.pop();

		if(y == N && x == M) return curCost;

		for(int i=0;i<4;i++){
			int ny = y + dy[i];
			int nx = x + dx[i];

			if(!isValid(ny, nx) || board[ny][nx] == -1) continue;
			if(cost[y][x] > cost[ny][nx]) continue;
			if(board[ny][nx] == 0) {
				if(curCost < cost[ny][nx]){
					cost[ny][nx] =curCost;
					pq.push({ny, nx, curCost});
				}
			} else{
				if(board[ny][nx] == 1){
					if(1 + curCost < cost[ny][nx]) {
						cost[ny][nx] = curCost + 1;
						pq.push({ny, nx, cost[ny][nx]});
					}
				} else if(board[ny][nx] == 2){
					if(2 + curCost < cost[ny][nx]){
						cost[ny][nx] = curCost + 2;
						pq.push({ny, nx, cost[ny][nx]});
					}
				}
			}
		}
	}
	return -1;
}

int main(){
	fastio;
	input();
	cout << solution() << endl;

	return 0;
}