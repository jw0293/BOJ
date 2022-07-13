#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 987654321
#define endl '\n'

using namespace std;

int len;
string number;
int cache[40 + 1][2];

void input(){
    cin >> number;
    len = number.size()-1;
}

bool isValid(int index){
    string temp;
    temp += number[index];
    if(index + 1 > len) return false;
    temp += number[index+1];
    return (1 <= stoi(temp) && stoi(temp) <= 34);
}

int path(int index, int length){
    if(length == 1 && number[index] == '0') return 0;
    if(index == len) {
        if(length == 1) {
            string temp = number.substr(index, index+1);
            return (1 <= stoi(temp) && stoi(temp) <= 34);
        }
        return 1;
    }
    int &ret = cache[index][length];
    if(ret != -1) return ret;
    
    ret = 0;
    if(isValid(index) && length == 1) ret += path(index+1, length+1);
    return ret += path(index+1, 1);
}

int solution(){
    memset(cache, -1, sizeof(cache));
    return path(0, 1);
}

int main(){
    fastio;
    input();
    cout << solution() << endl;

    return 0;
}