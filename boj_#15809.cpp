#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 123456789
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int N, M;
int parent[100000 + 1];
int power[100000 + 1];
bool visited[100000 + 1];

void init(){
	for(int i=1;i<=N;i++) parent[i] = i;
}

int getParent(int x){
	if(x == parent[x]) return x;
	return parent[x] = getParent(parent[x]);
}

bool isSame(int y, int x){
	return getParent(y) == getParent(x);
}

void unionCountry(int y, int x){
	int parentY = getParent(y);
	int parentX = getParent(x);
	int soilderPower = power[y] + power[x];
	if(parentY < parentX){
		for(int i=1;i<=N;i++){
			if(parent[i] == parentX) {
				parent[i] = parentY;
			}
			if(parent[i] == parentY){
				power[i] = soilderPower;
			}
		}
	} else{
		for(int i=1;i<=N;i++){
			if(parent[i] == parentY) {
				parent[i] = parentX;;
			}
			if(parent[i] == parentX){
				power[i] = soilderPower;
			}
		}
	}
}

void warCountry(int y, int x){
	int parentY = getParent(y);
	int parentX = getParent(x);
	if(power[y] < power[x]){
		int soliderPower = abs(power[y] - power[x]);
		for(int i=1;i<=N;i++){
			if(parent[i] == parentY) {
				parent[i] = parentX;
				power[i] = soliderPower;
			}
		}
	} else if(power[y] > power[x]){
		int soliderPower = abs(power[y] - power[x]);
		for(int i=1;i<=N;i++){
			if(parent[i] == parentX) {
				parent[i] = parentY;
				power[i] = soliderPower;
			}
		}
	} else{
		for(int i=1;i<=N;i++){
			if(parent[i] == parentY || parent[i] == parentX){
				parent[i] = -1;
			}
		}
	}
}

void input(){
	cin >> N >> M;
	init();
	for(int i=1;i<=N;i++){
		cin >> power[i];
	}

	for(int i=0;i<M;i++){
		int order, c1, c2;
		cin >> order >> c1 >> c2;

		if(order == 1){
			unionCountry(c1, c2);
		} else{
			warCountry(c1, c2);
		}
	}
}

vector<int> solution(){
	vector<int> result;
	for(int i=1;i<=N;i++){
		if(parent[i] == -1) continue;
		if(!visited[parent[i]]){
			visited[parent[i]] = true;
			result.push_back(power[parent[i]]);
		}
	}
	sort(result.begin(), result.end());

	return result;
}

int main(){
	fastio;
	input();
	vector<int> answer = solution();
	cout << answer.size() << endl;
	for(auto &t : answer) cout << t << " ";
	cout << endl;

	return 0;
}