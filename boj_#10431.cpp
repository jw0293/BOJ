#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 123456789
#define endl '\n'

using namespace std;

bool isClear(vector<int> &temp, int value){
	for(int i=0;i<temp.size();i++){
		if(value < temp[i]) return false;
	}
	return true;
}

int solution(vector<int> &ps){
	vector<int> temp;
	int count = 0;
	for(int i=0;i<20;i++){
		if(temp.empty() || isClear(temp, ps[i])) temp.push_back(ps[i]);
		else{
			int index;
			int size = temp.size();
			for(int j=0;j<size;j++){
				if(ps[i] < temp[j]){
					index = j;
					break;
				}
			}
			count += temp.size() - index;
			vector<int>::iterator it = temp.begin();
			temp.insert(it+index, ps[i]);
		}
	}
	return count;
}

void input(){
	int testCase;
	cin >> testCase;
	while(testCase--){
		int number;
		cin >> number;
		vector<int> ps(20, 0);
		for(int i=0;i<20;i++){
			cin >> ps[i];
		}
		cout << number << " " << solution(ps) << endl;
	}
}

int main() {
	fastio;
	input();
	
	return 0;
}