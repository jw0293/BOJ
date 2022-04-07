#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <cmath>
#define INF 9876543210
#define ENDL cout << endl;
#define endl '\n'
#define swap(type, x, y) do{type t=y;y=x;x=t;}while(0)
using namespace std;

typedef long long ll;
typedef pair<int, int> pl;

// BOJ :: https://www.acmicpc.net/problem/19236
// 맵에 저장할 정보 1. 물고기가 존재하는지, 2. 물고기 번호, 3. 물고기의 방향성

struct infor {
	bool isFish;
	int Number;
	int Direct;
};

struct d {
	int y;
	int x;
};

struct position {
	int y, x;
	bool islive;
};

infor adj[4][4], copy_adj[50][4][4];
bool Die[17];
const d Dir[9] = { {0,0}, {-1,0}, {-1,-1}, {0,-1}, {1,-1}, {1,0}, {1,1}, {0,1}, {-1,1} };
position pos[17];

// 벡터에 상어 정보를 담는다
vector<pair<int, pair<int, int>>> v;
int Answer, Sum;

void Copy(int depth) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			copy_adj[depth][i][j] = adj[i][j];
		}
	}
}

void Reverse(int depth) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			adj[i][j] = copy_adj[depth][i][j];
		}
	}
}

void Reverse_Pos(int depth) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			pos[copy_adj[depth][i][j].Number].y = i;
			pos[copy_adj[depth][i][j].Number].x = j;
		}
	}
}

bool isValid(int y, int x) {
	return (0 <= y && y < 4 && 0 <= x && x < 4);
}

void Input() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int Num, Dir;
			cin >> Num >> Dir;
			adj[i][j].isFish = true;
			adj[i][j].Number = Num;
			adj[i][j].Direct = Dir;

			pos[Num].y = i;
			pos[Num].x = j;
			pos[Num].islive = true;
		}
	}

	// 초기에 상어가 (0,0) 물고기를 먹고 그 방향을 가지는 사실은 변하지 않는다.
	v.push_back({ adj[0][0].Direct, {0,0} });
	Die[adj[0][0].Number] = true;
	pos[adj[0][0].Number].islive = false;
	adj[0][0].isFish = false;

	Sum = adj[0][0].Number;
}

bool isCan_SharkMove() {
	int y = v.back().second.first;
	int x = v.back().second.second;
	int dir = v.back().first;

	for (int i = 1; i <= 3; i++) {
		int ny = y + (Dir[dir].y * i);
		int nx = x + (Dir[dir].x * i);

		if (isValid(ny, nx) && adj[ny][nx].isFish) {
			return true;
		}
	}
	return false;
}

void Fish_Move() {
	int shark_y = v.back().second.first;
	int shark_x = v.back().second.second;
	for (int i = 1; i <= 16; i++) {
		// 상어한테 먹혀 존재하지 않는 물고기는 건너띄어줍니다
		if (Die[i] == true) continue;
		// 물고기 번호에 저장해놓은 좌표로 방향과 위치를 불러옵니다
		int y = pos[i].y;
		int x = pos[i].x;
		int d = adj[y][x].Direct;
		int count = 8;
		while (count--) {
			int ny = y + Dir[d].y;
			int nx = x + Dir[d].x;

			// 해당 범위 밖이거나
			if (!isValid(ny, nx)) {
				d++;
				if (d == 9) d = 1;
				continue;
			}
			// 해당 범위 안이지만 그 위치에 상어가 존재하는 경우에 방향을 돌려줍니다
			else if (shark_y == ny && shark_x == nx) {
				d++;
				if (d == 9) d = 1;
				continue;
			}
			// 모두 해당 되지 않으면 그 위치에 있는 물고기와 위치를 바꿔줍니다
			else {
				adj[y][x].Direct = d;
				int Temp_y = pos[i].y, Temp_x = pos[i].x;
				pos[i].y = pos[adj[ny][nx].Number].y;
				pos[i].x = pos[adj[ny][nx].Number].x;

				pos[adj[ny][nx].Number].y = Temp_y;
				pos[adj[ny][nx].Number].x = Temp_x;
				swap(infor, adj[y][x], adj[ny][nx]);

				break;
			}
		}
	}
}


void func(int depth, int total) {
	// 물고기 이동
	Fish_Move();

	// 상어가 이동할 수 있는 다음 위치들에 물고기가 존재하는지 확인
	if (!isCan_SharkMove()) {
		Answer = max(Answer, total);
		return;
	}
	// 물고기가 이동한 형태의 맵을 저장해준다
	Copy(depth);

	int y = v.back().second.first;
	int x = v.back().second.second;
	int dir = v.back().first;
	for (int i = 1; i <= 3; i++) {
		int ny = y + (Dir[dir].y * i);
		int nx = x + (Dir[dir].x * i);

		if (isValid(ny, nx) && adj[ny][nx].isFish) {
			v.push_back({ adj[ny][nx].Direct, {ny, nx} });
			adj[ny][nx].isFish = false;
			Die[adj[ny][nx].Number] = true;
			pos[adj[ny][nx].Number].islive = false;
			total += adj[ny][nx].Number;

			func(depth + 1, total);

			// 맵을 전 상태로 돌려놓습니다
			Reverse(depth);
			// 물고기 위치를 전 상태로 돌려놓습니다
			Reverse_Pos(depth);

			v.pop_back();
			adj[ny][nx].isFish = true;
			Die[adj[ny][nx].Number] = false;
			pos[adj[ny][nx].Number].islive = true;
			total -= adj[ny][nx].Number;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	Input();
	func(0, Sum);
	cout << Answer << endl;

	return 0;
}