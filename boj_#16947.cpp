#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <bitset>
#define INF 987654321
#define Mod 9901
#define CUNLINK ios::sync_with_stdio(false),cin.tie(0), cout.tie(0)
#define ll long long
#define ENDL cout << endl
#define endl '\n'

using namespace std;
typedef struct GraphNode {
	int cost;
	int dest;
	GraphNode* next;
}GraphNode;

typedef struct Graph {
	int cnt;
	GraphNode* adj;
}Graph;

int N;
int visited[3001];
bool visited2[3001];
int dist[3001];
bool isEnd = false;

void Init_Graph(Graph* gph, int cnt) {
	gph->cnt = cnt;
	gph->adj = (GraphNode*)malloc(sizeof(GraphNode) * (cnt + 1));
	for (int i = 1; i <= cnt; i++) gph->adj[i].next = NULL;
}

int AddDirectedLinkedEdge(Graph* gph, int src, int dst, int cost) {
	GraphNode* Temp = (GraphNode*)malloc(sizeof(GraphNode));
	Temp->cost = cost;
	Temp->dest = dst;
	Temp->next = gph->adj[src].next;
	gph->adj[src].next = Temp;
	return 1;
}

int AddUnDirectedLinkedEdge(Graph* gph, int src, int dst, int cost) {
	return AddDirectedLinkedEdge(gph, src, dst, cost) && AddDirectedLinkedEdge(gph, dst, src, cost);
}

int isCyclePresentUnDirectedEdge(Graph* gph, int start, int index, int prev) {
	visited[index] = 1;
	GraphNode* head = gph->adj[index].next;
	while (head) {
		if (!visited[head->dest]) {
			if (isCyclePresentUnDirectedEdge(gph, start, head->dest, index))
				return 1;
		}
		else if (head->dest != prev && head->dest == start)
			return 1;
		head = head->next;
	}
	visited[index] = 2;
	return 0;
}

void DFS(Graph* gph, int Init, int index, int len) {
	visited2[index] = true;
	GraphNode* head = gph->adj[index].next;
	while (head) {
		if (!visited2[head->dest]) {
			if (dist[head->dest] == 0) {
				isEnd = true;
				dist[Init] = len + 1;
				return;
			}
			else {
				DFS(gph, Init, head->dest, len + 1);
				if (isEnd) break;
			}
		}
		head = head->next;
	}
}

int main() {
	CUNLINK;
	Graph graph;
	queue<int> q;
	cin >> N;
	Init_Graph(&graph, N);
	memset(dist, -1, sizeof(dist));
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		AddUnDirectedLinkedEdge(&graph, a, b, 1);
	}
	for (int i = 1; i <= N; i++) {
		memset(visited, false, sizeof(visited));
		if (!visited[i]) {
			if (isCyclePresentUnDirectedEdge(&graph, i, i, -1)) {
				dist[i] = 0;
			}
			else {
				q.push(i);
			}
		}
	}
	while (!q.empty()) {
		int y = q.front(); q.pop();
		isEnd = false;
		DFS(&graph, y, y, 0);
		memset(visited2, false, sizeof(visited2));
	}
	for (int i = 1; i <= N; i++)
		cout << dist[i] << " ";

	return 0;
}