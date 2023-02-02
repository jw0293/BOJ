#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e9+3
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int N, M;
const short jump[] = {-1, 0, 1};
int cache[10000 + 1][250 + 1];
bool cantStone[10000 + 1];

void input(){
	cin >> N >> M;
	for(int i=0;i<M;i++){
		int x; cin >> x;
		cantStone[x] = true;
	}
}

int dp(int stone, int prev){
	if(stone == N) return 0;
	if(stone > N) return INF;
	int &ret = cache[stone][prev];
	if(ret != -1) return ret;
	ret = INF;
	for(int i=0;i<3;i++){
		int nextJump = prev + jump[i];
		int next = stone + nextJump;
		if(cantStone[next] || next < stone) continue;
		ret = min(ret, dp(next, nextJump) + 1);
	}
	return ret;
}

int solution(){
	if(cantStone[2]) return -1;
	memset(cache, -1, sizeof(cache));
	int answer = dp(2, 1) + 1;
	return (answer == INF) ? -1 : answer;
}

int main(){
	fastio;
	input();
	cout << solution() << endl;

	return 0;
}