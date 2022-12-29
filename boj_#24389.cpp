#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define Mod 1000000007
#define endl '\n'

using namespace std;

long long N;

void input(){
    cin >> N;
}

int solution(){
    int cnt = 0;
    long long x = -N;
    for(int i=0;i<32;i++){
        if((N & 1) != (x & 1)) cnt++;
        N >>= 1;
        x >>= 1;
    }
    return cnt;
}

int main(){
    fastio;
    input();
    cout << solution() << endl;

    return 0;
}