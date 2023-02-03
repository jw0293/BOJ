#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e9+3
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int K;

void input(){
	cin >> K;
}

int getPower(int x){
	for(int i=1;;i++){
		int val = (int)pow(2, i);
		if(val == x) return val;
		if(val > x) return -1;
	}
}

int getMinTwoPower(int x){
	for(int i=1;;i++){
		int power = (int)pow(2, i);
		if(x < power) return power;
	}
}

int getOddToOne(int x){
	for(int i=1;;i++){
		int power = (int)pow(2, i);
		if(power == x) return i;
	}
}

int getEvenValue(int x){
	int value = x, cnt = 0;
	while(K != 0){
		if(K >= value / 2) K -= value / 2;
		value /= 2;
		cnt++;
	}
	return cnt;
}

pair<int, int> solution(){
	int power = getPower(K);
	if(power != -1) return {power, 0};
	int value = getMinTwoPower(K);
	if(K % 2 != 0){
		return {value, getOddToOne(value/2) + 1};
	} else{
		int count = getEvenValue(value);
		return {value, count};
	}
}

int main(){
	fastio;
	input();
	pair<int, int> result = solution();
	cout << result.first << " " << result.second << endl;

	return 0;
}