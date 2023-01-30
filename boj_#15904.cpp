#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 123456789
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

vector<char> ret;
const char op[] = {'U', 'C', 'P', 'C'};

void input(){
	string str;
	getline(cin, str);
	for(int i=0;i<str.size();i++){
		if(!('A' <= str[i] && str[i] <= 'Z')) continue;
		if(str[i] == 'U' || str[i] == 'C' || str[i] == 'P') {
			ret.push_back(str[i]);
		}
	}
}

string solution(){
	int idx = 0;
	for(int i=0;i<ret.size();i++){
		if(ret[i] == op[idx]){
			idx++;
			if(idx == 4) return "I love UCPC";
		}
	}
	return "I hate UCPC";
}

int main(){
	fastio;
	input();
	cout << solution() << endl;

	return 0;
}