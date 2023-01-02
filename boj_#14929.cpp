#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define Mod 1000000007
#define endl '\n'

using namespace std;

int N;
long long ps[100000 + 1], psum[100000 + 1];

void input(){
	cin >> N;
	for(int i=1;i<=N;i++) {
		cin >> ps[i];
		psum[i] = psum[i-1] + ps[i];
	}
}

long long solution(){
	long long answer = 0;
	for(int i=2;i<=N;i++){
		answer += ps[i] * psum[i-1];
	}
	return answer;
}
 
int main() {
	fastio;
	input();
	cout << solution() << endl;
 
	return 0;
}