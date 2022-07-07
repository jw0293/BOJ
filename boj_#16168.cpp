#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 987654321
#define endl '\n'

using namespace std;

int V, E;
int parent[3000 + 1];
int degree[3000 + 1];
vector<int> adj[3000 + 1];

void init(int V){
    for(int i=1;i<=V;i++){
        parent[i] = i;
    }
}

int getParent(int x){
    if(x == parent[x]) return x;
    return parent[x] = getParent(parent[x]);
}

void unIon(int a, int b){
    a = getParent(a);
    b = getParent(b);

    if(a > b) parent[a] = b;
    else parent[b] = a;
}

void input(){
    cin >> V >> E;

    init(V);
    for(int i=0;i<E;i++){
        int from, to;
        cin >> from >> to;

        degree[from]++; 
        degree[to]++;

        adj[from].push_back(to);
        adj[to].push_back(from);
        unIon(from, to);
    }
}

string solution(){
    int count = 0;
    for(int i=1;i<=V;i++){
        if(degree[i] % 2 == 1) count++;
    }

    int rootParent = getParent(1);
    for(int i=2;i<=V;i++){
        if(rootParent != getParent(i)) count = 3;
    }
    
    return (count == 0 || count == 2) ? "YES" : "NO";
}

int main(){
    fastio;
    input();
    cout << solution() << endl;

    return 0;
}