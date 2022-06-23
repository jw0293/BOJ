#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define endl '\n'

using namespace std;

int N;
vector<pair<int, int>> building;

void input(){
    cin >> N;
    for(int i=0;i<N;i++){
        int x, y;
        cin >> x >> y;
        building.push_back({x, y});
    }
}

int solution(){
    int cnt = 0;
    stack<int> stk;
    sort(building.begin(), building.end());

    for(int i=0;i<building.size();i++){
        int height = building[i].second;
        while(!stk.empty() && stk.top() > height){
            int top = stk.top();
            if(top != 0) cnt++;
            stk.pop();
        }

        if(!stk.empty() && stk.top() == height) continue;

        stk.push(height);
    }

    while(!stk.empty()){
        int top = stk.top();
        stk.pop();

        if(top != 0) cnt++;
    }

    return cnt;
}

int main(){
    fastio;
    input();
    cout << solution() << endl;

    return 0;
}