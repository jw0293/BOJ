#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e6 + 3
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

string preOrder, inOrder;

string slicing(string str, int a, int b){
	string temp ="";
	for(int i=a;i<b;i++) temp += str[i];
	return temp;
}

void printPostOrder(string pre, string in){
	const int N = pre.size();
	if(pre.empty()) return;
	const char root = pre[0];
	const int L = find(in.begin(), in.end(), root) - in.begin();
	const int R = N - 1 - L;
	printPostOrder(slicing(pre, 1, L+1), slicing(in, 0, L));
	printPostOrder(slicing(pre, L+1, N), slicing(in, L+1, N));
	cout << root;
}

void input(){
	while(1){
		cin >> preOrder >> inOrder;
		if(cin.eof()) break;
		printPostOrder(preOrder, inOrder);
		cout << endl;
	}
}

int main(){
	fastio;
	input();

	return 0;
}