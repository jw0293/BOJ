#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define endl '\n'

using namespace std;

string str;
int alpha[25 + 1];
int checked[200000 + 2][25 + 1];

int solution(char op, int from, int to){
    return checked[to+1][op-'a'] - checked[from][op-'a'];
}

void prefixSum(string &str){
    for(int i=0;i<str.size();i++){
        int index = str[i]-'a';
        alpha[index]++;
        checked[i+1][index] = alpha[index];
        for(int j=0;j<26;j++){
            if(j==index) continue;
            checked[i+1][j] = checked[i][j];
        }
    }
}

void input(){
    char op;
    int from, to, N;
    cin >> str;
    prefixSum(str);

    cin >> N;
    for(int i=0;i<N;i++){
        cin >> op >> from >> to;
        cout << solution(op, from, to) << endl;
    }
}

int main(){
    fastio;
    input();

    return 0;
}