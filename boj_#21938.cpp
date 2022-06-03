#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define endl '\n'

using namespace std;

typedef struct color{
    int red;
    int green;
    int blue;
}Color;

int N, M, T;
int cache[1000 + 1][1000 + 1];
Color board[1000 + 1][1000 + 1];
bool visited[1000 + 1][1000 + 1];
const int dy[] = {1, -1, 0, 0};
const int dx[] = {0, 0, 1, -1};

void input(){
    cin >> N >> M;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin >> board[i][j].red >> board[i][j].green >> board[i][j].blue;
        }
    }
    cin >> T;
}

void saveValue(){
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            int total = 0;
            total += board[i][j].red + board[i][j].green + board[i][j].blue;
            if(T <=total / 3) {
                cache[i][j] = 255;
            }
            else{
                cache[i][j] = 0;
            }
        }
    }
}

bool isValid(int y, int x){
    return (1 <= y && y <= N && 1 <= x && 1 <= M);
}

void spread(int y, int x){
    queue<pair<int, int>> q;
    q.push({y, x});

    while(!q.empty()){
        int curY = q.front().first;
        int curX = q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int ny = curY + dy[i];
            int nx = curX + dx[i];

            if(!isValid(ny, nx) || visited[ny][nx] || cache[ny][nx] != 255) continue;
            q.push({ny, nx});
            visited[ny][nx] = true;
        }
    }
}

int countX(){
    int answer = 0;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            if(!visited[i][j] && cache[i][j] == 255){
                visited[i][j] = true;
                answer++;
                spread(i, j);
            }
        }
    }
    return answer;
}

int solution(){
    saveValue();
    return countX();
}

int main(void){
    fastio;
    input();
    cout << solution() << endl;

    return 0;
}