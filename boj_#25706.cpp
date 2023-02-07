#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e9+3
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int N;
vector<int> load;
int cache[200000 + 1];

void input(){
	cin >> N;
	load.reserve(N+1);
	for(int i=1;i<=N;i++){
		cin >> load[i];
	}
}

void memozation(){
	for(int i=N;i>=1;i--){
		if(i + load[i] + 1 > N) cache[i] = 1;
		else {
			int jump = cache[i + load[i] + 1];
			cache[i] = jump + 1;
		}
	}
}

void solution(){
	memozation();
	for(int i=1;i<=N;i++) cout << cache[i] << " ";
	cout << endl;
}

int main(){
	fastio;
	input();
	solution();

	return 0;
}