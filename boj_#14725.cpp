#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e18 + 3
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int N, M;
const int ROOT = 1;
const int MX = 10000 * 15 + 5;
int unused = 2;
bool chk[MX];
map<string, int> nxt[MX];

void insert(vector<string> &s){
	int cur = ROOT;
	for(auto c : s){
		if(!nxt[cur][c]) {
			nxt[cur][c] = unused++;
		}
		cur = nxt[cur][c];
	}
}

void input(){
	cin >> N;
	while(N--){
		cin >> M;
		vector<string> inputStr(M);
		for(int i=0;i<M;i++){
			cin >> inputStr[i];
		}
		insert(inputStr);
	}
}

void dfs(int cur, int d){
	for(auto nx : nxt[cur]){
		string level;
		for(int i=0;i<d;i++) level += "--";
		cout << level << nx.first << endl;
		dfs(nx.second, d+1);
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
