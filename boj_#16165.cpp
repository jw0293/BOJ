#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e18 + 3
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int N, M;
map<string, vector<string>> team;
map<string, string> member;

void input(){
	cin >> N >> M;
	for(int i=0;i<N;i++){

		string teamName;
		int memberCount;
		vector<string> members;
		
		cin >> teamName >> memberCount;
		for(int j=0;j<memberCount;j++){
			string name;
			cin >> name;

			member[name] = teamName;
			members.push_back(name);
		}
		sort(members.begin(), members.end());

		team[teamName] = members;
	}
}

void solution(){
	while(M--){
		string whos;
		int order;

		cin >> whos >> order;
		if(!order){
			for(auto &nm : team[whos]) cout << nm << endl;
		} else{
			cout << member[whos] << endl;
		}
	}
}

int main(){
	fastio;
	input();
	solution();

	return 0;
}
