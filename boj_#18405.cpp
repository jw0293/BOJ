#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define endl '\n'

using namespace std;

int N, K, S, purposeX, purposeY;
int board[200 + 1][200 + 1];
const int dy[] = { 1, -1, 0, 0 };
const int dx[] = { 0, 0, 1, -1 };
vector<pair<int, int>> adj[1000 + 1];

void input() {
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> board[i][j];
            if (board[i][j] != 0) {
                adj[board[i][j]].push_back({ i, j });
            }
        }
    }
    cin >> S >> purposeY >> purposeX;
}

bool isValid(int y, int x) {
    return (1 <= y && y <= N && 1 <= x && x <= N);
}

void infectBirus(vector<pair<int, int>>& temp, int y, int x, int curNumber) {
    for (int d = 0; d < 4; d++) {
        int ny = y + dy[d];
        int nx = x + dx[d];

        if (!isValid(ny, nx) || board[ny][nx] != 0) continue;
        temp.push_back({ ny, nx });
        board[ny][nx] = curNumber;
    }
}

int solution() {
    while (S--) {
        for (int i = 1; i <= K; i++) {
            vector<pair<int, int>> temp;
            for (int j = 0; j < adj[i].size(); j++) {
                int y = adj[i][j].first;
                int x = adj[i][j].second;

                infectBirus(temp, y, x, i);
            }
            adj[i].clear();
            adj[i] = temp;
        }
    }

    return board[purposeY][purposeX];
}

int main(void) {
    fastio;
    input();
    cout << solution() << endl;

    return 0;
}