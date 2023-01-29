#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 123456789
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

set<char> mp;
const char chs[] = {'A', 'B', 'C', 'D', 'E', 'F'};

void init(){
	for(int i=0;i<6;i++){
		mp.insert(chs[i]);
	}
}

bool firstStep(string &str, int &idx){
	bool flag = false;
	for(int i=idx;i<str.size();i++){
		if(str[i] == 'A'){
			flag = true;
			continue;
		}
		idx = i;
		break;
	}
	if(!flag || idx >= str.size()) return false;
	return true;
}

bool secondStep(string &str, int &idx){
	bool flag = false;
	for(int i=idx;i<str.size();i++){
		if(str[i] == 'F'){
			flag = true;
			continue;
		}
		idx = i;
		break;
	}
	if(!flag || idx >= str.size()) return false;
	return true;
}

bool thirdStep(string &str, int &idx){
	bool flag = false;
	for(int i=idx;i<str.size();i++){
		if(str[i] == 'C'){
			if(i == str.size()-1) idx = str.size();
			flag = true;
			continue;
		}
		idx = i;
		break;
	}
	if(!flag) return false;
	return true;
}

bool noStartMp(string &str, int index){
	int idx = index;
	if(!firstStep(str, idx)) return false;
	if(!secondStep(str, idx)) return false;
	if(!thirdStep(str, idx)) return false;
	if(idx < str.size()-1) return false;
	if(idx == str.size() - 1){
		if(mp.find(str[idx]) == mp.end()) return false;
	}
	return true;
}

bool startMp(string &str){
	if(mp.find(str[0]) == mp.end()) return false;
	if(!noStartMp(str, 1)) return false;
	return true;
}

string judgeString(string &str){
	if(noStartMp(str, 0)) return "Infected!";
	if(startMp(str)) return "Infected!";
	return "Good";
}

void input(){
	int testCase;
	cin >> testCase;
	while(testCase--){
		string str;
		cin >> str;
		cout << judgeString(str) << endl;
	}
}

int main(){
	fastio;
	init();
	input();

	return 0;
}