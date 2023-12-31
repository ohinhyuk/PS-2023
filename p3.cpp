#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    
    int M;

    cin >> M;

    vector<int> bags;

    int temp;

    while(1){
        cin >> temp;

        bags.push_back(temp);
        if(cin.eof() == 1) break;
    }

    sort(bags.begin() , bags.end());

    int start = 0;
    int end = bags.size()-1;

    int answer = 0;

    while(start <= end){
        if(bags[start] + bags[end] <= M){
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