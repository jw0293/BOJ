#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define Mod 1000000007
#define endl '\n'

using namespace std;

string H;

void input(){
    cin >> H;
}

vector<int> getPartialMatch(const string &N){
    int m = N.size();
    vector<int> pi(m, 0);
    int begin = 1, matched = 0;
    while(begin + matched < m){
        if(N[begin+matched] == N[matched]){
            ++matched;
            pi[begin+matched-1] = matched;
        }
        else{
            if(matched==0) ++begin;
            else{
                begin += matched - pi[matched-1];
                matched = pi[matched-1];
            }
        }
    }
    return pi;
}

vector<int> kmpSearch(const string &H, const string &N){
    int n = H.size(), m = N.size();

    vector<int> ret;
    vector<int> pi = getPartialMatch(N);
    int matched = 0;
    for(int i=0;i<n;++i){
        while(matched>0 && H[i] != N[matched]){
            matched = pi[matched-1];
        }
        if(H[i] == N[matched]){
            ++matched;
            if(matched==m){
                ret.push_back(i-m+1);
                matched = pi[matched-1];
            }
        }
    }
    return ret;
}

int solution(){
    int answer = 0;
    for(int i=0;i<H.size();i++){
        string S = H.substr(i, H.size());
        vector<int> pi = getPartialMatch(S);
        for(int j=0;j<pi.size();j++){
            if(answer >= pi[j]) continue;
            string hint = S.substr(0, pi[j]);
            vector<int> cache = kmpSearch(H, hint);
            if(cache.size() >= 2){
                answer = pi[j];
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