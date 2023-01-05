#include <bits/stdc++.h>
#define Mod 12345678910
#define endl '\n'

int N;
long long s[2020 + 1][34 + 1];

void input(){
	scanf("%d", &N);
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			int rel; 
			scanf("%1d", &rel);
			if(rel) s[i][j/60] |= 1LL << (j % 60);
		}
	}
}

void solution(){
	int Q;
	scanf("%d", &Q);
	while(Q--){
		int a, b, cnt = 0;
		scanf("%d %d", &a, &b);
		for(int i=0;i<35;i++){
			cnt += __builtin_popcountll(s[a][i] & s[b][i]);
		}
		printf("%d\n", cnt);
	}
}
 
int main() {
	input();
	solution();
 
	return 0;
}