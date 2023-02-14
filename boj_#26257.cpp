#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e9+3
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int N, M, Q;
bool visited[200000 + 1];
int ptr[200000 + 1];

const string ASSIGN = "assign";
const string SWAP = "swap";
const string RESET = "reset";

void input(){
	cin >> N >> M >> Q;
	for(int i=1;i<=M;i++){
		cin >> ptr[i];
	}

	for(int i=0;i<Q;i++){
		string order;
		int first, second;
		cin >> order;
		if(order == ASSIGN){
			cin >> first >> second;
			ptr[first] = ptr[second];
		} else if(order == SWAP){
			cin >> first >> second;
			int temp = ptr[first];
			ptr[first] = ptr[second];
			ptr[second] = temp;
		} else {
			cin >> first;
			ptr[first] = 0;
		}
	}
}

void solution(){
	int cnt = 0;
	vector<int> result;
	for(int i=1;i<=M;i++){
		if(ptr[i] != 0 && !visited[ptr[i]]){
			cnt++;
			result.push_back(ptr[i]);
			visited[ptr[i]] = true;
		}
	}

	sort(result.begin(), result.end());
	cout << cnt << endl;
	for(auto &pt : result) cout << pt << endl;
}

int main(){
	fastio;
	input();
	solution();

	return 0;
}