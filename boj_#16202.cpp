#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e9+3
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef struct Info{
	int x;
	int y;
	int cost;
}Info;
struct cmp{
	bool operator()(Info &lhs, Info &rhs){
		return lhs.cost > rhs.cost;
	}
};

int N, M, K, minParent;
int parent[1000 + 1];
bool visited[1000 + 1];
int conn[1000 + 1][1000 + 1];
priority_queue<Info, vector<Info>, cmp> pq1, pq2;

void init(){
	for(int i=1;i<=N;i++) parent[i] = i;
}

int getParent(int x){
	if(x == parent[x]) return x;
	return x = getParent(parent[x]);
}

void unionNode(int a, int b){
	int parentA = getParent(a);
	int parentB = getParent(b);
	cout << "A Number : " << a << " Parent is " << parentA << endl;
	cout << "B Number : " << b << " Parent is " << parentB << endl;
	if(parentA < parentB){
		for(int i=1;i<=N;i++){
			if(parent[i] == parentB) parent[i] = parentA;
		}
	} else{
		for(int i=1;i<=N;i++){
			if(parent[i] == parentA) parent[i] = parentB;
		}
	}
	conn[a][b] = conn[b][a] = 1;
}

bool isSame(int a, int b){
	return getParent(a) == getParent(b);
}

bool isMST(){
	int p = getParent(1);
	for(int i=2;i<=N;i++){
		if(parent[i] != p) {
			cout << "Parent DIFF --> " << i  << " >> " << parent[i] << endl;
			return false;
		}
	}
	return true;
}

void input(){
	cin >> N >> M >> K;
	init();
	for(int i=1;i<=M;i++){
		int a, b;
		cin >> a >> b;

		pq1.push({a, b, i});
	}
}

int getMST(){
	int score = 0;
	vector<Info> temp;
	while(!pq1.empty()){
		if(isMST()) break;
		Info cur = pq1.top();
		pq1.pop();
		cout << "[ " << cur.x << " : " << cur.y << " ] -> " << cur.cost << endl;
		if(isSame(cur.x, cur.y)) {
			temp.push_back(cur);
			continue;
		}

		unionNode(cur.x, cur.y);
		score += cur.cost;
		pq2.push(cur);
	}
	for(auto &tmp : temp) {
		cout << "==> " << tmp.cost << endl;
		pq1.push(tmp);
	}
	return score;
}

void initParent(int c, int t){
	bool flag = false;
	visited[t] = true;
	minParent = min(minParent, t);
	for(int i=1;i<=N;i++){
		if(!visited[i] && conn[t][i]) {
			flag = true;
			break;
		}
	}
	if(!flag) {
		cout << "---> " << c << " : " << minParent << endl;
		parent[t] = minParent;
		return;
	}

	for(int i=1;i<=N;i++){
		if(!visited[i] && conn[t][i]){
			initParent(c, i);
		}
	}

	parent[t] = minParent;
}

vector<int> solution(){
	vector<int> answer(K, 0);
	int firstScore = getMST();
	if(!isMST()) return answer;
	answer[0] = firstScore;

	int result = firstScore;
	for(int i=1;i<K;i++){
		Info deconn = pq2.top();
		pq2.pop();

		conn[deconn.y][deconn.x] = 0;
		conn[deconn.x][deconn.y] = 0;

		minParent = INF;
		memset(visited, false, sizeof(visited));
		initParent(i, deconn.x);
		minParent = INF;
		memset(visited, false, sizeof(visited));
		initParent(i, deconn.y);

		result -= deconn.cost;

		result += getMST();
		if(!isMST()) {
			cout << "No MST " << endl;
			return answer;
		}
		answer[i] = result;
	}
	return answer;
}

int main(){
	fastio;
	input();
	vector<int> result = solution();
	for(auto &t : result) cout << t << " ";
	cout << endl;

	return 0;
}