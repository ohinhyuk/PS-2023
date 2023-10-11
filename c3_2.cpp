#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<pair<int,int> > applicants;

int root[8001];

int find(int num){

    if(root[num]==num) return num;

    return find(root[num]);
}

void union_(int a , int b){

    
    a = find(a);
    b = find(b);

    if( a < b){
        root[b] = a; 
    } else{
        root[a] = b; 
    }

}

int main() {
    
    int N;
    int answer = 0;

    cin >> N;

    int x , y;

    for(int i = 1 ; i < 8001 ; ++i){
        root[i] = i;
    }

    for(int i = 0 ; i < N ; ++i){
        cin >> x >> y;
        applicants.push_back(make_pair(x,y));
    }
    vector<int> adj_list[N+1];


    for(int i = 1 ; i <= N ; ++i){
        for(int j = i+1 ; j <= N ; ++j){
            if((applicants[i-1].second > applicants[j-1].second && applicants[i-1].first < applicants[j-1].first) || (applicants[i-1].second < applicants[j-1].second && applicants[i-1].first > applicants[j-1].first)) {
                adj_list[i].push_back(j);
                adj_list[j].push_back(i);
            }
        }
    }

    // for(auto e : s) cout << e << ' ';
    //     for(int i = 1 ; i <= N ; ++i){
    //         for(int j = 0 ; j < adj_list[i].size(); ++j){
    //             cout << adj_list[i][j] << ' ';
    //         }
    //     cout << endl;
    // }

    for(int i = 1;  i <= N ; ++i){
        for(int j = 0 ; j < adj_list[i].size(); ++j){
            union_(i,adj_list[i][j]);
        }
    }
    set<int> s;

    for(int i = 1 ; i <= N ; ++i){
        s.insert(root[i]);
    }
    

    cout << s.size();
    

    return 0;
}