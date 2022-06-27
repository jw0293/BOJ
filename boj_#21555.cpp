#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define Mod 1000000007
#define endl '\n'

using namespace std;

int N, K;
vector<pair<int, int>> power;
long long cache[200000 + 1][2][2];

void input(){
    cin >> N >> K;
    power.resize(N);
    for(int i=0;i<N;i++) cin >> power[i].first;
    for(int i=0;i<N;i++) cin >> power[i].second;
}

long long path(int index, int method1, int method2){
    if(index == N) return 0;
    long long &ret = cache[index][method1][method2];
    
    if(ret != -1) return ret;
    ret = 0;
    if(method1 == 1) ret = min(path(index+1, method1, method2) + power[index].first ,path(index+1, 0, 1) + power[index].second + K);
    if(method2 == 1) ret = min(path(index+1, method1, method2) + power[index].second, path(index+1, 1, 0) + power[index].first + K);
    return ret;
}

long long solution(){
    memset(cache, -1, sizeof(cache));
    return min(path(1, 1, 0) + power[0].first, path(1, 0, 1) + power[0].second);
}

int main(){
    fastio;
    input();
    cout << solution() << endl;

    return 0;
}