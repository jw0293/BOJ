#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 987654321
#define endl '\n'

using namespace std;

int V, E;
int deg[200000 + 1];
bool oddPoint[200000 + 1];
bool visited[200000 + 1];
vector<int> adj[200000 + 1];

void input(){
    cin >> V >> E;
    for(int i=0;i<E;i++){
        int u, v;
        cin >> u >> v;

        deg[u]++; deg[v]++;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void dfs(vector<int> &odd, int node){
    if(visited[node]) return;

    visited[node] = true;
    if(deg[node] % 2) odd.push_back(node);
    for(auto &next :adj[node]){
        dfs(odd, next);
    }
}

int solution(){
    int answer = 0;
    for(int i=1;i<=V;i++){
        if(deg[i] == 0 || visited[i]) continue;
        vector<int> oddPoint;
        dfs(oddPoint, i);
        if(oddPoint.empty()) answer += 1;
        else {
            // cout << "-> " << oddPoint.size() << endl;
            answer += oddPoint.size() / 2;
        }
    }
    return answer;
}

int main(){
    fastio;
    input();
    cout << solution() << endl;

    return 0;
}