#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e9 + 3
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

string str;
stack<char> stk;

void initStk(){
	while(!stk.empty()) stk.pop();
}

int getZeroCnt(string &str, int idx){
	int cnt = 0;
	for(int i=idx;i<str.size();i++){
		if(str[i] == '1' && cnt != 0) return cnt;
		if(str[i] == '0'){
			cnt++;
		}
	}
	return cnt;
}

int getZeroIndex(string &str, int idx){
	for(int i=idx;i<str.size();i++){
		if(str[i] == '0') return i;
	}
	return -1;
}	

string solution(string &str){
	int idx = 0;
	while(idx < str.size()){
		char c = str[idx];

		if(stk.empty()){
			if(c == '0'){
				if(idx + 2 > str.size()) return "No";
				string sub = str.substr(idx, 2);
				if(sub != "01") return "No";
				if(idx + 2 >= str.size()) return "Yes";
				idx += 2;
			} else{
				stk.push(c);
				idx++;
			}
		} else{
			if(c == '0'){
				stk.push(c);
				idx++;
			} else{
				if(stk.size() < 3) return "No";
				else {
					int zeroCnt = getZeroCnt(str, idx);
					if(zeroCnt == 0) return "Yes";
					if(zeroCnt == 1){
						int zeroIndex = getZeroIndex(str, idx);
						idx = zeroIndex;
						initStk();
					} else{
						int zeroIndex = getZeroIndex(str, idx);
						if(idx +1 == zeroIndex) return "No"; 
						initStk();
						stk.push(c);
						idx = zeroIndex;
					}
				}
			}
		}
	}
	return stk.empty() ? "Yes" : "No";
}

void input(){
	int tc;
	cin >> tc;
	while(tc--){
		cin >> str;
		initStk();

		cout << solution(str) << endl;
	}
}

int main(){
	fastio;
	input();

	return 0;
}
