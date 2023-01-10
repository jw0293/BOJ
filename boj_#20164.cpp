#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 123456789
#define endl '\n'

using namespace std;

string N;
int maxV = -INF, minV = INF;

void input(){
	cin >> N;
}

int countingInitNumber(){
	int cnt = 0;
	for(int i=0;i<N.size();i++){
		if((N[i] - '0') % 2 != 0) cnt++;
	}
	return cnt;
}

int getOddNumber(string temp){
	int count = 0;
	for(int i=0;i<temp.size();i++){
		if((temp[i] % 2 != 0)) {
			count++;
		}
	}
	return count;
}

int getSum(string s1, string s2, string s3){
	return stoi(s1) + stoi(s2) + stoi(s3);
}

void func(string n, int cnt){
	if(n.size() == 1){
		maxV = max(maxV, cnt);
		minV = min(minV, cnt);
		return;
	}

	if(n.size() == 2){
		string temp = to_string((n[0]-'0') + (n[1]-'0'));
		int count = getOddNumber(temp);
		func(temp, cnt+count);
	} else { 
		for(int i=1;i<n.length()-1;i++){
			for(int j=i+1;j<n.length();j++){
				string s1 = n.substr(0, i);
				string s2 = n.substr(i, j-i);
				string s3 = n.substr(j, n.length()-j);

				int sum = getSum(s1, s2, s3);
				string temp = to_string(sum);
				int count = getOddNumber(temp);

				func(temp, cnt+count);
			}
		}
	}
}

void solution(){
	int cnt = countingInitNumber();
	func(N, cnt);
	cout << minV << " " << maxV << endl;
}

int main() {
	fastio;
	input();
	solution();
	
	return 0;
}