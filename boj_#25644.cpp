#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define Mod 12345678910
#define endl '\n'

using namespace std;

int N;
vector<int> ps;

void input(){
	cin >> N;
	ps.resize(N, 0);
	for(int i=0;i<N;i++){
		cin >> ps[i];
	}
}

int solution(){
	int answer = 0;
	int maxV = -1;
	for(int i=ps.size()-1;i>=0;i--){
		if(ps[i] > maxV){
			maxV = ps[i];
		}
		answer = max(answer, maxV-ps[i]);
	}
	return answer;
}

int main() {
	fastio;
	input();
	cout << solution() << endl;
	
	return 0;
}