#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define Mod 1000000007
#define endl '\n'

using namespace std;

int N, M, L;
vector<pair<int, int>> pos;

void input(){
    cin >> N >> L >> M;
    for(int i=0;i<M;i++){
        int y, x;
        cin >> y >> x;
        pos.push_back({y, x});
    }
}

int findFish(int y, int x, int cy, int cx){
    int cnt = 0;
    for(int i=0;i<M;i++){
        if(y <= pos[i].first && pos[i].first <= y+cy && x <= pos[i].second && pos[i].second <= x+cx){
            cnt++;
        }
    }
    return cnt;
}

int solution(){
    int answer = -1;
    for(int i=0;i<M;i++){
        for(int j=0;j<M;j++){
            for(int k=1;k<L/2;k++){
                answer = max(answer, findFish(pos[i].first, pos[j].second, k, L/2-k));
            }
        }
    }
    return answer;
}

int main(){
    fastio;
    input();
    cout << solution() << endl;

    return 0;
}