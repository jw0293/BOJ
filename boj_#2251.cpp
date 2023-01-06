#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define Mod 12345678910
#define endl '\n'

using namespace std;

typedef struct Set{
	int first;
	int second;
	int third;
}Set;

int a, b, c;
int cur[3 + 1], temp[3 + 1];
bool bowl[201][201][201];
bool visited[200 + 1];

void input(){
	cin >> a >> b >> c;
	cur[3] = c;
}

int getBowlPower(int index){
	switch (index)
	{
	case 1:
		return a;
	case 2:
		return b;
	case 3:
		return c;
	}
	return -1;
}

vector<int> solution(){
	vector<int> answer;
	memset(bowl, false, sizeof(bowl));
	bowl[0][0][c] = true;
	visited[cur[3]] = true;
	answer.push_back(c);

	queue<Set> q;
	q.push({cur[1], cur[2], cur[3]});
	while(!q.empty()){
		Set curPos = q.front();
		cur[1] = curPos.first; 
		cur[2] = curPos.second;
		cur[3] = curPos.third;
		q.pop();

		if(!visited[cur[3]] && !cur[1]){
			visited[cur[3]] = true;
			answer.push_back(cur[3]);
		}

		for(int i=1;i<=3;i++){
			if(i != 0){
				for(int j=1;j<=3;j++){
					if(i == j) continue;

					temp[1] = cur[1];
					temp[2] = cur[2];
					temp[3] = cur[3];

					if(temp[j] + temp[i] > getBowlPower(j)){
						int val = getBowlPower(j) - temp[j];
						temp[j] = getBowlPower(j);
						temp[i] -= val;
					} else{
						temp[j] += temp[i];
						temp[i] = 0;	
					}

					if(!bowl[temp[1]][temp[2]][temp[3]]){
						bowl[temp[1]][temp[2]][temp[3]] = true;
						q.push({temp[1], temp[2], temp[3]});
					}
				}
			}
		}
	}
	sort(answer.begin(), answer.end());
	return answer;
}
 
int main() {
	fastio;
	input();
	vector<int> result = solution();
	for(auto s : result) {
		cout << s <<  " ";
	}
	cout << endl;
 
	return 0;
}