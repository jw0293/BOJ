#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e18 + 3
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int MX = 200000 + 5;

int F, unused = 1;
int parent[MX];
int setSize[MX];
map<string, int> nameToNumber;

void init(){
	for(int i=0;i<=MX;i++){
		setSize[i] = 1;
		parent[i] = i;
	}

	unused = 1;
	nameToNumber.clear();
}

int getParent(int x){
	if(x == parent[x]) return x;
	return parent[x] = getParent(parent[x]);
}

int unIon(int n1, int n2){
	int pn1 = getParent(n1);
	int pn2 = getParent(n2);
	if(pn1 == pn2) return setSize[pn1];
	if(pn1 < pn2) {
		parent[pn2] = pn1;
		setSize[pn1] += setSize[pn2];
		setSize[pn2] = setSize[pn1];

		return setSize[pn1];
	}
	else {
		parent[pn1] = pn2;
		setSize[pn2] += setSize[pn1];
		setSize[pn1] = setSize[pn2];

		return setSize[pn2];
	}
}

void getNameNumber(string &name){
	if(nameToNumber.find(name) != nameToNumber.end()) return;
	nameToNumber[name] = unused++;
}

void input(){
	int testCase;
	cin >> testCase;
	while(testCase--){
		cin >> F;
		init();

		for(int i=0;i<F;i++){
			string n1, n2;
			cin >> n1 >> n2;

			if(n1 == n2){
				cout << setSize[nameToNumber[n1]] << endl;
				continue;
			}

			getNameNumber(n1);
			getNameNumber(n2);

			cout << unIon(nameToNumber[n1], nameToNumber[n2]) << endl;
		}
	}
}


int main(){
	fastio;
	input();

	return 0;
}
