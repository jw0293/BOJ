#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e6 + 3
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int N, M;
bool isComplete = false;
int wallStartY, wallStartX, wallEndY, wallEndX;
int board[1000 + 1][1000 + 1];
int cache[1000 + 1][1000 + 1];

bool isValid(int y, int x){
	return (1 <= y && y <= N && 1 <= x && x <= M);
}

bool isPossible(int py, int px, int cy, int cx){
	if(wallStartY == wallEndY && wallStartX == wallEndX) return true;
	if(wallStartY == wallEndY){
		if(px+1 == cx) return true;
		if((wallStartX < px && px <= wallEndX) && py == wallStartY && cy == wallStartY+1) return false;
	} else{
		if(py+1 == cy) return true;
		if((wallStartY < py && py <= wallEndY) && px == wallStartX && cx == wallStartX+1) return false;
	}
	return true;
}

void input(){
	cin >> N >> M;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			cin >> board[i][j];
		}
	}
	cin >> wallStartY >> wallStartX >> wallEndY >> wallEndX;
	
	if(wallStartY > wallEndY) swap(wallStartY, wallEndY);
	if(wallStartX > wallEndX) swap(wallStartX, wallEndX);
}

int path(int y, int x){
	if(y == N && x == M) {
		isComplete = true;
		return board[y][x];
	}
	int &ret = cache[y][x];
	if(ret != -1) return ret;
	ret = -100000001;
	if(isValid(y+1, x) && isPossible(y, x, y+1, x)) ret = max(ret, path(y+1, x) + board[y][x]);
	if(isValid(y, x+1) && isPossible(y, x, y, x+1)) ret = max(ret, path(y, x+1) + board[y][x]);
	return ret;
}

int solution(){
	memset(cache, -1, sizeof(cache));
	int answer = path(1, 1);
	if(!isComplete) return -1;
	return answer;
}

int main(){
	fastio;
	input();
	int result = solution();
	if(result == -1) cout << "Entity" << endl;
	else cout << result << endl;

	return 0;
}