#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e18 + 3
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef struct Info{
	int countJ;
	int countO;
	int countI;
}Info;

const int MAX_N = 1000 + 1;

int N, M, K;
char board[MAX_N][MAX_N];
Info cache[MAX_N][MAX_N];

void input(){
	int temp;
	cin >> N >> M >> K;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			cin >> board[i][j];
			if(board[i][j] == 'J') {
				cache[i][j].countJ = cache[i-1][j].countJ + cache[i][j-1].countJ - cache[i-1][j-1].countJ + 1;
				cache[i][j].countO = cache[i-1][j].countO + cache[i][j-1].countO - cache[i-1][j-1].countO;
				cache[i][j].countI = cache[i-1][j].countI + cache[i][j-1].countI - cache[i-1][j-1].countI;
				
			}
			else if(board[i][j] == 'O') {
				cache[i][j].countJ = cache[i-1][j].countJ + cache[i][j-1].countJ - cache[i-1][j-1].countJ;
				cache[i][j].countO = cache[i-1][j].countO + cache[i][j-1].countO - cache[i-1][j-1].countO + 1;
				cache[i][j].countI = cache[i-1][j].countI + cache[i][j-1].countI - cache[i-1][j-1].countI;
			}
			else if(board[i][j] == 'I') {
				cache[i][j].countJ = cache[i-1][j].countJ + cache[i][j-1].countJ - cache[i-1][j-1].countJ;
				cache[i][j].countI = cache[i-1][j].countI + cache[i][j-1].countI - cache[i-1][j-1].countI + 1;
				cache[i][j].countO = cache[i-1][j].countO + cache[i][j-1].countO - cache[i-1][j-1].countO;
			}
		}
	}
}

Info gridSum(int y1, int x1, int y2, int x2){
	Info ret = cache[y2][x2];
	if(y1 > 0) {
		ret.countJ -= cache[y1-1][x2].countJ;
		ret.countI -= cache[y1-1][x2].countI;
		ret.countO -= cache[y1-1][x2].countO;
	}
	if(x1 > 0) {
		ret.countJ -= cache[y2][x1-1].countJ;
		ret.countO -= cache[y2][x1-1].countO;
		ret.countI -= cache[y2][x1-1].countI;
	}
	if(y1 > 0 && x1 > 0) {
		ret.countJ += cache[y1-1][x1-1].countJ;
		ret.countI += cache[y1-1][x1-1].countI;
		ret.countO += cache[y1-1][x1-1].countO;
	}
	return ret;
}

void solution(){
	while(K--){
		int y1, x1, y2, x2;
		cin >> y1 >> x1 >> y2 >> x2;

		Info result = gridSum(y1, x1, y2, x2);
		cout << result.countJ << " " << result.countO << " " << result.countI << endl;
	}
}

int main(){
	fastio;
	input();
	solution();

	return 0;
}