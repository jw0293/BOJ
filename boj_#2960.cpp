#include <algorithm>
#include <iostream>
#include <numeric>
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
#define ll long long	
#define ull unsigned long long
#define INF 987654321
#define Mod 1000000003
#define endl '\n'
#define ENDL cout << endl

using namespace std;

int N, K;
int num[1000 + 1];

void input() {
	cin >> N >> K;
}

void init() {
	for (int i = 1; i <= N; i++) {
		num[i] = i;
	}
}

int savePrime() {
	int count = 0;
	for (int i = 2; i <= N; i++) {
		for (int j = i; j <= N; j += i) {
			if (!num[j]) continue;

			count++;
			num[j] = 0;
			if (count == K) return j;
		}
	}
}

int solution() {
	init();
	return savePrime();
}

int main() {
	fastio;
	input();
	cout << solution() << endl;

	return 0;
}