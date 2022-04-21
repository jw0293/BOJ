#include<iostream>
#include<cmath>
#include<list>
#include<stack>
#include<tuple>
#include<cstring>
#include<map>
#include<algorithm>
#include<vector>
#include<deque>
#include<queue>
#define CUNLINK ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define endl '\n'
#define MAX_SIZE 1003
#define INF 0x7fffffff
using namespace std;
typedef long long ll;

int N, maxV;
int board[21][21];
bool visited[21][21];
int Cboard[10][21][21];

void Input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> board[i][j];
		}
	}
}

void Copy(int depth) {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			Cboard[depth][i][j] = board[i][j];
		}
	}
}

void Reverse(int depth) {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			board[i][j] = Cboard[depth][i][j];
		}
	}
}

void Down() {
	for (int i = 1; i <= N; i++) {
		for (int j = N - 1; j >= 1; j--) {
			if (board[j][i] == 0) continue;
			else {
				if (board[j + 1][i] == 0) {
					int y = j + 1;
					while (y <= N && board[y][i] == 0) {
						board[y][i] = board[y - 1][i];
						board[y - 1][i] = 0;
						y++;
					}
					if (y <= N && board[y][i] == board[y - 1][i] && !visited[y][i]) {
						visited[y][i] = true;
						board[y][i] += board[y - 1][i];
						board[y - 1][i] = 0;
					}
				}
				else {
					if (board[j][i] != board[j + 1][i]) continue;
					else {
						if (!visited[j + 1][i]) {
							visited[j + 1][i] = true;
							board[j + 1][i] += board[j][i];;
							board[j][i] = 0;
						}
					}
				}
			}
		}
	}
}

void Up() {
	for (int i = 1; i <= N; i++) {
		for (int j = 2; j <= N; j++) {
			if (board[j][i] == 0) continue;
			else {
				if (board[j - 1][i] == 0) {
					int y = j - 1;
					while (y >= 1 && board[y][i] == 0) {
						board[y][i] = board[y + 1][i];
						board[y + 1][i] = 0;
						y--;
					}
					if (y >= 1 && board[y][i] == board[y + 1][i] && !visited[y][i]) {
						visited[y][i] = true;
						board[y][i] += board[y + 1][i];
						board[y + 1][i] = 0;
					}
				}
				else {
					if (board[j][i] != board[j - 1][i]) continue;
					else {
						if (!visited[j - 1][i]) {
							visited[j - 1][i] = true;
							board[j - 1][i] += board[j][i];;
							board[j][i] = 0;
						}
					}
				}
			}
		}
	}
}

void Right() {
	for (int i = 1; i <= N; i++) {
		for (int j = N - 1; j >= 1; j--) {
			if (board[i][j] == 0) continue;
			else {
				if (board[i][j + 1] == 0) {
					int x = j + 1;
					while (x <= N && board[i][x] == 0) {
						board[i][x] = board[i][x - 1];
						board[i][x - 1] = 0;
						x++;
					}
					if (x <= N && board[i][x] == board[i][x - 1] && !visited[i][x]) {
						visited[i][x] = true;
						board[i][x] += board[i][x - 1];
						board[i][x - 1] = 0;
					}
				}
				else {
					if (board[i][j] != board[i][j + 1]) continue;
					else {
						if (!visited[i][j + 1]) {
							visited[i][j + 1] = true;
							board[i][j + 1] += board[i][j];
							board[i][j] = 0;
						}
					}
				}
			}
		}
	}
}

void Left() {
	for (int i = 1; i <= N; i++) {
		for (int j = 2; j <= N; j++) {
			if (board[i][j] == 0) continue;
			else {
				if (board[i][j - 1] == 0) {
					int x = j - 1;
					while (x >= 1 && board[i][x] == 0) {
						board[i][x] = board[i][x + 1];
						board[i][x + 1] = 0;
						x--;
					}
					if (x >= 1 && board[i][x] == board[i][x + 1] && !visited[i][x]) {
						visited[i][x] = true;
						board[i][x] += board[i][x + 1];
						board[i][x + 1] = 0;
					}
				}
				else {
					if (board[i][j] != board[i][j - 1]) continue;
					else {
						if (!visited[i][j - 1]) {
							visited[i][j - 1] = true;
							board[i][j - 1] += board[i][j];
							board[i][j] = 0;
						}
					}
				}
			}
		}
	}
}

void Move(int dir) {
	memset(visited, false, sizeof(visited));
	switch (dir) {
	case 0:
		Down();
		break;
	case 1:
		Up();
		break;
	case 2:
		Right();
		break;
	case 3:
		Left();
		break;
	}
}

int FindMaxValue() {
	int mV = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			mV = max(mV, board[i][j]);
		}
	}
	return mV;
}

void func(int depth) {
	maxV = max(maxV, FindMaxValue());
	if (depth == 5) return;

	for (int i = 0; i < 4; i++) {
		Copy(depth);
		Move(i);
		func(depth + 1);
		Reverse(depth);
	}
}

int main() {
	CUNLINK;
	Input();
	func(0);
	cout << maxV << endl;

	return 0;
}