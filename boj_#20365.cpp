#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e18 + 3
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int N;
string op;

void input(){
	cin >> N;
	cin >> op;
}

int getB(){
	int cnt = 0;
	bool flag = false;
	for(int i=0;i<op.size();i++){
		if(flag && op[i] == 'B') continue;
		if(!flag && op[i] == 'B') {
			flag = true;
			cnt++;
		} 
		if(op[i] == 'R') flag = false;
	}
	return cnt;
}

int getR(){
	int cnt = 0;
	bool flag = false;
	for(int i=0;i<op.size();i++){
		if(flag && op[i] == 'R') continue;
		if(!flag && op[i] == 'R') {
			flag = true;
			cnt++;
		} 
		if(op[i] == 'B') flag = false;
	}
	return cnt;
}

void solution(){
	int B = getB();
	int R = getR();

	cout << min(R, B) + 1 << endl;
}

int main(){
	fastio;
	input();
	solution();

	return 0;
}