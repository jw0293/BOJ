#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 987654321
#define endl '\n'

using namespace std;

typedef struct info{
    int start;
    int bean;
    int count;
}info;

int N, T;
vector<info> bus;

int findMin(int index){
    if(T == bus[index].start) return 0;
    
    bool flag = false;
    int pl = 0, pr = bus[index].count - 1;
    while(pl <= pr){
        int mid = (pl + pr) / 2;
        int pTime = bus[index].start + (bus[index].bean * mid);
        
        if(T > pTime){
            pl = mid+1;
        }
        else{
            flag = true;
            pr = mid-1;
        }
    }
    if(!flag) return INF;
    return bus[index].start + (bus[index].bean * pl) >= T ? bus[index].start + (bus[index].bean * pl) - T : INF;
}

int solve(){
    cin >> N >> T;
    bus.resize(N);

    int answer = INF;
    for(int i=0;i<N;i++){
        cin >> bus[i].start >> bus[i].bean >> bus[i].count;

        answer = min(answer, findMin(i));
        if(answer == 0) return 0;
    }
    return answer == INF ? -1 : answer;
}

int main(){
    fastio;
    cout << solve() << endl;

    return 0;
}