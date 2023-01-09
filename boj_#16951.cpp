#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define Mod 12345678910
#define endl '\n'

using namespace std;

int N, K;
bool visited[1000 + 1];
vector<int> ps;

void input(){
	cin >> N >> K;
	ps.resize(N, 0);
	for(int i=0;i<N;i++){
		cin >> ps[i];
	}
}

vector<int> initNewArray(int first){
	vector<int> op;

	op.push_back(first);
	for(int i=0;i<N-1;i++){
		op.push_back(op.back() + K);
	}
	return op;
}

int getTime(vector<int> &op){
	int cnt = 0;
	for(int i=0;i<ps.size();i++){
		if(ps[i] != op[i]){
			cnt++;
		}
	}
	return cnt;
}

int solution(){
	int answer = INT_MAX;
	for(int i=0;i<N;i++){
		int start = ps[i] - (K * i);
		if(start <= 0 || visited[start]) continue;
		visited[start] = true;
		vector<int> op = initNewArray(start);
		answer = min(answer, getTime(op));
	}
	return answer;
}

int main() {
	fastio;
	input();
	cout << solution() << endl;
	
	return 0;
}