#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e9+3
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int N, M;
vector<int> cost;

void input(){
	cin >> N >> M;
	cost.resize(N);
	for(int i=0;i<N;i++){
		cin >> cost[i];
	}
}

int getCount(int k){
	int cnt = 1, temp = k;
	for(int i=0;i<cost.size();i++){
		if(cost[i] <= temp){
			temp -= cost[i];
		} else{
			cnt++;
			temp = k;
			if(temp < cost[i]) return -1;
			temp -= cost[i];
		}
	}
	return cnt;
}

int solution(){
	int pl = 1, pr = 1000000000;
	while(pl <= pr){
		int K = (pl + pr) / 2;
		int cnt = getCount(K);
		if(cnt == -1 || cnt > M) pl = K + 1;
		else pr = K-1;
	}
	return pl;
}

int main(){
	fastio;
	input();
	cout << solution() << endl;

	return 0;
}