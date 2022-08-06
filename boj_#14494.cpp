#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define Mod 1000000007
#define endl '\n'

using namespace std;

int N, M;
long long cache[1000 + 1][1000 + 1];

void input(){
    cin >> N >> M;
}

bool isValid(int y, int x){
    return (1 <= y && y <= N && 1 <= x && x <= M);
}

long long path(int y, int x){
    if(!isValid(y, x)) return 0;
    if(y == N && x == M) return 1;
    long long &ret = cache[y][x];
    if(ret != -1) return ret;

    ret = 0;
    return ret += (path(y+1, x) + path(y, x+1) + path(y+1, x+1)) % Mod;
}

long long solution(){
    memset(cache, -1, sizeof(cache));
    return path(1, 1) % Mod;
}   

int main(){
    fastio;
    input();
    cout << solution() << endl;

    return 0;
}