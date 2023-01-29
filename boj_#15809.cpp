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
	int soilderPower = power[parentY] + power[parentX];
	if(parentY < parentX){
		parent[parentX] = parentY;
		power[parentY] = power[parentY] + power[parentX];
		power[parentX] = power[parentY];
	} else{
		parent[parentY] = parentX;
		power[parentX] = power[parentY] + power[parentX];
		power[parentY] = power[parentX];
	}
}

void warCountry(int y, int x){
	if(isSame(y, x)) return;
	int parentY = getParent(y);
	int parentX = getParent(x);
	if(power[parentY] < power[parentX]){
		power[parentX] = power[parentX] - power[parentY];
		power[parentY] = 0;
		parent[parentY] = parentX;
	} else if(power[parentY] > power[parentX]){ 
		power[parentY] = power[parentY] - power[parentX];
		power[parentX] = 0;
		parent[parentX] = parentY;
	} else{
		power[parentY] = power[parentX] = 0;
		parent[parentY] = parent[parentX] = -1;
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
		if(parent[i] == i && power[i] != 0){
			result.push_back(power[i]);
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