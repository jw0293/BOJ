#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 987654321
#define endl '\n'

using namespace std;

int N, K;
vector<int> ps;
bool visited[150 + 1];

void input(){
    cin >> N >> K;
    ps.resize(N);
    for(int i=0;i<N;i++){
        cin >> ps[i];
    }
}

int path(int ptr, int count){
    if(visited[ptr]) return -1;
    if(ptr == K) return count;

    visited[ptr] = true;
    return path(ps[ptr], count+1);
}

int solution(){
    return path(ps[0], 1);
}

int main(){
    fastio;
    input();
    cout << solution() << endl;

    return 0;
}