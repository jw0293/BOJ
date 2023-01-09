#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 123456789
#define endl '\n'

using namespace std;

int jumpA, jumpB, N, M;
int visited[100000 + 1];
const int dy[] = {-1, 1};

void input(){
	cin >> jumpA >> jumpB >> N >> M;
}

bool isValid(int pos){
	return (0 <= pos && pos <= 100000);
}

int solution(){
	memset(visited, INF, sizeof(visited));
	queue<pair<int, int>> q;
	q.push({N, 0});

	while(!q.empty()){
		int position = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if(position == M) {
			return cnt;
		}

		for(int i=0;i<2;i++){
			int next = position + dy[i];
			if(isValid(next) && cnt+1 < visited[next]){
				visited[next] = cnt+1;
				q.push({next, cnt+1});
			}

			int nextA = position + (dy[i] * jumpA);
			int nextB = position + (dy[i] * jumpB);

			if(isValid(nextA) && cnt+1 < visited[nextA]){
				visited[nextA] = cnt+1;
				q.push({nextA, cnt+1});
			}
			if(isValid(nextB) && cnt+1 < visited[nextB]){
				visited[nextB] = cnt+1;
				q.push({nextB, cnt+1});
			}
		}

		int nextA = position * jumpA;
		int nextB = position * jumpB;

		if(isValid(nextA) && cnt+1 < visited[nextA]){
				visited[nextA] = cnt+1;
				q.push({nextA, cnt+1});
		}
		if(isValid(nextB) && cnt+1 < visited[nextB]){
				visited[nextB] = cnt+1;
				q.push({nextB, cnt+1});
			}
	}
	return -1;
}

int main() {
	fastio;
	input();
	cout << solution() << endl;
	
	return 0;
}