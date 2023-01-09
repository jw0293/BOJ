#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define Mod 12345678910
#define endl '\n'

using namespace std;

long long k;

void input(){
	cin >> k;
}

string getReverse(char ch){
	if(ch == '0') return "1";
	return "0";
}

long long dfs(long long index){
	if(index == 1) return 0;
	long long idx;
	for(idx=1;idx+idx<index;idx+=idx);
	return !dfs(index-idx);
}

int main() {
	fastio;
	input();
	cout << dfs(k) << endl;
	
	return 0;
}