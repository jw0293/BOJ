#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e9+3
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int N;
vector<int> chain;

void input(){
	cin >> N;
	chain.resize(N, 0);
	for(int i=0;i<N;i++){
		cin >> chain[i];
	}
}

int solution(){
	int startIndex = 0, index = chain.size()-1, ans = 0;
	sort(chain.begin(), chain.end());
	while(startIndex < index){
		while(chain[startIndex]){
			ans++;
			index--;
			chain[startIndex]--;
			if(startIndex == index) break;
		}
		if(startIndex == index) break;
		startIndex++;
	}
	return ans;
}

int main(){
	fastio;
	input();
	cout << solution() << endl;

	return 0;
}