#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e9+3
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
int N;
vector<ll> file;
priority_queue<ll, vector<ll>, greater<ll>> pq;

ull getSum(){
	ull ret = 0;
	while(!pq.empty()){
		if(pq.size() < 2) {
			break;
		}

		ull cache = 0;
		for(int i=0;i<2;i++){
			ll tp = pq.top();
			pq.pop();

			cache += tp;
		}
		pq.push(cache);
		ret += cache;
	}
	return ret;
}

void input(){
	int testCase;
	cin >> testCase;
	while(testCase--){
		cin >> N;
		file.resize(N);
		for(int i=0;i<N;i++){
			cin >> file[i];
			pq.push(file[i]);
		}
		cout << getSum() << endl;
		while(!pq.empty()) pq.pop();
	}
}

int main(){
	fastio;
	input();

	return 0;
}