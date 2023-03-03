#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e18 + 3
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int MX = 1000 + 5;

int N, M, unused = 1;
int inDeg[MX];

vector<int> adj[MX];
vector<string> names;
map<string, int> name2number;
map<int, string> number2name;

vector<string> info[MX];

void input(){
	cin >> N;
	for(int i=0;i<N;i++){
		string name;
		cin >> name;

		name2number[name] = unused;
		number2name[unused] = name;

		unused++;

		names.push_back(name);
	}

	cin >> M;
	for(int i=0;i<M;i++){
		string from, to;
		cin >> from >> to;

		int from2number1 = name2number[from];
		int from2number2 = name2number[to];

		adj[from2number2].push_back(from2number1);

		inDeg[from2number1]++;
	}
}

void resultPrint(vector<string> &setNames){
	cout << setNames.size() << endl;
	sort(setNames.begin(), setNames.end());
	for(auto &st : setNames) cout << st << " ";
	cout << endl;

	sort(names.begin(), names.end());
	for(auto &n : names){
		cout << n << " " << info[name2number[n]].size() << " ";
		sort(info[name2number[n]].begin(), info[name2number[n]].end());
		for(auto &p : info[name2number[n]]) cout << p << " ";
		cout << endl;
	}
}

void solution(){
	vector<string> setNames;
	queue<int> q;
	for(int i=1;i<unused;i++){
		if(inDeg[i] == 0) {
			q.push(i);
			setNames.push_back(number2name[i]);
		}
	}

	while(!q.empty()){
		int cur = q.front();
		q.pop();

		for(auto &next : adj[cur]){
			inDeg[next]--;
			if(inDeg[next] == 0){
				q.push(next);
				info[cur].push_back(number2name[next]);
			}

		}
	}

	resultPrint(setNames);
}

int main(){
	fastio;
	input();
	solution();

	return 0;
}
