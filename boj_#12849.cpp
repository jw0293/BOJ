#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define Mod 1000000007
#define endl '\n'

using namespace std;

int t;
long long cache[100000 + 1][10];
vector<int> adj[10];

void init(){
    // 정보과학관을 1번으로 지정
    adj[1].push_back(2);
    adj[2].push_back(1);

    adj[1].push_back(3);
    adj[3].push_back(1);

    adj[2].push_back(3);
    adj[3].push_back(2);

    adj[2].push_back(4);
    adj[4].push_back(2);

    adj[3].push_back(4);
    adj[4].push_back(3);

    adj[3].push_back(5);
    adj[5].push_back(3);

    adj[4].push_back(5);
    adj[5].push_back(4);

    adj[4].push_back(6);
    adj[6].push_back(4);

    adj[5].push_back(6);
    adj[6].push_back(5);

    adj[6].push_back(7);
    adj[7].push_back(6);

    adj[5].push_back(8);
    adj[8].push_back(5);

    adj[7].push_back(8);
    adj[8].push_back(7);
}

void input(){
    cin >> t;
}

long long path(int restTime, int node){
    if(restTime == 0){
        if(node == 1) return 1;
        else return 0;
    }
    long long &ret = cache[restTime][node];
    if(ret != -1) return ret;

    ret = 0;
    for(auto &y : adj[node]){
        ret += path(restTime-1, y) % Mod;
    }
    return ret;
}

long long solution(){
    long long count = 0;
    memset(cache, -1, sizeof(cache));
    for(auto &next : adj[1]){
        count += path(t-1, next) % Mod;
    }
    return count;
}

int main(){
    fastio;
    init();
    input();
    cout << solution() << endl;

    return 0;
}