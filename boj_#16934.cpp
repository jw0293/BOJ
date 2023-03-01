#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e18 + 3
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int ROOT = 1;
const int MX = 100000 * 10 + 10;

int unused = 2, N;
int chk[MX];
int nxt[MX][26];

void init(){
	for(int i=0;i<MX;i++){
		fill(nxt[i], nxt[i]+26, -1);
	}
}

int c2i(char ch){
	return ch - 'a';
}

string insert(string &str){
	int cur = ROOT;
	string ret;
	bool isFind = false;
	for(int i=0;i<str.size();i++){
		if(nxt[cur][c2i(str[i])] == -1){
			if(!isFind){
				isFind = true;
				ret = str.substr(0, i+1);
			}
			nxt[cur][c2i(str[i])] = unused++;
		}
		cur = nxt[cur][c2i(str[i])];
	}
	chk[cur]++;
	if(!isFind) {
		if(chk[cur] == 1) ret = str;
		else {
			ret = str;
			ret += to_string(chk[cur]);
		}
	}

	return ret;
}

void input(){
	cin >> N;
	for(int i=0;i<N;i++){
		string op;
		cin >> op;

		cout << insert(op) << endl;
	}
}

int main(){
	fastio;
	init();
	input();

	return 0;
}
