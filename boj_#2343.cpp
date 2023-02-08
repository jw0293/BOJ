#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e9+3
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int N, M;
vector<int> lecture;

void input(){
	cin >> N >> M;
	lecture.resize(N+1);
	for(int i=1;i<=N;i++){
		cin >> lecture[i];
	}
}

int getCount(int val){
	int x = val, cnt = 1;
	for(int i=1;i<=N;i++){
		if(lecture[i] <= x){
			x -= lecture[i];
		} else{
			cnt++;
			x = val;
			if(lecture[i] > x) return -1;
			x -= lecture[i];
		}
	}
	return cnt;
}

int solution(){
	int pl = 1, pr = 1000000000;
	while(pl <= pr){
		int mid = (pl + pr) / 2;
		int cnt = getCount(mid);
		if(cnt == -1 || cnt > M) pl = mid + 1;
		else pr = mid - 1;
	}
	return pl;
}

int main(){
	fastio;
	input();
	cout << solution() << endl;

	return 0;
}