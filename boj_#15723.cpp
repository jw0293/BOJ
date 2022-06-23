#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define endl '\n'

using namespace std;

int N;
bool visited[26 + 1];
vector<int> adj[26 + 1];

void input(){
    cin >> N;
    cin.ignore();

    for(int i=0;i<N;i++){
        string info; 
        getline(cin, info);

        adj[info[0] - 'a' + 1].push_back(info[5] - 'a' + 1);
    }
}

bool isValid(int node1, int node2){
    queue<int> q;
    q.push(node1);
    
    memset(visited, false, sizeof(visited));
    visited[node1] = true;

    while(!q.empty()){
        int y = q.front();
        q.pop();

        if(y == node2) return true;

        for(auto &t : adj[y]){
            if(!visited[t]){
                visited[t] = true;
                q.push(t);
            }
        }
    }
    return false;
}

void solution(){
    int M; cin >> M;
    cin.ignore();

    for(int i=0;i<M;i++){
        string info;
        getline(cin, info);

        if(isValid(info[0] - 'a'  + 1, info[5] - 'a' + 1)) cout << "T" << endl;
        else cout << "F" << endl;
    }
}

int main(){
    fastio;
    input();
    solution();

    return 0;
}