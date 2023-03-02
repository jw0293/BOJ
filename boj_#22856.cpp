#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e18 + 3
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int ROOT = 1;
const int MX = 100000 + 1;

int N,endNode;
bool visited[MX];
int lc[MX], rc[MX], p[MX];

void input(){
	cin >> N;
	for(int i=0;i<N;i++){
		int o, l, r;
		cin >> o >> l >> r;

		lc[o] = l;
		rc[o] = r;

		p[l] = p[r] = o;
	}
}

void preOrder(){
	endNode = ROOT;
	while(rc[endNode] != -1) {
		endNode = rc[endNode];
	}
}

int solution(){
	preOrder();
	
	int cur = ROOT, cnt = 0;
	while(1){
		cnt++;
		visited[cur] = true;

		if(lc[cur] != -1 && !visited[lc[cur]]) cur = lc[cur];
		else if(rc[cur] != -1 && !visited[rc[cur]]) cur = rc[cur];
		else{
			if(cur == endNode) break;
			cur = p[cur];
		}
	}

	return cnt - 1;
}

int main(){
	fastio;
	input();
	cout << solution() << endl;

	return 0;
}
