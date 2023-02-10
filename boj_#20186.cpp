#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e9+3
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int N, K;
vector<int> ps;
void input(){
	cin >> N >> K;
	ps.resize(N);
	for(int i=0;i<N;i++){
		cin >> ps[i];
	}
}

int solution(){
	int answer = 0;
	sort(ps.begin(), ps.end(), greater<int>());
	for(int i=0;i<K;i++){
		answer += ps[i];
	}

	return answer - (K * (K-1))/2;
}

int main(){
	fastio;
	input();
	cout << solution() << endl;

	return 0;
}