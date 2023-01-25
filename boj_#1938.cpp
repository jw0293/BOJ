#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 123456789
#define endl '\n'

using namespace std;

typedef long long ll;
typedef struct Info{
	int y;
	int x;
	int rotation;
	int cnt;
}Info;

int N, py, px, pRotation;
char init[50 + 1][50 + 1];
int cache[50 + 1][50 + 1];
int board[50 + 1][50 + 1][1 + 1];
const pair<int, int> dir[] = {{0, 0}, {-1, 0}, {1, 0}, {0, -1}, {0, 1}};
queue<Info> q;

void makeBoard(){
	bool findB = false;
	bool findE = false;
	memset(board, INF, sizeof(board));
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			if(init[i][j] == '1') {
				cache[i][j] = -1;
			} else if(init[i][j] == 'B' && !findB){
				findB = true;
				if(init[i+1][j] == 'B'){
					q.push({i+1, j, 1, 0});
					board[i+1][j][1] = 0;
				}
				if(init[i][j+1] == 'B'){
					q.push({i, j+1, 0, 0});
					board[i][j+1][0] = 0;
				}
			} else if(init[i][j] == 'E' && !findE){
				findE = true;
				if(init[i+1][j] == 'E'){
					py = i+1;
					px = j;
					pRotation = 1;
				}
				if(init[i][j+1] == 'E'){
					py = i;
					px = j+1;
					pRotation = 0;
				}
			}
		}
	}
}

void input(){
	cin >> N;
	char ch;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			cin >> init[i][j];
		}
	}
}

bool isValid(int y, int x){
	return (1 <= y && y <= N && 1 <= x && x <= N);
}

bool isValidMove(int y, int x, int rotation, int moveDir){
	// 가로방향으로 통나무가 존재할 경우
	if(!rotation){
		if(moveDir == 1){
			for(int i=x-1;i<=x+1;i++){
				if(!isValid(y-1, i)) return false;
				if(cache[y-1][i] == -1) return false;
			}
		} else if(moveDir == 2){
			for(int i=x-1;i<=x+1;i++){
				if(!isValid(y+1, i)) return false;
				if(cache[y+1][i] == -1) return false;
			}
		} else if(moveDir == 3){
			for(int i=x-2;i<=x;i++){
				if(!isValid(y, i)) return false;
				if(cache[y][i] == -1) return false;
			}
		} else{
			for(int i=x;i<=x+2;i++){
				if(!isValid(y, i)) return false;
				if(cache[y][i] == -1) return false;
			}
		}
	} else{
		if(moveDir == 1){
			for(int i=y-2;i<=y;i++){
				if(!isValid(i, x)) return false;
				if(cache[i][x] == -1) return false;
			} 
		} else if(moveDir == 2){
			for(int i=y;i<=y+2;i++){
				if(!isValid(i, x)) return false;
				if(cache[i][x] == -1) return false;
			}
		} else if(moveDir == 3){
			for(int i=y-1;i<=y+1;i++){
				if(!isValid(i, x-1)) return false;
				if(cache[i][x-1] == -1) return false;
			}
		} else{
			for(int i=y-1;i<=y+1;i++){
				if(!isValid(i, x+1)) return false;
				if(cache[i][x+1] == -1) return false;
			}
		}
	}
	return true;
}

bool isValidRotation(int y, int x, int rotation){
	for(int i=y-1;i<=y+1;i++){
		for(int j=x-1;j<=x+1;j++){
			if(!isValid(i, j)) return false;
			if(cache[i][j] == -1) return false;
		}
	}
	return true;
}

int solution(){
	makeBoard();
	while(!q.empty()){
		Info cur = q.front();
		q.pop();

		if(cur.y == py && cur.x == px && cur.rotation == pRotation){
			return cur.cnt;
		}

		for(int i=1;i<=4;i++){
			int ny = cur.y + dir[i].first;
			int nx = cur.x + dir[i].second;
			if(isValidMove(cur.y, cur.x, cur.rotation, i)
				&& cur.cnt + 1 < board[ny][nx][cur.rotation]){
				q.push({ny, nx, cur.rotation, cur.cnt+1});
				board[ny][nx][cur.rotation] = cur.cnt+1;
			}
		}

		if(isValidRotation(cur.y, cur.x, cur.rotation)
			&& cur.cnt + 1 < board[cur.y][cur.x][!cur.rotation]){
			q.push({cur.y, cur.x, !cur.rotation, cur.cnt+1});
			board[cur.y][cur.x][!cur.rotation] = cur.cnt+1;
		}
	}

	return 0;
}

int main() {
	fastio;
	input();
	cout << solution() << endl;

	return 0;
}