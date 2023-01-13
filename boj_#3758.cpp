#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 123456789
#define endl '\n'

using namespace std;

typedef long long ll;
typedef struct Information{
	int teamNumber;
	int score;
	int submitCnt;
	int submitTime;
}Information;

int teamProblemScore[100 + 1][100 + 1];
int submitCount[100 + 1];
int resultScore[100 + 1];
int submitTime[100 + 1];

bool cmp(Information lhs, Information rhs){
	if(lhs.score == rhs.score){
		if(lhs.submitCnt == rhs.submitCnt){
			return lhs.submitTime < rhs.submitTime;
		} else{
			return lhs.submitCnt < rhs.submitCnt;
		}
	} else{
		return lhs.score > rhs.score;
	}
}

void initArray(){
	memset(teamProblemScore, 0, sizeof(teamProblemScore));
	memset(submitCount, 0, sizeof(submitCount));
	memset(resultScore, 0, sizeof(resultScore));
	memset(submitTime, 0, sizeof(submitTime));
}

vector<Information> getInformationOfTeam(int n){
	vector<Information> info;
	for(int i=1;i<=n;i++){
			Information infors;
			infors.teamNumber = i;
			infors.score = resultScore[i];
			infors.submitCnt = submitCount[i];
			infors.submitTime = submitTime[i];

			info.push_back(infors);
	}
	return info;
}

void addInitScore(int teamID, int problemNumber, int score){
	teamProblemScore[teamID][problemNumber] = score;
	resultScore[teamID] += score;
}

void updateScore(int teamID, int problemNumber, int score){
	resultScore[teamID] -= teamProblemScore[teamID][problemNumber];
	teamProblemScore[teamID][problemNumber] = score;
	resultScore[teamID] += teamProblemScore[teamID][problemNumber];
}

void findTeamRank(vector<Information> &info, int teamID){
	for(int i=0;i<info.size();i++){
		if(info[i].teamNumber == teamID){
			cout << i+1 << endl;
			return;
		}
	}
}

void inputInformation(int log, int id){
	for(int i=1;i<=log;i++){
		int teamID, problemNumber, score;
		cin >> teamID >> problemNumber >> score;

		submitCount[teamID]++;			
		if(teamProblemScore[teamID][problemNumber] == 0){
			addInitScore(teamID, problemNumber, score);
		} else{
			if(teamProblemScore[teamID][problemNumber] < score){
				updateScore(teamID, problemNumber, score);
			}
		}
		submitTime[teamID] = max(submitTime[teamID], i);
	}
}

void solution(){
	int testCase;
	cin >> testCase;
	while(testCase--){
		initArray();
		int n, k, id, log;
		cin >> n >> k >> id >> log;

		inputInformation(log, id);
		vector<Information> info = getInformationOfTeam(n);
		sort(info.begin(), info.end(), cmp);	
		
		findTeamRank(info, id);
	}
}

int main() {
	fastio;
	solution();
	
	return 0;
}