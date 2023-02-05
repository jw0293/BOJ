#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e9+3
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
int N, M, K;
int A[100 + 1][100 + 1];
int B[100 + 1][100 + 1];
int X[100 + 1][100 + 1];

void input(){
	cin >> N >> M;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cin >> A[i][j];
		}
	}

	cin >> M >> K;
	for(int i=0;i<M;i++){
		for(int j=0;j<K;j++){
			cin >> B[i][j];
		}
	}
}

void solution(){
	int val;
	for(int i=0;i<N;i++){
		for(int j=0;j<K;j++){
			val = 0;
			for(int k=0;k<M;k++){
				val += A[i][k] * B[k][j];
			}
			X[i][j] = val;
		}
	}

	for(int i=0;i<N;i++){
		for(int j=0;j<K;j++){
			cout << X[i][j] << " ";
		}
		cout << endl;
	}
}

int main(){
	fastio;
	input();
	solution();

	return 0;
}