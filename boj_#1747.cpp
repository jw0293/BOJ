#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e9+3
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int N;
const int MAX_N = 1000000 + 3003;
int prime[MAX_N];

void init(){
	for(int i=2;i<=MAX_N;i++){
		prime[i] = i;
	}
}

void priming(){
	for(int i=2;i<=sqrt(MAX_N);i++){
		if(prime[i] == 0) continue;
		for(int j=i*i;j<=MAX_N;j+=i) {
			prime[j] = 0;
		}
	}
}

void input(){
	cin >> N;
}

bool isPalindrome(int n){
	string temp = to_string(n);
	string _temp = temp;
	reverse(temp.begin(), temp.end());
	return temp == _temp;
}

int solution(){
	init();
	priming();

	int answer = -1;
	for(int i=N;i<MAX_N;i++){
		if(!prime[i]) continue;
		if(!isPalindrome(i)) continue;
		answer = i;
		break;
	}
	return answer;
}

int main(){
	fastio;
	input();
	cout << solution() << endl;
	for(int i=1;i<=1000;i++) {
		if(prime[i] != 0) cout << i << " ";
	}

	return 0;
}