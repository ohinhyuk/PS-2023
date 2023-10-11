#include <iostream>
#include <vector>
#include <set>
using namespace std;

#define MAX_SIZE 8001

struct Applicants{
	int x;
	int y;
}Applicants;

int main(){
	int N;
	cin >> N;
	set<int> s;

	struct Applicants applicants[N+1];

	for(int i=1; i<=N; i++){
		cin >> applicants[i].x >> applicants[i].y;
	}

	int interview_bool[MAX_SIZE] = {0};

	for(int i=1; i<=N; i++){
		interview_bool[i] = i;
	}

	for(int i=1; i<=N; i++){
		for(int j=i+1; j<=N; j++){
			if((applicants[i].x > applicants[j].x && applicants[i].y < applicants[j].y) ||
				(applicants[i].x < applicants[j].x && applicants[i].y > applicants[j].y)){
					int min = interview_bool[i];
					if(min > interview_bool[j]){
						min = interview_bool[j];
					}
					interview_bool[j] = min;
					interview_bool[i] = min;
				}
		}
	}

	for(int i=1; i<=N; i++){
		s.insert(interview_bool[i]);
	}

	cout << s.size() << endl;

	return 0;
}