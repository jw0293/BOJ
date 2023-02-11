#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e9+3
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int N, M, cnt;
bool isBack = false;
char board[1000 + 1][1000 + 1];
int visited[1000 + 1][1000 + 1];
const int dy[] = {1, -1, 0, 0};
const int dx[] = {0, 0, -1, 1};

int getDir(char x){
	if(x == 'U') return 1;
	if(x == 'D') return 0;
	if(x == 'L') return 2;
	return 3;
}

void input(){
	cin >> N >> M;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			cin >> board[i][j];
		}
	}	
}

void dfs(int y, int x){
	if(visited[y][x] != -1 && visited[y][x] < cnt) {
		cnt--;
		isBack = true;
		return;
	}
	if(visited[y][x] == cnt) return;
	visited[y][x] = cnt;

	int dir = getDir(board[y][x]);
	dfs(y + dy[dir], x + dx[dir]);
	if(isBack) visited[y][x] = cnt;
}

int solution(){
	memset(visited, -1, sizeof(visited));
	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			if(visited[i][j] == -1){
				cnt++;
				isBack = false;
				dfs(i, j);
			}
		}
	}
	return cnt;
}

int main(){
	fastio;
	input();
	cout << solution() << endl;

	return 0;
}