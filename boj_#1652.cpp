#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e9+3
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int N;
bool visited[100 + 1][100 + 1];
int board[100 + 1][100 + 1];

void input(){
	cin >> N;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			char x;
			cin >> x;
			if(x == '.') board[i][j] = 0;
			else board[i][j] = -1;
		}
	}
}

bool isValid(int y, int x){
	return (1 <= y && y <= N && 1 <= x && x <= N);
}

int isCanWide(int y, int x){
	int cnt = 0, can = 0;
	for(int i=1;;i++){
		if(!isValid(y, x+i) || board[y][x+i] != 0 || visited[y][x+i]) break;
		cnt++;
		visited[y][x+i] = true;
	}
	if(cnt >= 2) can++;

	cnt = 0;
	for(int i=1;;i++){
		if(!isValid(y, x-i) || board[y][x-i] != 0 || visited[y][x-i]) break;
		cnt++;
		visited[y][x-i] = true;
	}
	if(cnt >= 2) can++;
	return can;
}

int isCanHigh(int y, int x){
	int cnt = 0, can = 0;
	for(int i=1;;i++){
		if(!isValid(y+i, x) || board[y+i][x] != 0 || visited[y+i][x]) break;
		cnt++;
		visited[y+i][x] = true;
	}
	if(cnt >= 2) can++;
	cnt = 0;
	for(int i=1;;i++){
		if(!isValid(y-i, x) || board[y-i][x] != 0 || visited[y-i][x]) break;
		visited[y-i][x] = true;
		cnt++;
	}
	if(cnt >= 2) can++;
	return can;
}

int isCanLongWide(int y){
	for(int i=1;i<=N;i++){
		if(board[y][i] != 0) return 0;
	}
	return 1;
}

int isCanLongHigh(int x){
	for(int i=1;i<=N;i++){
		if(board[i][x] != 0) return 0;
	}
	return 1;
}

pair<int, int> solution(){
	int wide = 0, high = 0;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			if(board[i][j] == -1){
				wide += isCanWide(i, j);
			}
		}
	}

	memset(visited, false, sizeof(visited));
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			if(board[i][j] == -1){
				high += isCanHigh(i, j);
			}
		}
	}
	if(N >= 2){
		for(int i=1;i<=N;i++){
			wide += isCanLongWide(i);
			high += isCanLongHigh(i);
		}
	}

	return {wide, high};
}

int main(){
	fastio;
	input();
	pair<int, int> answer = solution();
	cout << answer.first << " " << answer.second << endl;

	return 0;
}