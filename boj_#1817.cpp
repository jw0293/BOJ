#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 123456789
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int N, M;
vector<int> ps;

void input(){
	cin >> N >> M;
	ps.resize(N, 0);
	for(int i=0;i<N;i++){
		cin >> ps[i];
	}
}

int solution(){
	int sum = 0;
	int answer = 0;
	for(int i=0;i<ps.size();i++){
		if(sum + ps[i] <= M){
			sum += ps[i];
			continue;
		} else{
			answer++;
			sum = 0;
			sum += ps[i];
		}
	}
	return sum == 0 ? answer : answer+1;
}

int main(){
	fastio;
	input();
	cout << solution() << endl;

	return 0;
}