#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<pair<int ,int > > applicants;


bool isGroup(int i , int j){

    if(applicants[i].first < applicants[j].first && applicants[i].second > applicants[j].second) return true;
    else if(applicants[i].first > applicants[j].first && applicants[i].second < applicants[j].second) return true;

    return false;
}

int main() {
    
    int N;
    int x , y;
    cin >> N;

    vector<int> group;
    set<int> groupNum;


    for(int i = 0 ; i < N ; ++i){
        cin >> x >> y;
        applicants.push_back(make_pair(x,y));
        group.push_back(i+1);
    }

    for(int i = 0 ; i < N-1 ; ++i){
        for(int j = i+1 ; j < N ; ++j){
            if(isGroup(i,j)){
                if(group[i] < group[j]){
                    group[i] = group[j];
                }
            }
        }
    }

    for(int i = 0 ; i < N ; ++i){
        cout << group[i] << ' ';
        groupNum.insert(group[i]);
    }

    cout << groupNum.size();

    return 0;
}