#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 123456789
#define endl '\n'

using namespace std;

typedef long long ll;

vector<int> op;
int N, M, first, second;
ll cache[20 + 1][20 + 1][20 + 1];

void input(){
	cin >> N;
	cin >> first >> second;
	cin >> M;
	op.resize(M, 0);
	for(int i=0;i<M;i++){
		cin >> op[i];
	}
}

ll func(int first, int second, int index){
	if(index == M) return 0;
	ll& ret = cache[first][second][index];
	if(ret != -1) return ret;

	return ret = min(func(op[index], second, index+1) + abs(first - op[index]),
						func(first, op[index], index+1) + abs(second - op[index]));
}

ll solution(){
	memset(cache, -1, sizeof(cache));
	return func(first, second, 0);
}

int main() {
	fastio;
	input();
	cout << solution() << endl;
	
	return 0;
}