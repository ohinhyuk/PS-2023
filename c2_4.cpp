#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>

using namespace std;

int M,N , p ,q ,r;

map<int,int> BFS (vector<int> adj_list[], int target){

    map<int,int > m;
    vector<int> isVisited(N,false);
    queue<int> q;

    q.push(target);
    
    int distance = 0;
    
   while(!q.empty()){
    int level_size = q.size();  

    for(int j = 0; j < level_size; ++j) {
        target = q.front();
        q.pop();

        for(int i = 0 ; i < adj_list[target-1].size(); ++i){
            
            if(!isVisited[adj_list[target-1][i]-1]){
                q.push(adj_list[target-1][i]);
                isVisited[adj_list[target-1][i]-1] = true;
                m[adj_list[target-1][i]] = distance + 1;
            }
        }
    }

    distance++;
}

return m;

}

int main() {
    
    /**
     * @brief 풀이 방법
     * 1) 인접리스트를 만든다.
     * 2) 알파 열차 -> 다른 모든 장소의 거리를 구한다.
     * 3) 베타 열차 -> 다른 모든 장소의 거리를 구한다.
     * 4) 목적지 -> 다른 모든 장소의 거리를 구한다.
     * 5) 모든 장소를 탐색하며 (알파 -> 장소) + (베타 -> 장소) + (목적지 -> 장소) 에 사용되는 연료를 구하고 최소 값을 찾는다.
     */

    /**
     * @brief 입력 받기
     * 
     */

    int left , right;
    

    cin >> p >> q >> r >> N >> M;
    
    vector<int> adj_list[N];
    vector<bool> isVisited(N, false);

    /**
     * @brief 1)인접리스트 만들기
     *  O(M)
     */

    for (int i = 0 ; i < M ; ++i){
       
       cin >> left >> right ;

        adj_list[right-1].push_back(left);
        adj_list[left-1].push_back(right);

    }
    


    /**
     * @brief 2) 알파 열차 -> 다른 모든 장소의 거리를 구한다.
     * O(N)
     */

    map<int,int> m1 = BFS(adj_list , 1);
    m1[1] = 0;

    /**
     * @brief 3) 베타 열차 -> 다른 모든 장소의 거리를 구한다.
     * 
     */
    map<int,int> m2 = BFS(adj_list , 2);
    m2[2] = 0;

    /**
     * @brief 4) 목적지 -> 다른 모든 장소의 거리를 구한다.
     * 
     */

    map<int,int> mN = BFS(adj_list , N);
    mN[N] = 0;

    
    /**
     * @brief 5) 모든 장소를 탐색하며 (알파 -> 장소) + (베타 -> 장소) + (목적지 -> 장소) 에 사용되는 연료를 구하고 최소 값을 찾는다.
     * O(N)
     */

    int answer = mN[1] * p + mN[2] * q;
    answer = min(m2[1] * q + mN[1] * r , answer);
    answer = min(m1[2] * p + mN[2] * r , answer);


    for(int i = 0 ; i < N-1 ; ++i){
        if(m1[i+1] && m2[i+1] && mN[i+1]) answer = min(m1[i+1] * p + m2[i+1] * q + mN[i+1] * r, answer);
    }

    cout << answer;

    return 0;
}