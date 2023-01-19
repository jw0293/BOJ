#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 123456789
#define endl '\n'

using namespace std;

typedef long long ll;

int N, M, answer = INF;
int board[20 + 1][20 + 1];
int cy1, cx1, cy2, cx2;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, -1, 0, 1};

void input(){
	cin >> N >> M;

	bool isFirst = false;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			char ch;
			cin >> ch;
			if(ch == 'o'){
				if(!isFirst) {
					isFirst = true;
					cy1 = i, cx1 = j;
				}
				else {
					cy2 = i, cx2 = j;
				}
			} else if(ch == '.'){
				board[i][j] = 0;
			} else{
				board[i][j] = -1;
			}
		}
	}
}

bool isValid(int y, int x){
	return (1 <= y && y <= N && 1 <= x && x <= M);
}

void depth(int y1, int x1, int y2, int x2, int cnt, int dir){
	if(answer < cnt || cnt > 10) return;

	int ny1 = y1 + dy[dir];
	int nx1 = x1 + dx[dir];

	int ny2 = y2 + dy[dir];
	int nx2 = x2 + dx[dir];

	if(!isValid(ny1, nx1) && !isValid(ny2, nx2)) return;
	else if((!isValid(ny1, nx1) && isValid(ny2, nx2)) ||
				(isValid(ny1, nx1) && !isValid(ny2, nx2))){
		answer = min(answer, cnt);
		return;
	}

	if(board[ny1][nx1] == -1) {
		ny1 = y1;
		nx1 = x1;
	}
	if(board[ny2][nx2] == -1){
		ny2 = y2;
		nx2 = x2;
	}

	for(int i=0;i<4;i++){
		depth(ny1, nx1, ny2, nx2, cnt+1, i);
	}
}

int solution(){
	for(int i=0;i<4;i++){
		depth(cy1, cx1, cy2, cx2, 1, i);
	}
	return answer > 10 ? -1 : answer;
}

int main() {
	fastio;
	input();
	cout << solution() << endl;
	
	return 0;
}