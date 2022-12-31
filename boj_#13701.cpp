#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define Mod 1000000007
#define endl '\n'

using namespace std;

int fullSet[(1 << 25) / 32];

void solution(){
    while(1){
        int x;
        cin >> x;
        if(cin.eof() == true){
            break;
        }

        if(!(fullSet[(x / 32)] & (1 << (x % 32)))){
            fullSet[(x / 32)] += (1 << (x % 32));
            cout << x << " ";
        }
    }
}

int main(){
    fastio;
    solution();

    return 0;
}