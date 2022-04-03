#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <climits>
#include <set>
#include <map> 
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ENDL cout << endl
#define ll long long	
#define ull unsigned long long
#define INF 987654321
#define Mod 1000000
#define endl '\n'
#define pil pair<int,int>

using namespace std;

int board[10][10];
bool Row[10][10], Col[10][10], Sqare[15][10];

int returnArea(int y, int x) {
	if (1 <= y && y <= 3) {
		if (1 <= x && x <= 3) return 1;
		if (4 <= x && x <= 6) return 2;
		if (7 <= x && x <= 9) return 3;
	}
	else if (4 <= y && y <= 6) {
		if (1 <= x && x <= 3) return 4;
		if (4 <= x && x <= 6) return 5;
		if (7 <= x && x <= 9) return 6;
	}
	else {
		if (1 <= x && x <= 3) return 7;
		if (4 <= x && x <= 6) return 8;
		if (7 <= x && x <= 9) return 9;
	}
}

void reverse(int y, int x, int value) {
	Row[y][value] = !Row[y][value];
	Col[x][value] = !Col[x][value];
	Sqare[returnArea(y, x)][value] = !Sqare[returnArea(y, x)][value];
}

void input() {
	for (int i = 1; i <= 9; i++) {
		string s; cin >> s;
		for (int j = 0; j < s.length(); j++) {
			board[i][j + 1] = s[j] - '0';
			if (board[i][j + 1] != 0) {
				Row[i][board[i][j + 1]] = true;
				Col[j + 1][board[i][j + 1]] = true;
				Sqare[returnArea(i, j + 1)][board[i][j + 1]] = true;
			}
		}
	}
}

bool isValid(int y, int x, int value) {
	return (!Row[y][value] && !Col[x][value] && !Sqare[returnArea(y, x)][value]);
}


void go(int y, int x) {
	if (y == 10) {
		for (int i = 1; i <= 9; i++) {
			for (int j = 1; j <= 9; j++) {
				cout << board[i][j];
			}
			ENDL;
		}
		exit(0);
	}


	if (board[y][x] != 0) {
		x == 9 ? go(y + 1, 1) : go(y, x + 1);
	}
	else {
		for (int i = 1; i <= 9; i++) {
			if (!isValid(y, x, i)) continue;
			board[y][x] = i;
			reverse(y, x, i);

			x == 9 ? go(y + 1, 1) : go(y, x + 1);

			board[y][x] = 0;
			reverse(y, x, i);
		}
	}
}


int main() {
	fastio;
	input();
	go(1, 1);

	return 0;
}