#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e18 + 3
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int N, sum;
vector<int> ps;

void input(){
	cin >> N;
	ps.resize(N);
	for(int i=0;i<N;i++){
		cin >> ps[i];
		sum += ps[i];
	}
}

int solution(){
	bool isStart = false;
	int pl = 0, pr = 1;
	int plSum = ps[0], prSum = sum - ps[0];
	int answer = min(plSum, prSum);
	while(pl < N){
		answer = max(answer, min(plSum, prSum));
				cout << "[ " << plSum << " : " << prSum << " ]" << endl;

		if(plSum >= prSum){
			plSum -= ps[pl];
			prSum += ps[pl];
			pl++;
			continue;
		}
		plSum += ps[pr];
		prSum -= ps[pr];
		pr++;
		pr %= N;
	}
	return answer;
}

int main(){
	fastio;
	input();
	cout << solution() << endl;

	return 0;
}