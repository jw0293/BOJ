#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e9 + 3
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void input(){
	int testCase;
	cin >> testCase;
	while(testCase--){
		ll x, y;
		cin >> x >> y;

		ll cur = x + 1, cnt = 1, jump = 1;
		while(cur != y){
			if(cur + (((jump + 1) * (jump + 2)) / 2) <= y) jump++;
			else if(cur + (jump * (jump + 1)) / 2 <= y) jump = jump;
			else jump--;

			cur = cur + jump;
			cnt++;
		}

		cout << cnt << endl;
	}
}

int main(){
	fastio;
	input();

	return 0;
}
