#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 987654321
#define endl '\n'

using namespace std;

int K, M, P;
vector<int> adj[1000 + 1];
int in[1000 + 1], level[1000 + 1];
bool visited[1000 + 1], update[1000 + 1];

void topologySort(queue<int> &q){
    while(!q.empty()){
        int cur = q.front();
        q.pop();

        for(auto &next : adj[cur]){
            if(!visited[next]){
                visited[next] = true;
                level[next] = level[cur];
            }
            else{
                if(level[next] == level[cur] && !update[next]) {
                    update[next] = true;
                    level[next] = level[cur] + 1;
                }
                else{
                    if(level[next] < level[cur]){
                        update[next] = false;
                        level[next] = level[cur];
                    }
                }
            }

            --in[next];
            if(!in[next]){
                q.push(next);
            }
        }
    }
}

pair<int, int> solution(int turn, int pos){
    queue<int> q;
    for(int i=1;i<=M;i++){
        if(!in[i]){
            q.push(i);
            level[i] = 1;
            visited[i] = true;
        }
    }
    topologySort(q);

    return {turn, level[pos]};
}

void clear(int node){
    memset(in, 0, sizeof(in));
    memset(visited, false, sizeof(visited));
    memset(update, false, sizeof(update));
    for(int i=0;i<node;i++){
        adj[i].clear();
    }
}

void input(){
    int testCase;
    cin >> testCase;

    while(testCase--){
        cin >> K >> M >> P;
        for(int i=0;i<P;i++){
            int from, to;
            cin >> from >> to;
            adj[from].push_back(to);
            in[to]++;
        }

        pair<int, int> answer = solution(K, M);
        cout << answer.first << " " << answer.second << endl;
        
        clear(M);
    }
}

int main(){
    fastio;
    input();

    return 0;
}