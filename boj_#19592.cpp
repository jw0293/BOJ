#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 987654321
#define endl '\n'

using namespace std;

int N, X, Y;
double minTime;
vector<int> speed;

double doingTime(int x, int s){
    return (double)((double)x / (double)s);
}

int solution(double minValue){
    if(doingTime(X, speed[N-1]) < minValue) return 0;
    if(doingTime(X-Y, speed[N-1]) + 1 >= minValue) return -1;

    int pl = 1, pr = Y-1;
    while(pl <= pr){
        int dist = (pl + pr) / 2;

        if(doingTime(X-dist, speed[N-1]) + 1 < minValue) pr = dist-1;
        else pl = dist+1;
    }
    return pl;
}

void input(){
    int testCase;
    cin >> testCase;

    while(testCase--){
        minTime = (double)INF;
        cin >> N >> X >> Y;
        
        speed.resize(N);
        for(int i=0;i<N;i++){
            cin >> speed[i];
            if(i != N-1) {
                minTime = min(minTime, doingTime(X, speed[i]));
            }
        }

        cout << solution(minTime) << endl;
    }
}

int main(){
    fastio;
    input();

    return 0;
}