#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define Mod 1000000007
#define endl '\n'

using namespace std;

int N, M;
vector<int> adj[100000 + 1];
long long cache[100000 + 1][7 + 1];

void input(){
    cin >> N >> M;
    for(int i=0;i<M;i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

long long path(int index, int length){
    if(length == 7) return 1;
    long long &ret = cache[index][length];
    if(ret != -1) return ret;
    ret = 0;
    for(auto &next : adj[index]){
        ret += path(next, length+1) % Mod;
    }
    return ret % Mod;
}

long long solution(){
    memset(cache, -1, sizeof(cache));
    long long answer = 0;
    for(int i=1;i<=N;i++){
        answer += path(i, 0) % Mod;
    }
    return answer % Mod;
}

int main(){
    fastio;
    input();
    cout << solution() << endl;

    return 0;
}