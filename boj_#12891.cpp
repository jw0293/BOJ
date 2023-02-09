#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e9+3
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int S, P;
bool flag;
string str;
int demandCnt[4], cnt[4];

void input(){
	cin >> S >> P;
	cin >> str;
	for(int i=0;i<4;i++){
		cin >> demandCnt[i];
	}
}

int isValid(string checkStr){
	for(int i=0;i<4;i++){
		if(cnt[i] < demandCnt[i]) return 0;
	}
	return 1;
}

void cancelChar(char ch){
	if(ch == 'A') {
		cnt[0]--;
		if(flag == true && cnt[0] < demandCnt[0]) flag = false;
	}
	if(ch == 'C') {
		cnt[1]--;
		if(flag == true && cnt[1] < demandCnt[1]) flag = false;
	}
	if(ch == 'G') {
		cnt[2]--;
		if(flag == true  && cnt[2] < demandCnt[2]) flag = false;
	}
	if(ch == 'T') {
		cnt[3]--;
		if(flag == true  && cnt[3] < demandCnt[3]) flag = false;
	}
}

void addChar(char ch){
	if(ch == 'A') cnt[0]++;
	if(ch == 'C') cnt[1]++;
	if(ch == 'G') cnt[2]++;
	if(ch == 'T') cnt[3]++;
}

bool isValidFlag(){
	for(int i=0;i<4;i++){
		if(cnt[i] < demandCnt[i]) return false;
	}
	return true;
}

int getInitCount(){
	for(int i=0;i<P;i++){
		addChar(str[i]);
	}
	return isValid(str.substr(P));
}

int solution(){
	int answer = getInitCount();
	if(answer) flag = true;
	
	int pl = 0, pr = P-1;
	while(pr+1 < str.size()){
		cancelChar(str[pl]);
		pl++;

		pr++;
		addChar(str[pr]);

		if(!flag) flag = isValidFlag();
		if(flag) answer++;
	}
	return answer;
}

int main(){
	fastio;
	input();
	cout << solution() << endl;

	return 0;
}