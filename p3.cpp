#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    
    int M;

    cin >> M;

    int bags[M];

    for(int i = 0 ; i < M ; ++i){
        cin >> bags[i];
    }    

    sort(bags , bags + M);

    int start = 0;
    int end = M-1;

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