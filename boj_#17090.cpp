#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e9+3
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int N, M;
int cache[500 + 1][500 + 1];
char board[500 + 1][500 + 1];
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int getDirIndex(char dir){
	if(dir == 'U') return 0;
	if(dir == 'R') return 1;
	if(dir == 'D') return 2;
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

bool isValid(int y, int x){
	return (1 <= y && y <= N && 1 <= x && x <= M);
}

int path(int y, int x){
	if(!isValid(y, x)) return 1;
	int &ret = cache[y][x];
	if(ret != -1) return ret;

	ret = 0;
	int dir = getDirIndex(board[y][x]);
	int ny = y + dy[dir];
	int nx = x + dx[dir];
	return ret += path(ny, nx);
}

int solution(){
	int answer = 0;
	memset(cache, -1, sizeof(cache));
	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			answer += path(i, j);
		}
	}
	return answer;
}

int main(){
	fastio;
	input();
	cout << solution() << endl;

	return 0;
}