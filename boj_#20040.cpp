#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <climits>
#include <set>
#include <map> 
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ENDL cout << endl
#define ll long long	
#define ull unsigned long long
#define INF 987654321
#define Mod 1000000
#define endl '\n'
#define pil pair<int,int>

using namespace std;

int N, M;
int parent[500000 + 1];

void init(int n) {
	for (int i = 0; i < n; i++) {
		parent[i] = i;
	}
}

int getParent(int x) {
	if (x == parent[x]) return x;
	return parent[x] = getParent(parent[x]);
}

void unionNode(int x, int y) {
	x = getParent(x);
	y = getParent(y);

	if (x > y) parent[x] = y;
	else parent[y] = x;
}

bool isSame(int x, int y) {
	if (getParent(x) == getParent(y)) return true;
	return false;
}

int input() {
	cin >> N >> M;
	init(N);
	for (int i = 1; i <= M; i++) {
		int node1, node2;
		cin >> node1 >> node2;
		if (isSame(node1, node2)) return i;
		unionNode(node1, node2);
	}
	return 0;
}

int main() {
	fastio;
	cout << input() << endl;	

	return 0;
}