#include <iostream>
#include <vector>

using namespace std;

vector<pair<int,int> > applicants;

bool isGroup(int i , int j){

    if(applicants[i].second > applicants[j].second && applicants[i].first < applicants[j].first) return true;
    else if(applicants[i].second < applicants[j].second && applicants[i].first > applicants[j].first) return true;

    return false;
}

int main() {
    
    int N;
    int answer = 0;

    cin >> N;

    int x , y;


    for(int i = 0 ; i < N ; ++i){
        cin >> x >> y;
        applicants.push_back(make_pair(x,y));
    }

    for(int i = 0; i < N-1 ; ++i){
        for(int j = i + 1 ; j < N ; ++j){
            if(isGroup(i,j)) answer++;
        }
    }

    cout << answer;
    

    return 0;
}