#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 987654321
#define endl '\n'

using namespace std;

int N, M;
bool visited[500 + 1];
vector<int> inDeg[500 + 1], outDeg[500 + 1];

void input(){
    cin >> N >> M;
    for(int i=0;i<M;i++){
        int from, to;
        cin >> from >> to;

        inDeg[to].push_back(from);
        outDeg[from].push_back(to);
    }
}

void dfsIn(int next, int &count){
    count++;
    for(auto &t : inDeg[next]){
        if(!visited[t]){
            visited[t] = true;
            dfsIn(t, count);
        }
    }
}

void dfsOut(int next, int &count){
    count++;
    for(auto &t : outDeg[next]){
        if(!visited[t]){
            visited[t] = true;
            dfsOut(t, count);
        }
    }
}

int sumDeg(int index){
    int count = 0;
    memset(visited, false, sizeof(visited));
    for(auto &t : inDeg[index]){
        if(!visited[t]){
            visited[t] = true;
            dfsIn(t, count);
        }
    }

    for(auto &t : outDeg[index]){
        if(!visited[t]){
            visited[t] = true;
            dfsOut(t, count);
        }
    }

    return count;
}

int solution(){
    int answer = 0;
    for(int i=1;i<=N;i++){
        if(sumDeg(i) == N-1) {
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