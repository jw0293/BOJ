#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define endl '\n'

using namespace std;

int N, M, totalLower, totalUpper;
bool visited[99 + 1];
vector<int> adj[99 + 1][2];
bool checked[99 + 1][99 + 1];

void input(){
    cin >> N >> M;
    for(int i=0;i<M;i++){
        int upper, lower;
        cin >> upper >> lower;
        
        if(!checked[upper][lower]){
            checked[upper][lower] = true;
            adj[upper][0].push_back(lower);
        }
        if(!checked[lower][upper]){
            checked[lower][upper] = true;
            adj[lower][1].push_back(upper);
        } 
    }
}

void findAllLowerWeight(int index){
    if(adj[index][0].size() == 0) return;
    
    visited[index] = true;
    for(auto &t : adj[index][0]){
        if(!visited[t]){
            totalLower++;
            visited[t] = true;
            findAllLowerWeight(t);
        }
    }
}

void findAllUpperWeight(int index){
    if(adj[index][1].size() == 0) return;
    
    visited[index] = true;
    for(auto &t : adj[index][1]){
        if(!visited[t]){
            totalUpper++;
            visited[t] = true;
            findAllUpperWeight(t);
        }
    }
}

int solution(){
    int answer = 0;
    for(int i=1;i<=N;i++){
        totalLower = totalUpper = 0;

        memset(visited, false, sizeof(visited));
        findAllLowerWeight(i);

        memset(visited, false, sizeof(visited));
        findAllUpperWeight(i);

        if(totalLower > ((int)(N/2)) || totalUpper > ((int)(N/2))) {
            answer++;
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