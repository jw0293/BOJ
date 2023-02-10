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
	return parent[x] = getParent(parent[x]);
}

void unionNode(int a, int b){
	int parentA = getParent(a);
	int parentB = getParent(b);
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
	for(int i=2;i<=N;i++){
		if(parent[i] != parent[1]) return false;
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
		if(isSame(cur.x, cur.y)) {
			temp.push_back(cur);
			continue;
		}

		unionNode(cur.x, cur.y);
		score += cur.cost;
		pq2.push(cur);
	}

	for(auto &tmp : temp) {
		pq1.push(tmp);
	}

	return score;
}

void initParent(vector<int> &re, int t){
	re.push_back(t);
	visited[t] = true;
	minParent = min(minParent, t);

	for(int i=1;i<=N;i++){
		if(!visited[i] && conn[t][i]){
			initParent(re, i);
		}
	}
}

Info deConnect(){
	Info deconn = pq2.top();
	pq2.pop();
	conn[deconn.y][deconn.x] = 0;
	conn[deconn.x][deconn.y] = 0;

	return deconn;
}

void dfs(int x){
	vector<int> re;
	minParent = INF;
	memset(visited, false, sizeof(visited));
	initParent(re, x);
	for(auto &r : re) parent[r] = minParent;
}

void initParent(int a, int b){
	vector<int> re;
	dfs(a);
	dfs(b);
}

vector<int> solution(){
	vector<int> answer(K, 0);
	int firstScore = getMST();
	if(!isMST()) return answer;
	answer[0] = firstScore;

	int result = firstScore;
	for(int i=1;i<K;i++){
		Info deconn = deConnect();
		initParent(deconn.x, deconn.y);
		result -= deconn.cost;

		result += getMST();
		if(!isMST()) return answer;
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