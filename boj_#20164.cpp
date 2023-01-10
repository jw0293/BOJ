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

vector<int> getNumbers(string number){
	vector<int> v;
	for(int i=0;i<number.size()-1;i++){
		v.push_back(i+1);
	}
	return v;
}

vector<int> getInit(int n){
	vector<int> s(n,0);
	for(int i=n-2;i<n;i++) s[i] = 1;
	return s;
}

void func(string n, int cnt){
	if(n.size() == 1){
		maxV = max(maxV, cnt);
		minV = min(minV, cnt);
		return;
	}

	if(n.size() == 2){
		int count = 0;
		int a = n[0] - '0';
		int b = n[1] - '0';
		string temp = to_string(a+b);
		for(int i=0;i<temp.size();i++){
			if((temp[i]-'0') % 2 != 0) count++;
		}
		func(temp, cnt+count);
	}else { 
		int c = 0;
		vector<int> ps, op;
		for(int i=1;i<=n.size()-1;i++){
			ps.push_back(i);
			if(c < 2){
				op.push_back(1);
				c++;
			} else{
				op.push_back(0);
			}
		}
		do{
			vector<int> idx;
			for(int i=0;i<ps.size();i++){
				if(op[i] == 1){
					idx.push_back(ps[i]);
				}
			}
			string first = n.substr(0, idx[0]);
			string second = n.substr(idx[0], idx[1]-idx[0]);
			string third = n.substr(idx[1], idx[2]-idx[1]);

			int sum = stoi(first) + stoi(second) + stoi(third);
			string temp = to_string(sum);

			int count = 0;
			for(int i=0;i<temp.size();i++){
				int x = temp[i]-'0';
				if(x % 2 != 0) count++;
			}
			func(temp, cnt+count);
		}while(prev_permutation(op.begin(), op.end()));
	}
}

void solution(){
	int cnt = 0;
	for(int i=0;i<N.size();i++){
		if((N[i] - '0') % 2 != 0) cnt++;
	}
	func(N, cnt);
	cout << minV << " " << maxV << endl;
}

int main() {
	fastio;
	input();
	solution();
	
	return 0;
}