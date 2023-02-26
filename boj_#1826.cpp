#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e18 + 3
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int N;
vector<pair<int, int>> fuel;
int purpose, K;

void input(){
	cin >> N;
	for(int i=0;i<N;i++){
		int d, f;
		cin >> d >> f;
		fuel.push_back({d, f});
	}
	cin >> purpose >> K;
}

int solution(){
	ll cur = K, answer = 0, idx = 0;
	sort(fuel.begin(), fuel.end());
	priority_queue<int> pq;
	
	while(cur < purpose){
		while(idx < N && fuel[idx].first <= cur){
			pq.push(fuel[idx].second);
			idx++;
		}

		if(pq.empty()) return -1;

		cur += pq.top();
		pq.pop();
		answer++;
	}

	return answer;
}

int main(){
	fastio;
	input();
	cout << solution() << endl;

	return 0;
}
