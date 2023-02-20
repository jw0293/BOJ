#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e18 + 3
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ull N, M;
vector<ull> T;

void input(){
	cin >> N >> M;
	T.resize(N);
	for(int i=0;i<N;i++){
		cin >> T[i];
	}
}

ull solution(){
	ull answer = -1;
	sort(T.begin(), T.end());
	ull pl = 1, pr = T[0] * M;
    
	if(M == 1) return T[0];
	
    while(pl <= pr){
		ull mid = (pl + pr) / 2;

		ull value = 0;
		for(auto &t : T) value += mid / t;
		if(M <= value){
			if(answer == -1 || mid < answer) answer = mid;
			pr = mid - 1;
		} else{
			pl = mid + 1;
		}
	}
	return answer;
}

int main(){
	fastio;
	input();
	cout << solution() << endl;

	return 0;
}