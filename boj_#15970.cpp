#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define endl '\n'

using namespace std;

int N, colorCnt;
queue<int> q;
bool visited[5000 + 1];
vector<int> info[5000 + 1];

void input(){
    cin >> N;
    for(int i=0;i<N;i++){
        int pos, color;
        cin >> pos >> color;

        if(!visited[color]){
            visited[color] = true;
            colorCnt++;
            q.push(color);

            info[color].push_back(pos);
        }
        else{
            info[color].push_back(pos);
        }
    }
}

int solution(){
    int answer = 0;
    while(!q.empty()){
        int color = q.front();
        q.pop();

        sort(info[color].begin(), info[color].end());

        for(int i=0;i<info[color].size();i++){
            if(i == 0 || i == info[color].size()-1){
                if(i == 0) answer += (info[color][1] - info[color][0]);
                else answer += (info[color][info[color].size()-1] - info[color][info[color].size() -2]);
            }
            else{
                answer += min(info[color][i]-info[color][i-1], info[color][i+1] - info[color][i]);
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