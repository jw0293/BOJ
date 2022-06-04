#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define endl '\n'

using namespace std;

int N, M, robotCnt, order, crashRobot;
int board[100 + 1][100 + 1];
vector<pair<pair<int, int>, int>> robot;
bool isCrashWall = false, isCrashRobot = false;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };

int returnDir(char dir) {
    if (dir == 'N') return 2;
    if (dir == 'E') return 1;
    if (dir == 'S') return 0;
    if (dir == 'W') return 3;
    return -1;
}

int changeDirRight(int dir) {
    if (dir == 0) return 3;
    return dir - 1;
}

int changeDirLeft(int dir) {
    if (dir == 3) return 0;
    return dir + 1;
}

void input() {
    cin >> N >> M;
    cin >> robotCnt >> order;
    for (int i = 0; i < robotCnt; i++) {
        int y, x; char dir;
        cin >> y >> x >> dir;
        robot.push_back({ {x, y}, returnDir(dir) });
        board[x][y] = i + 1;
    }
}

bool isValid(int y, int x) {
    return (1 <= y && y <= M && 1 <= x && x <= N);
}

bool isCrashOtherRobot(int y, int x) {
    return board[y][x] == 0 ? false : true;
}

void startMove(int robotNumber, char op, int cnt) {
    if (op == 'L' || op == 'R') {
        cnt %= 4;

        int dir = robot[robotNumber - 1].second;
        for (int i = 0; i < cnt; i++) {
            if (op == 'L') dir = changeDirLeft(dir);
            if (op == 'R') dir = changeDirRight(dir);
        }
        robot[robotNumber - 1].second = dir;
    }
    else {
        for (int i = 0; i < cnt; i++) {
            int y = robot[robotNumber - 1].first.first;
            int x = robot[robotNumber - 1].first.second;
            int dir = robot[robotNumber - 1].second;

            int ny = y + dy[dir];
            int nx = x + dx[dir];

            if (!isValid(ny, nx)) {
                isCrashWall = true;
                break;
            }
            if (isCrashOtherRobot(ny, nx)) {
                isCrashRobot = true;
                crashRobot = board[ny][nx];
                break;
            }

            board[y][x] = 0;
            board[ny][nx] = robotNumber;
            robot[robotNumber - 1].first.first = ny;
            robot[robotNumber - 1].first.second = nx;
        }
    }
}

void solution() {
    char op;
    int robotNumber, repeatCnt;

    vector<pair<int, pair<char, int>>> ps;
    for (int i = 0; i < order; i++) {
        cin >> robotNumber >> op >> repeatCnt;
        ps.push_back({ robotNumber, {op, repeatCnt} });
    }

    for (int i = 0; i < ps.size(); i++) {
        robotNumber = ps[i].first, op = ps[i].second.first, repeatCnt = ps[i].second.second;
        startMove(robotNumber, op, repeatCnt);

        if (isCrashWall == true) {
            cout << "Robot " << robotNumber << " crashes into the wall" << endl;
            exit(0);
        }
        if (isCrashRobot == true) {
            cout << "Robot " << robotNumber << " crashes into robot " << crashRobot << endl;
            exit(0);
        }
    }
    cout << "OK" << endl;
}

int main(void) {
    fastio;
    input();
    solution();

    return 0;
}