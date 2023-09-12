#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool compare(pair<int , long long int> &a,pair<int , long long int> &b ){

    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int main() {

    vector<pair<int , long long int> > v;
    map<long long int , long long int> m;
    long long int answer = 0;

    long long int x, g;
    int n , k;

    cin >> n >> k;

    for(int i = 0 ; i < n ; ++i){
        cin >> g >> x;
        m.insert(make_pair(x,g));
        // v.push_back(make_pair(g,x));
    }

    

    // sort(v.begin(), v.end() ,compare);

    /**
     * @brief check v
     * 
     */
    // for(auto p : m){
    //     cout << p.first <<p.second << endl;
    // }


    // for(pair<int , long long int> pair : v){
        
    // }
    

    // for(int i = 0 ; i < n ; ++i){
    for(auto iter = m.begin() ; iter != m.end() ; ++iter){

        auto nextIter = next(iter);

        long long int max = iter->second;

       while(nextIter != m.end() && nextIter->first <= (iter->first + 2*k) ){
            max += nextIter->second;
            ++nextIter;  
        }
        if(max > answer) answer = max;

       if(iter->first + (2*k) >= std::prev(m.end())->first) break;
    }

    cout << answer;

    return 0;
}