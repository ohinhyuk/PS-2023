#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    
    int M;

    cin >> M;

    // int bags[M];
    vector<int> bags;

    int temp;

    while(1){
        cin >> temp;
        if(temp <= M) bags.push_back(temp);

        if(temp >= M) break;
    }    

    // for(int i = 0 ; i < M ; ++i){
    //     cin >> bags[i];
    // }    

    sort(bags.begin() , bags.end());

    int start = 0;
    int end = bags.size()-1;

    int answer = 0;

    while(start <= end){
        if(bags[start] + bags[end] <= bags.size()){
            start++;
            end--;   
        }else{
            end--;   
        }
        answer ++;
    }

    cout << answer;

    return 0;
}