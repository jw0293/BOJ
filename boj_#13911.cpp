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
#include <ctime>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ENDL cout << endl
#define ll long long
#define ull unsigned long long
#define INF 987654321
#define Mod 1000000009
#define endl '\n'
#define pil pair<int,int>

using namespace std;

typedef struct GraphNode {
	int dest;
	int cost;
	GraphNode* next;
}GraphNode;

typedef struct Graph {
	GraphNode* adj;
}Graph;

int V, E;
priority_queue<pair<int, int>, vector<pair<int, int>>> pq;

void Init_Graph(Graph* gph, int count) {
	gph->adj = (GraphNode*)malloc(sizeof(GraphNode) * (count + 3));
	for (int i = 1; i <= count; i++) {
		gph->adj[i].next = NULL;
	}
}

void Reset(Graph* gph, int count) {
	for (int i = 1; i <= count; i++) {
		gph->adj[i].next = NULL;
		free(gph->adj[i].next);
	}
}

int AddDirectedLinked(Graph* gph, int src, int dst, int cost) {
	GraphNode* Temp = (GraphNode*)malloc(sizeof(GraphNode));
	Temp->cost = cost;
	Temp->dest = dst;
	Temp->next = gph->adj[src].next;
	gph->adj[src].next = Temp;
	return 1;
}

int AddUnDirectedLinked(Graph* gph, int src, int dst, int cost) {
	return AddDirectedLinked(gph, src, dst, cost) && AddDirectedLinked(gph, dst, src, cost);
}

void Dijkstra(Graph* gph, vector<int>& dist) {
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int node = pq.top().second;
		pq.pop();

		GraphNode* head = gph->adj[node].next;
		while (head) {
			if (head->cost + cost < dist[head->dest]) {
				dist[head->dest] = head->cost + cost;
				pq.push({ -(head->cost + cost), head->dest });
			}
			head = head->next;
		}
	}
}

int main() {
	fastio;
	Graph graph;
	cin >> V >> E;
	Init_Graph(&graph, V);

	int a, b, c;
	while (E--) {
		cin >> a >> b >> c;
		AddUnDirectedLinked(&graph, a, b, c);
	}

	int M, x, S, y;
	cin >> M >> x;
	vector<int> dist1(V + 1, INF);
	for (int i = 0; i < M; i++) {
		int mac; cin >> mac;
		dist1[mac] = 0;
		pq.push({ 0, mac });
	}
	Dijkstra(&graph, dist1);

	cin >> S >> y;
	vector<int> dist2(V + 1, INF);
	for (int i = 0; i < S; i++) {
		int star; cin >> star;
		dist2[star] = 0;
		pq.push({ 0, star });
	}
	Dijkstra(&graph, dist2);

	int answer_node = -1, answer_dist = INF;
	for (int node = 1; node <= V; node++) {
		if (dist1[node] && dist2[node] && dist1[node] <= x && dist2[node] <= y)
			answer_dist = answer_dist < dist1[node] + dist2[node] ? answer_dist : dist1[node] + dist2[node];
	}

	if (answer_dist != INF)
		cout << answer_dist << endl;
	else
		cout << -1 << endl;

	return 0;
}