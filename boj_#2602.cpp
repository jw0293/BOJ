#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e9+7;
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

string str;
string ps1, ps2;
int cache[3][100 + 1][100 + 1];

void input(){
	cin >> str;
	cin >> ps1 >> ps2;
}

int dp(int len, int op, int index){
	if(len == str.size()) return 1;
	int &ret = cache[op][len][index];
	if(ret != -1) return ret;
	ret = 0;
	for(int i=index+1;i<ps1.size();i++){
		if(op == 1 && str[len] == ps2[i]) ret += dp(len+1, 2, i);
		if(op == 2 && str[len] == ps1[i]) ret += dp(len+1, 1, i);
	}
	return ret;
}

int solution(){
	int ans = 0;
	memset(cache, -1, sizeof(cache));
	for(int i=0;i<ps1.size();i++){
		if(str[0] == ps1[i]) ans += dp(1, 1, i);
		if(str[0] == ps2[i]) ans += dp(1, 2, i);
	}
	return ans;
}

int main(){
	fastio;
	input();
	cout << solution() << endl;

	return 0;
}