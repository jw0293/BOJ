#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e18 + 3
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int N, Q, cur;
set<int> mst;

void input(){
	cin >> N >> Q;
	for(int i=0;i<N;i++){
		int cur; 
		cin >> cur;
		if(cur == 1) {
			mst.insert(i);
			mst.insert(i + N);
		}
	}
}

void solution(){
	while(Q--){
		int order, value;
		cin >> order;

		if(order == 1){
			cin >> value;
			if(mst.find(value-1) != mst.end()){
				mst.erase(value-1);
				mst.erase(value - 1 + N);
			} else{
				mst.insert(value-1);
				mst.insert(value - 1 + N);
			}
		} else if(order == 2){
			cin >> value;
			cur = (cur + value) % N;
		} else{
			auto nxt = mst.lower_bound(cur);
			if(nxt == mst.end()) cout << -1 << endl;
			else cout << (abs(cur - (*nxt))) % N << endl;
		}
	}
}

int main(){
	fastio;
	input();
	solution();

	return 0;
}
