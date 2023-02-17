#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e6 + 3
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef struct Info{
	int y;
	int x;
	int ctime;
	int count;
	vector<vector<int>> tempBoard;
}Info;

bool isPossible = false;
int N, cnt, cy, cx, answer = INF;
int board[100 + 1][100 + 1], saveBoard[100 + 1][100 + 1];
bool visited[100 + 1][100 + 1];
const int dy[] = {-1, -1, 1, 1};
const int dx[] = {-1, 1, -1, 1};

queue<Info> q;

void input(){
	cin >> N;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			cin >> board[i][j];
			if(board[i][j] == 2) {
				cy = i;
				cx = j;
			} else if(board[i][j] == 1){
				cnt++;
			}
			saveBoard[i][j] = board[i][j];
		}
	}

}

bool isValid(int y, int x){
	return (1 <= y && y <= N && 1 <= x && x <= N);
}

void dfs(int y, int x, int cnt, int process){
	if(cnt == 0){	
		isPossible = true;
		answer = min(answer, process);
		return;
	}

	for(int i=0;i<4;i++){
		int ny = y + dy[i];
		int nx = x + dx[i];

		if(!isValid(ny, nx) || visited[ny][nx]) continue;

		visited[ny][nx] = true;
		if(board[ny][nx] == 1) {
			board[ny][nx] = 0;

			dfs(ny, nx, cnt-1, process+1);

			board[ny][nx] = 1;
		} else{
			dfs(ny, nx, cnt, process+1);
		}
		visited[ny][nx] = false;
	}
}

void solution(){
	dfs(cy, cx, cnt, 0);
	if(isPossible) cout << "Undertaker" << endl << answer << endl;
	else cout << "Shorei" << endl;
}

int main(){
	fastio;
	input();
	solution();

	return 0;
}