#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int , long long int> &a,pair<int , long long int> &b ){

    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int main() {

    vector<pair<int , long long int> > v;
    
    long long int answer = 0;

    long long int x;
    int g , n , k;

    cin >> n >> k;

    for(int i = 0 ; i < n ; ++i){
        cin >> g >> x;
        v.push_back(make_pair(g,x));
    }

    

    sort(v.begin(), v.end() ,compare);

    /**
     * @brief check v
     * 
     */
    // for(auto p : v){
    //     cout << p.first <<p.second << endl;
    // }


    // for(pair<int , long long int> pair : v){
        
    // }
    

    for(int i = 0 ; i < n ; ++i){

        int j = i+1;

        long long int max = v[i].first;

        while(j < n && v[j].second <= (v[i].second + 2*k) ){
            max += v[j].first;
            j++;
        }

        if(max > answer) answer = max;

    }

    cout << answer;

    return 0;
}