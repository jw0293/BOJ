#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define Mod 12345678910
#define endl '\n'

using namespace std;

int A, B;
string bitA, bitB;

void input(){
	cin >> bitA >> bitB;
}

void solution(){
	// AND
	for(int i=0;i<bitA.size();i++){
		if(bitA[i] == '1' && bitB[i] == '1') cout << '1';
		else cout << '0';
	}
	cout << endl;

	// OR
	for(int i=0;i<bitA.size();i++){
		if(bitA[i] == '1' || bitB[i] == '1') cout << '1';
		else cout << '0';
	}
	cout << endl;

	// XOR
	for(int i=0;i<bitA.size();i++){
		if(bitA[i] != bitB[i]) cout << '1';
		else cout << '0';
	}
	cout << endl;

	// NOT A
	for(int i=0;i<bitA.size();i++){
		if(bitA[i] == '0') cout << '1';
		else cout << '0';
	}
	cout << endl;

	// NOT B
	for(int i=0;i<bitA.size();i++){
		if(bitB[i] == '0') cout << '1';
		else cout << '0';
	}
	cout << endl;
}
 
int main() {
	fastio;
	input();
	solution();
 
	return 0;
}