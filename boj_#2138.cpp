#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e9+3
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int N;
int before[100000 + 1];
int after[100000 + 1];
int temp[100000 + 1];

void input(){
	cin >> N;
	string temp; 
	cin >> temp;
	for(int i=0;i<N;i++){
		if(temp[i] == '0') before[i] = 0;
		else before[i] = 1;
	}
	temp.clear();
	cin >> temp;
	for(int i=0;i<N;i++){
		if(temp[i] == '0') after[i] = 0;
		else after[i] = 1;
	}
}

bool isSame(){
	for(int i=0;i<N;i++){
		if(temp[i] != after[i]) return false;
	}
	return true;
}

void turnLight(int index){
	if(index-1 >= 0) temp[index-1] = !temp[index-1];
	temp[index] = !temp[index];
	if(index+1 < N) temp[index+1] = !temp[index+1];
}

int getOffZeroIndex(){
	int cnt = 0;
	copy(begin(before), end(before), begin(temp));
	for(int i=1;i<N;i++){
		if(temp[i-1] != after[i-1]){
			turnLight(i);
			cnt++;
		}
	}
	if(!isSame()) return -1;
	return cnt;
}

int getOnZeroIndex(){
	int cnt = 1;
	copy(begin(before), end(before), begin(temp));
	turnLight(0);
	for(int i=1;i<N;i++){
		if(temp[i-1] != after[i-1]){
			turnLight(i);
			cnt++;
		}
	}
	if(!isSame()) return -1;
	return cnt;
}

int solution(){
	int turnOffZero = getOffZeroIndex();
	int turnOnZero = getOnZeroIndex();
	if(turnOffZero == -1 && turnOnZero == -1) return -1;
	if(turnOffZero == -1 && turnOnZero != -1) return turnOnZero;
	if(turnOffZero != -1 && turnOnZero == -1) return turnOffZero;
	return min(turnOffZero, turnOnZero);
}

int main(){
	fastio;
	input();
	cout << solution() << endl;

	return 0;
}