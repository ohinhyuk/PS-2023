#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;



int main() {
    int n , k , f , from , to;

    cin >> n >> k >> f;

    vector<int> adj_list[n];
    vector<int> length;
    vector<bool> isVisited;
    int answer = 0;
    bool done = false;
    queue<int> invalid;


    
    /**
     * @brief 인접 리스트 만들기
     * @timeComplexity O(n^2)
     */

    for(int i = 0 ; i < f ; ++i){
        cin >> from >> to;
        adj_list[from-1].push_back(to);
        adj_list[to-1].push_back(from);
    }

    /**
     * @brief 인접 리스트 확인하기
     * 
     */

    // for(int i = 0 ; i < f ;++i){
    //     for(int j = 0 ; j < adj_list[i].size(); ++j){
    //         cout << adj_list[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    /**
     * @brief 
     *  각 인접 리스트의 길이와 방문했는지 여부 만들기
     *  @timeComplexity O(n)
     */

        for(int i = 0 ; i < n ; ++i){
            length.push_back(adj_list[i].size());
            isVisited.push_back(false);
        }

    /**
     * @brief 적합 하지 않은 것 찾기
     * @timeComplexity O(n^2)
     */


    while(!done){
        
        done = true;

        /**
         * @brief 친구가 k보다 적은 사람들은 제거 한다.
         * 제거 한 뒤 큐 담는다.
         */

        for(int i = 0 ; i < n ; ++i){
            if(length[i] < k && !isVisited[i]){
                invalid.push(i);
                isVisited[i] = true;
                done = false;
            }  
        }

        /**
         * @brief 큐에서 꺼내면서 해당 인접리스트 속을 탐색하면서 length를 하나씩 줄여나간다.
         */

        while(!invalid.empty()){

            int targetIdx = invalid.front();

             for(int j = 0 ; j < adj_list[targetIdx].size(); ++j){
                length[adj_list[targetIdx][j]-1]--;
             }
             invalid.pop();
        }
    }

    /**
     * @brief 걸러지지 않은 사람들의 숫자를 출력한다.
     * @timeComplexity O(n)
     */

    for(int i = 0 ; i < n ; ++i){
        if(!isVisited[i]) answer++;
    }

    cout << answer;
    

    return 0;
}