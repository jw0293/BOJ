#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 123456789
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

string str;
set<char> op;
set<string> word;
vector<string> hps;
const char ops[] = {'a', 'e', 'i', 'o', 'u', 'h'};
const string words[] = {"c", "j", "n", "m", "t", "s", "l", "d", "qu", "s"};

void init(){
	for(auto &o : ops) op.insert(o);
	for(auto &w : words) word.insert(w);
}

void input(){
	getline(cin, str);
	string temp = "";
	for(int i=0;i<str.size();i++){
		if(str[i] == ' ' || str[i] == '-'){
			hps.push_back(temp);
			temp.clear();
			continue;
		}
		temp += str[i];
	}
	if(!temp.empty()) hps.push_back(temp);
}


int solution(){
	vector<string> tempHps;
	string temp = "";
	for(int i=0;i<hps.size();i++){
		for(int j=0;j<hps[i].size();j++){
			if(hps[i][j] == '\'' && word.find(temp) != word.end() && op.find(hps[i][j+1]) != op.end()){
				temp += 'e';
				tempHps.push_back(temp);
				temp.clear();
				continue;
			}
			temp += hps[i][j];
		}
		if(!temp.empty()) {
			tempHps.push_back(temp);
			temp.clear();
		}
	}
	hps = tempHps;

	return hps.size();
}

int main(){
	fastio;
	init();
	input();
	cout << solution() << endl;

	return 0;
}