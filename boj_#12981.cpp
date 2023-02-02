#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e9+3
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int R, G, B;

void input(){
	cin >> R >> G >> B;
}

int addSameBall(){
	int cnt = 0;
	if(R > 0) cnt++;
	if(G > 0) cnt++;
	if(B > 0) cnt++;
	return cnt;
}

int solution(){
	int ans=0;
	ans += R / 3, R %= 3;
	ans += G / 3, G %= 3;
	ans += B / 3, B %= 3;

	while(R && G && B) ans++, R--, G--, B--;
	while(R && G) ans++, R--, G--;
	while(R && B) ans++, R--, B--;
	while(G && B) ans++, G--, B--;
	ans += addSameBall();
	return ans;
}

int main(){
	fastio;
	input();
	cout << solution() << endl;

	return 0;
}