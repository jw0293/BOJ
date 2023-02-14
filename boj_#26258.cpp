#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e9+3
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int N, Q;
map<int, int> position;
vector<int> point1, point2;

void input(){
	cin >> N;
	for(int i=0;i<N;i++){
		int x, y;
		cin >> x >> y;
		position[x] = y;
		point1.push_back(x);
		point2.push_back(-x);
	}
}

void solution(){
	cin >> Q;
	sort(point1.begin(), point1.end());
	sort(point2.begin(), point2.end());
	for(int i=0;i<Q;i++){
		double quiz;
		cin >> quiz;

		int pos1 = lower_bound(point2.begin(), point2.end(), (-quiz)) - point2.begin();
		int pos2 = upper_bound(point1.begin(), point1.end(), quiz) - point1.begin();

		if(position[point1[point1.size()-1-pos1]] == position[point1[pos2]]) cout << 0 << endl;
		else{
			if(position[point1[point1.size()-1-pos1]] < position[point1[pos2]]) cout << 1 << endl;
			else cout << -1 << endl;
		}
	}
}

int main(){
	fastio;
	input();
	solution();

	return 0;
}