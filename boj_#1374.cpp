#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 987654321
#define endl '\n'

using namespace std;

typedef struct info{
    int number;
    int start;
    int end;
}info;

int N;
vector<info> op;

bool cmp(const info &lhs, const info &rhs){
    if(lhs.start == rhs.start) return lhs.end < rhs.end;
    return lhs.start < rhs.start;
}

void input(){
    cin >> N;
    op.resize(N);
    for(int i=0;i<N;i++){
        cin >> op[i].number >> op[i].start >> op[i].end;
    }
}

int solution(){
    sort(op.begin(), op.end(), cmp);
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(auto &t : op){
        if(pq.empty() || t.start < pq.top()) {
            pq.push(t.end);
        }
        else{
            pq.pop();
            pq.push(t.end);
        }
    }
    return pq.size();
}

int main(){
    fastio;
    input();
    cout << solution() << endl;

    return 0;
}