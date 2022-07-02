#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 987654321
#define endl '\n'

using namespace std;

int L, N;
long long answer;
vector<int> ps;
bool isin[1000 + 1];

void input(){
    cin >> L;
    ps.resize(L);
    for(int i=0;i<L;i++){
        cin >> ps[i];
        isin[ps[i]] = true;
    }
    cin >> N;
}

void dfs(vector<int> &temp, vector<int> &as, int start){
    if(as.size() == 2){
        if(as[0] <= N && N <= as[1]) {
            answer++;
        }
        return;
    }

    for(int i=start; i<temp.size();i++){
        as.push_back(temp[i]);
        
        dfs(temp, as, i+1);

        as.pop_back();
    }
}

pair<int, int> findOffsetLimit(){
    pair<int, int> info;
    for(auto &t : ps){
        if(t == N) return {0, 0};
        if(t > N){
            info.second = t;
            break;
        }
        else{
            info.first = t;
        }
    }
    return info;
}

vector<int> init_vector(int offset, int limit){
    vector<int> temp;
    for(int start = offset + 1; start < limit; start++){
        temp.push_back(start);
    }
    return temp;
}

long long solution(){
    if(isin[N]) return 0;
    sort(ps.begin(), ps.end());

    pair<int, int> info = findOffsetLimit();
    if(!info.first && !info.second) return 0;

    vector<int> temp = init_vector(info.first, info.second);

    vector<int> as;
    for(int i=0;i<temp.size();i++){
        as.push_back(temp[i]);

        dfs(temp, as, i+1);

        as.pop_back();
    }
    
    return answer;
}

int main(){
    fastio;
    input();
    cout << solution() << endl;

    return 0;
}