#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 987654321
#define endl '\n'

using namespace std;

int N, L, W, H;

void input(){
    cin >> N >> L >> W >> H;
}

void solution(){
    cout << fixed;
    cout.precision(10);
    double pl = 0, pr = 1000000000, mid;
    for(int i=0;i<10000;i++){
        mid = (pl + pr) / 2;
        if(((long long)(L / mid)) * ((long long)(W / mid)) * ((long long)(H / mid)) < N) pr = mid;
        else pl = mid;
    }
    cout << pl << endl;
}

int main(){
    fastio;
    input();
    solution();

    return 0;
}