#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e9+3
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int N, L;
vector<pair<int, int>> ps;

bool cmp(pair<int, int> lhs, pair<int, int> rhs){
	if(lhs.first == rhs.first) return lhs.second > rhs.second;
	return lhs.first < rhs.first;
}

void input(){
	cin >> N >> L;
	ps.resize(N);
	for(int i=0;i<N;i++){
		cin >> ps[i].first >> ps[i].second;
	}
}

int counting(vector<pair<int, int>> &temp){
	int ans = 0, pos = temp[0].first, cnt;
	for(auto &cur : temp){
		cnt = 0;
		if(pos < cur.first) pos = cur.first;
		int len = cur.second - pos;
		if(len <= 0) continue;
		if(len % L == 0){
			pos = cur.second;
			cnt = len / L;
		} else{
			cnt = len / L + 1;
			pos = pos + cnt * L;
		}
		ans += cnt;
	}
	return ans;
}

int solution(){
	vector<pair<int, int>> temp;
	sort(ps.begin(), ps.end(), cmp);
	int begin = ps[0].first, end = ps[0].second, ans = 0;
	for(int i=1;i<ps.size();++i){
		if(end < ps[i].first){
			temp.push_back({begin, end});
			begin = ps[i].first;
			end = ps[i].second;
		} else{
			end = ps[i].second;
		}
	}
	temp.push_back({begin, end});
	return counting(temp);
}

int main(){
	fastio;
	input();
	cout << solution() << endl;

	return 0;
}