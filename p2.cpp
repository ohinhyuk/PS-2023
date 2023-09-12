#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// heap (priority queue)으로 해볼 가치도 있을듯하다.

int main() {
    /**
     * @brief 해결 방법
     * 
     * 1) 입력 받기
     * 2) 차례로 탐색하면서 두 합이 가장 작은 것을 찾는다.
     * 3) 앞에꺼에 뒤에꺼 더하고 뒤에꺼를 pop한다.
     * 4) 끝날 때까지 한다.
     */

        int N ,input ;

        int answer = 0 ;

        cin >> N;

        vector<int> v;

    /**
     * @brief 1) 입력받기
     * 
     */
        for(int i = 0 ; i < N ; ++i){
            cin >> input;
            v.push_back(input);
        }   

    /**
     * @brief 2)탐색하여 두 합이 가장 작은 것을 찾는다.
     * 
     */

    while(v.size() > 1){
        int minSum = 1001;
        int minIdx = 0;

        for(int i = 0 ; i < v.size()-1 ; ++i){
            int tempSum = v[i] + v[i+1];
            if(minSum > tempSum){
                minSum = min(minSum, v[i] + v[i+1]);
                minIdx = i;
            }
        }
        
        answer += v[minIdx] + v[minIdx + 1];
        
        v[minIdx] += v[minIdx+1];
        
        v.erase(v.begin() + minIdx+1);
    }

    cout << answer;
    

    return 0;
}