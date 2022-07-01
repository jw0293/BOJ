#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 987654321
#define endl '\n'

using namespace std;

int N, K, maxV = -1;
vector<int> ps;

void input(){
    cin >> N >> K;
    ps.resize(N);
    for(int i=0;i<N;i++){
        cin >> ps[i];
        maxV = max(maxV, ps[i]);
    }
}

long long solution(){
    if(N == 1 && ps[0] == 0) return 0;
    long long pl = 0, pr = maxV;
    while(pl <= pr){
        long long mid = (pl + pr)/2;
        
        int count = 0;
        for(auto &t : ps){
            count += t / mid;
        }
        if(K > count) pr = mid -1;
        else pl = mid+1;
    }
    
    int count = 0;
    for(auto &t : ps) count += t / pl;
    
    return count >= K ? pl : pl - 1;
}

int main(){
    fastio;
    input();
    cout << solution() << endl;

    return 0;
}