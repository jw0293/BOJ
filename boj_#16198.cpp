#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e9+3
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int N;
ll result, answer = -1;
vector<int> ps, temp;

void input(){
	cin >> N;
	ps.resize(N);
	for(int i=0;i<N;i++){
		cin >> ps[i];
	}
}

void func(vector<int> &op){
	if(op.size() == 3){
		answer = max(answer, result + (op[0] * op[2]));
		return;
	}

	vector<int> temping = op;
	for(int i=1;i<op.size()-1;i++){
		ll value = op[i-1] * op[i+1];
		op.erase(op.begin() + i);
		result += value;

		func(op);

		op = temping;
		result -= value;
	}
}

ll solution(){
	if(ps.size() == 3) return ps[0] * ps[2];
	temp = ps;
	for(int i=1;i<ps.size()-1;i++){
		ll value = ps[i-1] * ps[i+1];
		ps.erase(ps.begin() + i);
		result += value;

		func(ps);

		ps = temp;
		result -= value;
	}
	return answer;
}

int main(){
	fastio;
	input();
	cout << solution() << endl;

	return 0;
}