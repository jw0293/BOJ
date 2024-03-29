#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define Mod 1000000007
#define endl '\n'

using namespace std;

string T, P;

void input(){
    getline(cin, T);
    getline(cin, P);
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

void solution(){
    vector<int> ret = kmpSearch(T, P);
    int answerCount = ret.size();
    cout << answerCount << endl;
    for(auto &ptr : ret){
        cout << ptr+1 << " ";
    }
    cout << endl;
}

int main(){
    fastio;
    input();
    solution();

    return 0;
}