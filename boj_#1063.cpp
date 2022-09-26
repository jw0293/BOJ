#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define Mod 1000000007
#define endl '\n'

using namespace std;

int N;
int board[8 + 1][8 + 1];
vector<string> order;

pair<int, int> pos;
pair<int, int> stone;

const int dy[] = {0, 0, -1, 1, 1, 1, -1, -1};
const int dx[] = {1, -1, 0, 0, 1, -1, 1, -1};

void initPosition(string king, string st){
    pos.second = king[0]-'A'+1;
    pos.first = king[1]-'0';

    stone.second = st[0]-'A'+1;
    stone.first = st[1]-'0';
}

void input(){
    string posKing, posStone;
    cin >> posKing >> posStone >> N;

    initPosition(posKing, posStone);

    order.resize(N);
    for(int i=0;i<N;i++){
        cin >> order[i];
    }
}

int moveDir(string op){
    if(op == "R") return 0;
    if(op == "L") return 1;
    if(op == "B") return 2;
    if(op == "T") return 3;
    if(op == "RT") return 4;
    if(op == "LT") return 5;
    if(op == "RB") return 6;
    if(op == "LB") return 7;

    return -1;
}

bool isSamePos(int y, int x, int dir){
    int ny = y + dy[dir];
    int nx = x + dx[dir];

    if(ny == stone.first && nx == stone.second) return true;
    return false;
}

bool isValid(int y, int x, int dir){
    int ny = y + dy[dir];
    int nx = x + dx[dir];

    if(1 <= ny && ny <= 8 && 1 <= nx && nx <= 8) return true;
    return false;
}

void solution(){
    for(auto op : order){
        int y = pos.first;
        int x = pos.second;
        int dir = moveDir(op);
        
        if(isSamePos(y, x, dir)){
            if(!isValid(y+dy[dir], x+dx[dir], dir) || !isValid(y, x, dir)){
                continue;
            }
            else{
                pos.first = y + dy[dir];
                pos.second = x + dx[dir];

                stone.first = pos.first + dy[dir];
                stone.second = pos.second + dx[dir];
            }
        }
        else{
            if(!isValid(y, x, dir)){
                continue;
            }
            else{
                pos.first = y + dy[dir];
                pos.second = x + dx[dir];
            }
        }
    }

    cout << (char)(pos.second+'A'-1) << pos.first  << endl;
    cout << (char)(stone.second+'A'-1) << stone.first  << endl;
}

int main(){
    fastio;
    input();
    solution();

    return 0;
}