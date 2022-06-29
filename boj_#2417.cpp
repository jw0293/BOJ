#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 987654321
#define endl '\n'

using namespace std;

long long N;

void input(){
    cin >> N;
}

long long solution(){
    long long pl = 0, pr = pow(2, 63) -1;
    while(pl <= pr){
        long long mid = (pl + pr) / 2;
        unsigned long long val = mid * mid;
        if(val >= N) pr = mid-1;
        else pl = mid+1;
    }
    return pl;
}

int main(){
    fastio;
    input();
    cout << solution() << endl;

    return 0;
}