#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define Mod 1000000007
#define endl '\n'

using namespace std;

const int ARI = 1023;
int price, added;

void input(){
    cin >> price >> added; 
}

string solution(){
    if(price <= 1023) return "No thanks";
    price -= ARI;
    bool flag = false;
    for(int i=0;i<10;i++){
        bool f1 = price & (1 << i);
        bool f2 = added & (1 << i);
        if(f1 && !f2){
            flag = true;
            break;
        }
    }
    return flag == false ? "Thanks" : "Impossible";
}

int main(){
    fastio;
    input();
    cout << solution() << endl;

    return 0;
}