#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 123456789
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int T;
ull sum;
vector<int> ps;

void input(){
	cin >> T;
	ps = vector<int>(T, 0);
	for(int i=0;i<T;i++){
		cin >> ps[i];
		sum += ps[i];
	}
}

ull solution(){
	ull answer = 0;
	sort(ps.begin(), ps.end(), greater<>());
	for(int i=0;i<ps.size()-1;i++){
		sum -= ps[i];
		answer += sum * ps[i];
	}
	return answer;
}

int main() {
	fastio;
	input();
	cout << solution() << endl;

	return 0;
}