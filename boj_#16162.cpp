#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define endl '\n'

using namespace std;

int N, a, d;
vector<int> eum;

void input(){
    cin >> N >> a >> d;
    eum.resize(N);
    for(int i=0;i<N;i++){
        cin >> eum[i];
    }
}

int solution(){
    int prev = -1, cnt = 0;
    for(int i=0;i<N;i++){
        if(prev == -1 && eum[i] == a) {
            cnt++;
            prev = a;
            continue;
        }

        if(prev != -1 && eum[i] == prev + d){
            cnt++;
            prev = eum[i];
        }
    }   
    return cnt;
}

int main(){
    fastio;
    input();
    cout << solution() << endl;

    return 0;
}