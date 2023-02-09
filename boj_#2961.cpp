#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e9+3
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int N, answer = INF;
bool visited[10 + 1];
vector<pair<int, int>> op;

void input(){
	cin >> N;
	op.resize(N);
	for(int i=0;i<N;i++){
		cin >> op[i].first >> op[i].second;
	}
}

int getScore(vector<int> &temp){
	int S = 1, B = 0;
	for(auto &index : temp){
		S *= op[index].first;
		B += op[index].second;
	}
	return abs(S - B);
}

void dfs(int cnt, vector<int> &temp){
	if(cnt == temp.size()){
		answer = min(answer, getScore(temp));
		return;
	}

	for(int i=0;i<N;i++){
		if(!visited[i]){
			visited[i] = true;
			temp.push_back(i);

			dfs(cnt, temp);

			visited[i] = false;
			temp.pop_back();
		}
	}
}

int solution(){
	vector<int> temp;
	for(int i=1;i<=N;i++){
		dfs(i, temp);
	}
	return answer;
}

int main(){
	fastio;
	input();
	cout << solution() << endl;

	return 0;
}