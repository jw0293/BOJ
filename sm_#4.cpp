#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e18 + 3
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

vector<string> input(){
	int n;
	cin >> n;
	vector<string> cps;
	for(int i=0;i<n;i++){
		string c;
		cin >> c;
		cps.push_back(c);
	}
	return cps;
}

pair<int, int> getIndex(int idx, char op, vector<string> &cps){
	for(int i=idx+1;i<cps.size();i++){
		if(cps[i][0] == op) return {i, 0};
		if(cps[i][1] == op) return {i, 1};
	}
	return {idx, 0};
}

int getCountSwap(pair<int, int> purpose, pair<int, int> cur,vector<string> &cps){
	int count = 0;
	while(purpose.first != cur.first){
		if(purpose.first + 1 == cur.first) {
			count++;
			swap(cps[purpose.first][(purpose.second+1)%2], cps[cur.first][cur.second]);
			break;
		}

		pair<int, int> prevLeft = getIndex(cur.first-1, cps[cur.first-1][0], cps);
		pair<int, int> prevRight = getIndex(cur.first-1, cps[cur.first-1][1], cps);

		cout << "PREVLEFT : [ " << prevLeft.first << ", " << prevLeft.second << " ]" << endl;
		cout << "PREVRIGHT : [ " << prevRight.first << ", " << prevRight.second << " ]" << endl;

		if(prevLeft.first == prevRight.first){
			swap(cps[prevLeft.first][(prevLeft.second+1)%2], cps[cur.first][cur.second]);

			cur.first = prevLeft.first;
			cur.second = (prevLeft.second+1)%2;
		} else{
			if(prevLeft.first < prevRight.first) {
				swap(cps[prevRight.first][(prevRight.second+1)%2], cps[cur.first][cur.second]);

				cur.first = prevRight.first;
				cur.second = (prevRight.second+1)%2;
			} else{
				swap(cps[prevLeft.first][(prevLeft.second+1)%2], cps[cur.first][cur.second]);
				
				cur.first = prevLeft.first;
				cur.second = (prevLeft.second+1)%2;
			}
		}
		count++;
	}
	return count;
}

int solution(vector<string> &chopsticks){
	int answer = 0;
	for(int i=0;i<chopsticks.size()-1;i++){
		if(chopsticks[i][0] == chopsticks[i][1]) continue;

		for(auto &c : chopsticks) cout << "[ " << c[0] << ":" << c[1] << " ]" << endl;

		pair<int, int> left = getIndex(i, chopsticks[i][0], chopsticks);
		pair<int, int> right = getIndex(i, chopsticks[i][1], chopsticks);

		if(left.first == right.first){
			answer += getCountSwap({i,0}, left, chopsticks);
		} else{
			if(left.first < right.first) answer += getCountSwap({i,0}, left, chopsticks);
			else answer += getCountSwap({i,1}, right, chopsticks);
		}
		cout << endl;
	}
	return answer;
}

int main(){
	fastio;
	vector<string> cps = input();
	cout << solution(cps) << endl;

	return 0;
}
