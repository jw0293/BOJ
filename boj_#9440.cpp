#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 123456789
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

bool visited[14 + 1];
string numbers[2] = {"",""};

void addInteger(string &number, vector<int> &ps){
	for(int i=0;i<ps.size();i++){
	if(number.size() == 0 && ps[i] == 0) continue;
		if(!visited[i]){
			visited[i] = true;

			number += to_string(ps[i]);
			break;
		}
	}
}

void makeNumbers(vector<int> &ps){
	int index = 0;
	while(1){
		bool isNot = false;
		for(int i=0;i<ps.size();i++){
			if(numbers[index].size() == 0 && ps[i] == 0) continue;
			if(!visited[i]){
				isNot = true;
				visited[i] = true;

				numbers[index] += to_string(ps[i]);
				index = !index;
				break;
			}
		}
		if(!isNot) break;
	}
}

int solution(vector<int> &ps){
	int index = 0;
	numbers[0].clear();
	numbers[1].clear();
	sort(ps.begin(), ps.end());
	memset(visited, false, sizeof(visited));
	
	if(ps.size() % 2 == 0){
		makeNumbers(ps);
	} else{
		addInteger(numbers[index], ps);
		makeNumbers(ps);
	}

	return stoi(numbers[0]) + stoi(numbers[1]);
}

void input(){
	while(1){
		int N;
		cin >> N;
		if(!N) break;

		vector<int> ps(N, 0);
		for(int i=0;i<N;i++){
			cin >> ps[i];
		}

		cout << solution(ps) << endl;
	}
}

int main() {
	fastio;
	input();


	return 0;
}