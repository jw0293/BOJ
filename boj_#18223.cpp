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
#define pil pair<int,int>x	

using namespace std;

typedef struct GraphNode {
	int dest;
	int cost;
	GraphNode* next;
}GraphNode;

typedef struct Graph {
	GraphNode* adj;
}Graph;

int V, E, P;
bool isCan = false;
vector<pair<int, int>> arr[5003];
priority_queue<pair<int, int>, vector<pair<int, int>>> pq;

void Init_Graph(Graph* gph, int count) {
	gph->adj = (GraphNode*)malloc(sizeof(GraphNode) * (count + 1));
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
	pq.push({ 0, 1 });
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int node = pq.top().second;
		pq.pop();

		GraphNode* head = gph->adj[node].next;
		while (head) {
			if (head->cost + cost <= dist[head->dest]) {
				if (!arr[head->dest].empty()) {
					if (arr[head->dest].back().first > head->cost + cost) arr[head->dest].pop_back();
					arr[head->dest].push_back({ head->cost + cost, node });
				}
				else arr[head->dest].push_back({ head->cost + cost, node });
				dist[head->dest] = head->cost + cost;
				pq.push({ -(head->cost + cost), head->dest });
			}
			head = head->next;
		}
	}
}

void Back_tracking(int node) {
	if (node == 1) return;
	if (node == P) isCan = true;
	for (auto a : arr[node]) {
		Back_tracking(a.second);
	}
}

int main() {
	fastio;
	Graph graph;
	cin >> V >> E >> P;
	if (V == P || P == 1) isCan = true;
	Init_Graph(&graph, V);
	for (int i = 0; i < E; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		AddUnDirectedLinked(&graph, from, to, cost);
	}
	vector<int> dist(V + 1, INF);
	Dijkstra(&graph, dist);
	Back_tracking(V);

	if (isCan) cout << "SAVE HIM" << endl;
	else cout << "GOOD BYE" << endl;

	return 0;
}