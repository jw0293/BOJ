#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 123456789
#define endl '\n'

using namespace std;

typedef long long ll;
typedef struct info{
	int y;
	int x;
	int dir;
	int cnt;
}Info;

int M, N, cy, cx, py, px, cdir, pdir;
int board[100 + 1][100 + 1];
int cache[100 + 1][100 + 1][4 + 1];
const pair<int, int> dyx[] = {
	{0, 0}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}
};

void input(){
	cin >> M >> N;
	for(int i=1;i<=M;++i){
		for(int j=1;j<=N;++j){
			cin >> board[i][j];
		}
	}

	cin >> cy >> cx >> cdir;
	cin >> py >> px >> pdir;
}

bool isValid(int y, int x){
	return (1 <= y && y <= M && 1 <= x && x <= N);
}

bool isValidDir(int y, int x, int dir){
	if(!isValid(y, x)) return false;
	int ny = y + dyx[dir].first;
	int nx = x + dyx[dir].second;
	if(board[ny][nx] == 1) return false;
	return true;
}

vector<int> getTurnDir(int dir){
	vector<int> res;
	if(dir == 1 || dir == 2){
		res.push_back(3);
		res.push_back(4);
	} else {
		res.push_back(1);
		res.push_back(2);
	}
	return res;
}

bool isValidArea(int y, int x, int dir, int len){
	for(int i=1;i<=len;i++){
		int ny = y + dyx[dir].first * i;
		int nx = x + dyx[dir].second * i;

		if(board[ny][nx] == 1) return false;
	}
	return true;
}

int solution(){
	queue<Info> q;
	q.push({cy, cx, cdir, 0});
	memset(cache, INF, sizeof(cache));

	cache[cy][cx][cdir] = 0;
	while(!q.empty()){
		Info cur = q.front();
		q.pop();

		if(cur.y == py && cur.x == px && cur.dir == pdir) return cur.cnt;

		for(int k=1;k<=3;k++){
			int ny = cur.y + dyx[cur.dir].first * k;
			int nx = cur.x + dyx[cur.dir].second * k;

			if(!isValidArea(cur.y, cur.x, cur.dir, k)) continue;
			if(isValid(ny, nx) && !board[ny][nx] && cache[ny][nx][cur.dir] > cur.cnt + 1){
				cache[ny][nx][cur.dir] = cur.cnt + 1;
				q.push({ny, nx, cur.dir, cur.cnt+1});
			}
		}

		vector<int> dirs = getTurnDir(cur.dir);
		for(int i=0;i<dirs.size();i++){
			if(cache[cur.y][cur.x][dirs[i]] > cur.cnt + 1){
				cache[cur.y][cur.x][dirs[i]] = cur.cnt + 1;
				q.push({cur.y, cur.x, dirs[i], cur.cnt+1});
			}
		}
	}
	return -1
}

int main() {
	fastio;
	input();
	cout << solution() << endl;
	
	return 0;
}