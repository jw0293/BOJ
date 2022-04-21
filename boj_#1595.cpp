#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <string>
#include <cstring>
#include <sstream>
#include <set>
#include <unordered_set>
#include <map> 
#include <algorithm>
#include <cmath>
#define CUNLINK ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ENDL cout << endl
#define ll long long
#define ull unsigned long long
#define INF 987654321987654
#define Mod 1000000009
#define endl '\n'
#define pil pair<int,int>

using namespace std;

typedef struct GraphNode {
	ull dest;
	ull cost;
	struct GraphNode* next;
}GraphNode;

typedef struct Graph {
	int cnt;
	GraphNode* adj;
}Graph;

ull dist[10001];
priority_queue<pair<ull, ull>, vector<pair<ull, ull>>, greater<pair<ull, ull>>> pq;

void Init_Graph(Graph* gph, int count) {
	gph->cnt = count;
	gph->adj = (GraphNode*)malloc(sizeof(GraphNode) * (count + 1));
	for (int i = 1; i <= count; i++) {
		dist[i] = INF;
		gph->adj[i].next = NULL;
	}
}

int AddDirectedLinkedEdge(Graph* gph, ull src, ull dst, ull cost) {
	GraphNode* Temp = (GraphNode*)malloc(sizeof(GraphNode));
	Temp->cost = cost;
	Temp->dest = dst;
	Temp->next = gph->adj[src].next;
	gph->adj[src].next = Temp;

	return 1;
}

int AddUnDirectedLinkedEdge(Graph* gph, ull src, ull dst, ull cost) {
	return AddDirectedLinkedEdge(gph, src, dst, cost) && AddDirectedLinkedEdge(gph, dst, src, cost);
}

void Dijkstra(Graph* gph, ull S) {
	dist[S] = 0;
	pq.push({ 0, S });

	while (!pq.empty()) {
		ull prev_cost = pq.top().first;
		ull prev_Node = pq.top().second;
		pq.pop();
		GraphNode* head = gph->adj[prev_Node].next;

		while (head) {
			if (prev_cost + head->cost < dist[head->dest]) {
				dist[head->dest] = prev_cost + head->cost;
				pq.push({ dist[head->dest], head->dest });
			}
			head = head->next;
		}
	}
}

void Reset_Distance(int n) {
	for (int i = 1; i <= n; i++) dist[i] = INF;
}

int main() {
	CUNLINK;
	Graph graph;
	Init_Graph(&graph, 10000);
	string str;
	priority_queue<ull> g;
	priority_queue<ull, vector<ull>, greater<ull>> m;
	ull From, To, Cost;
	while (getline(cin, str)) {
		if (str.empty() || str == "0") break;
		stringstream ps(str);
		ps >> From >> To >> Cost;
		g.push(From); g.push(To);
		m.push(From); m.push(To);
		AddUnDirectedLinkedEdge(&graph, From, To, Cost);
	}
	if (m.empty()) {
		cout << 0 << endl;
		exit(0);
	}
	ull start = m.top();
	Dijkstra(&graph, start);

	int idx;
	ull maxV = 0;
	for (int i = 1; i <= g.top(); i++) {
		if (maxV < dist[i]) idx = i;
		maxV = max(maxV, dist[i]);
	}

	Reset_Distance(g.top());
	Dijkstra(&graph, idx);
	ull answer = 0;
	for (int i = 1; i <= g.top(); i++) {
		answer = max(answer, dist[i]);
	}
	cout << answer << endl;

	return 0;
}