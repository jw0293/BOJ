#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <set>
#include <map> 
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ENDL cout << endl
#define ll long long	
#define ull unsigned long long
#define INF 987654321
#define Mod 100000
#define endl '\n'
#define pil pair<int,int>

using namespace std;

int n1, n2, v1, v2;

void input() {
	cin >> n1 >> n2 >> v1 >> v2;
}

void solution() {
	int down = n2 * v2;
	int up = (n1 * v2) + (n2 * v1);

	int std = down > up ? up : down;
	int index = 2;
	while (1) {
		std = down > up ? up : down;
		if (index > std) break;

		if (down % index == 0 && up % index == 0) {
			up /= index;
			down /= index;
			index = 2;
		}
		else {
			index++;
		}
	}
	cout << up << " " << down << endl;
}

int main() {
	fastio;
	input();
	solution();

	return 0;
}