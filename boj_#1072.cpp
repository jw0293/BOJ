#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 987654321
#define endl '\n'

using namespace std;

int X, Y;

void input(){
    cin >> X >> Y;
}

int solution(){
    long rate = ((long double)Y / (long double)X) * 100;
    bool flag = false;
    int pl = 0, pr = X;
    while(pl <= pr){
        int mid = (pl + pr) / 2;

        long newRate = ((long double)(Y + mid) / (long double)(X + mid)) * 100;
        if(newRate != rate){
            flag = true;
            pr = mid -1;
        }
        else{
            pl = mid + 1;
        }
    }
    return flag == false ? -1 : pl;
}

int main(){
    fastio;
    input();
    cout << solution() << endl;

    return 0;
}