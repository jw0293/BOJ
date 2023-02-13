#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e9+3
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int N, M;
int board[50 + 1][50 + 1];
int cache[50 + 1][50 + 1];

void input(){
	cin >> N >> M;
	string temp;
	for(int i=1;i<=N;i++){
		cin >> temp;
		for(int j=0;j<M;j++){
			if(temp[j] == '0') board[i][j+1] = 0;
			else board[i][j+1] = 1;
		}
	}
	for(int i=1;i<=N;i++){
		cin >> temp;
		for(int j=0;j<M;j++){
			if(temp[j] == '0') cache[i][j+1] = 0;
			else cache[i][j+1] = 1;
		}
	}
}

bool isSame(){
	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			if(board[i][j] != cache[i][j]) return false;
		}
	}
	return true;
}

bool isValid(int y, int x){
	if(1 > y || y > N || x < 1 || x > M) return false;
	if(1 > y + 2 || y + 2 > N || x + 2 < 1 || x + 2 > M) return false;
	return true;
}

bool isExist(int y, int x){
	for(int i=y;i<y+3;i++){
		for(int j=x;j<x+3;j++){
			if(board[i][j] != cache[i][j]) return true;
		}
	}
	return false;
}

void filp(int y, int x){
	for(int i=y;i<y+3;i++){
		for(int j=x;j<x+3;j++){
			board[i][j] = !board[i][j];
		}
	}
}

int solution(){
	int cnt = 0;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			if(!isValid(i, j)) continue;
			if(board[i][j] != cache[i][j]){
				filp(i, j);
				cnt++;
			}
		}
	}
	if(!isSame()) return -1;
	return cnt;
}

int main(){
	fastio;
	input();
	cout << solution() << endl;

	return 0;
}