#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 123456789
#define endl '\n'

using namespace std;

typedef long long ll;

int N, K, P, X;
const int number[10][7] = {
	{1, 1, 1, 0, 1, 1, 1},
	{0, 0, 1, 0, 0, 1, 0},
	{1, 0, 1, 1, 1, 0, 1},
	{1, 0, 1, 1, 0, 1, 1},
	{0, 1, 1, 1, 0, 1, 0},
	{1, 1, 0, 1, 0, 1, 1},
	{1, 1, 0, 1, 1, 1, 1},
	{1, 0, 1, 0, 0, 1, 0},
	{1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 0, 1, 1}
};

void input(){
	cin >> N >> K >> P >> X;
}

int getXIndex(string &cur, int idx){
	if(cur.size() <= idx) return 0;
	return cur[idx]-'0';
}

int getPurposeIndex(string &purpose, int idx){
	if(purpose.size() <= idx) return 0;
	return purpose[idx]-'0';
}

int onAndOffCounting(int curX, int purposeX){
	int cnt = 0;
	for(int j=0;j<7;j++){
		if(number[curX][j] != number[purposeX][j]){
			cnt++;
		}
	}
	return cnt;
}

int getPossibleChange(){
	int possible = 0;
	string cur = to_string(X);
	reverse(cur.begin(), cur.end());

	for(int n=1;n<=(int)pow(10, K);n++){
		if(n > N) break;
		if(n == X) continue;

		int cnt = 0;
		string purpose = to_string(n);
		reverse(purpose.begin(), purpose.end());

		for(int i=0;i<K;i++){
			int curX = getXIndex(cur, i);
			int purposeX = getPurposeIndex(purpose, i);

			cnt += onAndOffCounting(curX, purposeX);
		}
		
		if(cnt <= P){
			possible++;
		}
	}
	return possible;
}

int solution(){
	return getPossibleChange();
}

int main() {
	fastio;
	input();
	cout << solution() << endl;
	
	return 0;
}