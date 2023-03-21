#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e9 + 3
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

vector<int> pr;
const int numberRange = 1000000;
int prime[numberRange + 1];

void createPrimeArray(){
	for(int i=2;i<=sqrt(numberRange);i++){
		if(prime[i] == 0) continue;
		for(int j=i+i;j<=numberRange;j+=i){
			prime[j] = 0;
		}
	}

	for(int i=2;i<=numberRange;i++){
		if(prime[i] != 0) {
			pr.push_back(i);
		}
	}
}

void initPrime(){
	for(int i=2;i<=numberRange;i++){
		prime[i] = i;
	}
}

pair<int, int> getPrimeDuo(int x){
	for(int i=0;i<pr.size();i++){
		int y = x - pr[i];
		int findValueIdx = lower_bound(pr.begin(), pr.end(), y) - pr.begin();
		if(pr[i] + pr[findValueIdx] == x) return {pr[i], pr[findValueIdx]};
	}
	return {-1, -1};
}

void input(){
	initPrime();
	createPrimeArray();
	while(1){
		int val;
		cin >> val;
		if(!val) break;

		pair<int, int> answer = getPrimeDuo(val);
		if(answer.first == -1 && answer.second == -1) cout << "Goldbach's conjecture is wrong." << endl;
		else cout << val << " = " << answer.first << " + " << answer.second << endl;
	}
}

int main(){
	fastio;
	input();

	return 0;
}