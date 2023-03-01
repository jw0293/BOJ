#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e18 + 3
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int ROOT = 1;
const int MX = 500 * 80 + 5;

int unused = 2, N = 0;
map<string, int> nxt[MX];

void insert(vector<string> &temp){
	int cur = ROOT;
	for(auto &s : temp){
		if(!nxt[cur][s]) {
			nxt[cur][s] = unused++;
		}
		cur = nxt[cur][s];
	}
}


vector<string> getStringOp(string &op){
	string temp = "";
	vector<string> ret;
	for(int i=0;i<op.size();i++){
		if(op[i] == '\\'){
			ret.push_back(temp);
			temp.clear();
			continue;
		}
		temp += op[i];
	}
	ret.push_back(temp);
	return ret;
}

void input(){
	cin >> N;
	for(int i=0;i<N;i++){
		string op;
		cin >> op;
		vector<string> ret = getStringOp(op);

		insert(ret);
	}
}

void dfs(int r, int d){
	for(auto &cur : nxt[r]){
		string blank = "";
		for(int i=0;i<d;i++){
			blank += " ";
		}
		cout << blank << cur.first << endl;
		dfs(cur.second, d+1);
	}
}

void solution(){
	dfs(1, 0);
}

int main(){
	fastio;
	input();
	solution();

	return 0;
}
