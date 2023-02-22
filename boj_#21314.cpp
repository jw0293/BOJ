#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e18 + 3
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int cnt = 0;
string str;

void input(){
	cin >> str;
	for(int i=0;i<str.size();i++){
		if(str[i] == 'K') cnt++;
	}
}

string getM(string op){
	int size = op.size()-1;
	string ret = "1";
	for(int i=0;i<size;i++) ret += "0";
	return ret;
}

string getMK(string op){
	int size = op.size() - 1;
	string ret = "5";
	for(int i=0;i<size;i++) ret += "0";
	return ret;
}

string getMax(){
	int count = cnt;
	string temp = "", result = "";
	for(int i=0;i<str.size();i++){
		if(str[i] == 'K'){
			count--;
			temp += str[i];
			result += getMK(temp);
			temp.clear();
			continue;
		}
		if(!temp.empty() && !count) {
			result += getM(temp);
			temp.clear();
		}
		temp += str[i];
	}
	if(!temp.empty()) result += getM(temp);
	return result;
}

string getMin(){
	string temp = "", result = "";
	for(int i=0;i<str.size();i++){
		if(str[i] == 'K'){
			if(!temp.empty()) result += getM(temp);
			result += getMK("K");
			temp.clear();
			continue;
		}
		temp += str[i];
	}
	if(!temp.empty()) result += getM(temp);
	return result;
}

void solution(){
	cout << getMax() << endl;
	cout << getMin() << endl;
}

int main(){
	fastio;
	input();
	solution();

	return 0;
}