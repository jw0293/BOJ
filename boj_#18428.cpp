#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e9+3
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int N;
string answer = "NO";
vector<pair<int, int>> teacher;
int board[6 + 1][6 + 1];
bool visited[6 + 1][6 + 1];
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};

void input(){
	cin >> N;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			char c; cin >> c;
			if(c == 'T') {
				teacher.push_back({i, j});
				board[i][j] = 1;
			}
			else if(c == 'S') board[i][j] = 7;
		}
	}
}

bool isValid(int y, int x){
	return (1 <= y && y <= N && 1 <= x && x <= N);
}

bool isCanHide(){
	for(auto &cur : teacher){
		int y = cur.first;
		int x = cur.second;

		bool isFindStudent = false;
		for(int i=0;i<4;i++){
			for(int j=1;;j++){
				int ny = y + dy[i] * j;
				int nx = x + dx[i] * j;

				if(!isValid(ny, nx)) break;
				if(board[ny][nx] == -1) break;
				if(board[ny][nx] == 7) {
					isFindStudent = true;
					break;
				}
			}
			if(isFindStudent) return false;
		}
	}
	return true;
}

void dfs(vector<pair<int, int>> &temp){
	if(temp.size() == 3){
		if(isCanHide()) answer = "YES";
		return;
	}

	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			if(board[i][j] == 0 && !visited[i][j]){
				visited[i][j] = true;
				board[i][j] = -1;
				temp.push_back({i, j});

				dfs(temp);

				if(answer == "YES") break;

				visited[i][j] = false;
				board[i][j] = 0;
				temp.pop_back();
			}
		}
		if(answer == "YES") break;
	}
}

string solution(){
	vector<pair<int, int>> temp;
	dfs(temp);
	return answer;
}

int main(){
	fastio;
	input();
	cout << solution() << endl;

	return 0;
}