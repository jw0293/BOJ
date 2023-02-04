#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e9+3
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int spaceCnt;
string content;
int cnting[26 + 1];

void input(){
	getline(cin, content);
	cin >> spaceCnt;
	for(int i=0;i<26;i++){
		cin >> cnting[i];
	}
}

string solution(){
	string title = "";
	bool isNext = false;
	char prev = content[0];

	title += toupper(content[0]);
	cnting[tolower(content[0]) - 'a']--;

	for(int i=1;i<content.size();i++){
		if(prev == content[i]) continue;
		if(content[i] == ' '){
			isNext = true;
			spaceCnt--;
		} else{
			if(isNext) {
				isNext = false;
				title += toupper(content[i]);
			}
			cnting[tolower(content[i])-'a']--;
		}
		prev = content[i];
	}
	return title;
}

bool isCan(){
	if(spaceCnt < 0) return false;
	for(int i=0;i<26;i++){
		if(cnting[i] < 0) return false;
	}
	return true;
}

bool isCanTitle(string &title){
	for(int i=0;i<title.size();i++){
		if(cnting[tolower(title[i])]-'a' <= 0) return false;
	}
	return true;
}

int main(){
	fastio;
	input();
	string answer = solution();
	if(!isCan() || !isCanTitle(answer)) cout << -1 << endl;
	else cout << answer << endl;

	return 0;
}