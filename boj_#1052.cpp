#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e9+3
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int N, K;

void input(){
	cin >> N >> K;
}

int solution(){
	int cnt = 0, answer = 0;
	for(answer = 0;;answer++){
		cnt = 0;
		int temp = N;

		while(temp){
			if(temp % 2 != 0) cnt++;
			temp /= 2;
		}

		if(cnt <= K) return answer;
		N++;
	}
	return -1;
}
int main(){
	fastio;
	input();
	cout << solution() << endl;

	return 0;
}