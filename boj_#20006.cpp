#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 123456789
#define endl '\n'

using namespace std;

typedef long long ll;
typedef struct Member{
	int level;
	string name;
}Member;

typedef struct Information{
	int minRank;
	int maxRank;
	int seq;
	int cnt;
	vector<Member> members;
}Information;

int P, M;
vector<Information> rooms;

bool cmp(Information lhs, Information rhs){
	return lhs.seq < rhs.seq;
}

bool madeRoomSorting(Information lhs, Information rhs){
	return lhs.seq < rhs.seq;
}

bool nameSorting(Member lhs, Member rhs){
	return lhs.name < rhs.name;
}

void mediateRank(Member& member, Information& cur){
	if(member.level - 10 < 0) cur.minRank = 0;
	else cur.minRank = member.level - 10;

	if(member.level + 10 > 500) cur.maxRank = 500;
	else cur.maxRank = member.level + 10;
}

void parInOrCreateRoom(Member& member, Information &cur){
	bool isPartIn = false;
	sort(rooms.begin(), rooms.end() ,cmp);
	for(auto &pr : rooms){
		if(pr.cnt >= M) continue;
		if((pr.minRank <= member.level && member.level <= pr.maxRank)){
			pr.cnt++;
			isPartIn = true;
			pr.members.push_back(member);
			break;
		}
	}

	if(!isPartIn){
		cur.cnt = 1;
		cur.members.push_back(member);
		rooms.push_back(cur);
	}
}

void input(){
	cin >> P >> M;

	int sequence = 1;
	for(int i=0;i<P;i++){
		Member member;
		cin >> member.level >> member.name;

		Information cur;
		mediateRank(member, cur);
		cur.seq = sequence++;
	
		parInOrCreateRoom(member, cur);	
	}
}

void printRoomStatus(Information info){
	if(info.cnt == M) cout << "Started!" << endl;
	else cout << "Waiting!" << endl;
}

void solution(){
	sort(rooms.begin(), rooms.end(), madeRoomSorting);
	for(auto &t : rooms){
		sort(t.members.begin(), t.members.end(), nameSorting);
		for(auto &member : t.members){
			cout << member.level << " " << member.name << endl;
		}
	}
}

int main() {
	fastio;
	input();
	solution();
	
	return 0;
}