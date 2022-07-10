#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 987654321
#define endl '\n'

using namespace std;

typedef struct comp{
    int odd, even;
}comp;

int V, E;
int deg[1000 + 1];
bool visited[1000 + 1];
vector<int> adj[1000 + 1];

void input(){
    cin >> V >> E;
    for(int i=0;i<E;i++){
        int node1, node2;
        cin >> node1 >> node2;

        deg[node1]++; deg[node2]++;

        adj[node1].push_back(node2);
        adj[node2].push_back(node1);
    }
}

void dfs(comp &cur, int node){
    if(visited[node]) return;

    visited[node] = true;
    if(deg[node] % 2 == 0) cur.even++;
    else cur.odd++;

    for(auto &next : adj[node]){
        dfs(cur, next);
    }
}

void connect(comp &cmp){
    if(cmp.odd){
        cmp.odd--;
        cmp.even++;
    }
    else{
        cmp.even--;
        cmp.odd++;
    }
}

int linkSet(vector<comp> &cur){
    int cnt = 0;
    for(int i=0;i<cur.size()-1;i++){
        connect(cur[i]);
        connect(cur[i+1]);
        cnt++;
    }
    return cnt;
}

int solution(){
    vector<comp> component;
    for(int i=1;i<=V;i++){
        if(!visited[i]){
            comp cur = {0, 0};
            dfs(cur, i);
            component.push_back(cur);
        }
    }

    int setLink = linkSet(component);
    int odd = 0, even = 0;
    for(auto &cmp : component){
        odd += cmp.odd;
        even += cmp.even;
    }

    if(odd <= 2) return setLink;
    return (odd - 2) / 2 + setLink;
}

int main(){
    fastio;
    input();
    cout << solution() << endl;

    return 0;
}