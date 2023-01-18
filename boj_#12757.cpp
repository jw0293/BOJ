#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 123456789
#define endl '\n'

using namespace std;

typedef long long ll;

int N, M, K;
map<int, int> m;
set<int> s;

void input(){
	cin >> N >> M >> K;
	for(int i=0;i<N;i++){
		int key, value;
		cin >> key >> value;

		s.insert(key);
		m[key] = value;
	}
}

pair<int, int> getLowerUpper(int key){
	int lower, upper;
	if(key - K < 0) lower = 0;
	else lower = key - K;

	if(key + K > 1000000000) upper = 1000000000;
	else upper = key + K;

	return {lower, upper};
}

int getIndex(int key){
	pair<int, int> info = getLowerUpper(key);
	int lower = info.first, upper = info.second;

	set<int>::iterator l;
	int cache = INF, index = -1, cnt = 0;
	for(l = s.lower_bound(lower);l != s.upper_bound(upper); l++){
		if(*l == key) return *l;
		if(abs(*l - key) < cache){
			cnt = 0;
			cache = abs(*l - key);
			index = *l;
		} 
		else if(abs(*l - key) == cache){
			cnt++;
		}
	}

	if(cnt != 0) return INF;
	else if(index == -1) return -1;
	return index;
}

void solution(){
	for(int i=0;i<M;i++){
		int method, key, value;
		cin >> method;
		switch (method){
		case 1:
			cin >> key >> value;

			s.insert(key);
			m[key] = value;
			break;
		case 2:
			cin >> key >> value;
			{
				int index = getIndex(key);
				if(!(index == INF || index == -1)) {
					m[index] = value;
				}
			}
			break;
		case 3:
			cin >> key;
			if(m.find(key) != m.end()) cout << m[key] << endl;
			else{
				int index = getIndex(key);
				if(index == INF) cout << "?" << endl;
				else if(index == -1) cout << -1 << endl;
				else cout << m[index] << endl;
			}
			break;
		}
	}
}

int main() {
	fastio;
	input();
	solution();
	
	return 0;
}