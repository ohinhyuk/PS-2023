#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>

using namespace std;

int answer = 999999;
int M,N , p ,q ,r;

vector<vector<int> > alpha;
vector<vector<int> > beta;
vector<int> connectingList;
map<int ,int > m_dist;
map<int,int> m;
map<int , int> m_0;
set<int> s;

/**
 * @brief input
 * 
 * 
4 4 5 8 8
1 4
2 3
3 4
4 7
2 5
5 6
6 8
7 8
 * 
 */


void BFS_1 (vector<int> adj_list[]){
    int target = 1;
    vector<int> isVisited(N,false);
    queue<int> q;
    q.push(target);
    
    int distance = 0;
    
    while(!q.empty()){
        
        target = q.front();
        q.pop();
        for(int i = 0 ; i < adj_list[target-1].size(); ++i){
            if(!isVisited[adj_list[target-1][i]-1]){
                isVisited[adj_list[target-1][i]-1] = true;
                m_0[adj_list[target-1][i]] = distance + 1;
            }
        }

        distance++;

    }
}

void BFS_2 (vector<int> adj_list[]){
    int target = N;
    vector<int> isVisited(N,false);
    queue<int> q;
    q.push(target);
    
    int distance = 0;
    
   while(!q.empty()){
    int level_size = q.size();  // 현재 레벨의 노드 개수를 가져옴

    for(int j = 0; j < level_size; ++j) { // 현재 레벨의 모든 노드를 처리
        target = q.front();
        q.pop();

        for(int i = 0 ; i < adj_list[target-1].size(); ++i){
            if(!isVisited[adj_list[target-1][i]-1]){
                q.push(adj_list[target-1][i]);
                isVisited[adj_list[target-1][i]-1] = true;
                m_dist[adj_list[target-1][i]-1] = distance + 1;
            }
        }
    }

    distance++;
}



}

/**
 * @brief 경로 구하기
 * 
 * @param adj_list 인접 리스트
 * @param target 현재의 도시
 * @param path 여태까지 온 경로
 * @param type alpha 인지 beta인지 구분
 */

void DFS(vector<int> adj_list[], int target, vector<int> path , string type ,vector<bool> isVisited){
    isVisited[target-1] = true;

    path.push_back(target);

    if(type =="alpha" && target == N) return;
    // 마지막 도시 도착
    if(type =="alpha" && target == 2){
        // auto it = find(path.begin(), path.end(), N);

        //  if (it != path.end()) {
        // answer = min( int((it - path.begin()) * p + (path.end() - it) *q) , answer );
        // } else {

        //  alpha.push_back(path);

        for(int i = 0 ; i < path.size() ; ++i){
            int tempMin;
            if(m_0[path[i]] == 0) tempMin = int(p*i + q* (path.size()-1-i));
            else tempMin = min(m_0[path[i]], int(p*i + q* (path.size()-1-i)));

            // m_0.insert(make_pair(path[i],tempMin));
            m_0[path[i]] = tempMin;
            s.insert(path[i]);

        // } 
        }
       
        return;
    }
    if(type =="beta"){
        for(int elem : s){
            if(elem == target){
                if(m[elem] == 0) m[elem] = int(path.size()-1);
                else m[elem] = min(int(path.size()-1), m[elem]);
            }
        }
    }

    // 완전 탐색
    for(int i = 0 ; i < adj_list[target-1].size(); ++i){
        if(!isVisited[adj_list[target-1][i]-1]){
            
            DFS(adj_list, adj_list[target-1][i] , path, type, isVisited);
        }
        
    } 
}


// /**
//  * @brief 알파 베타의 각각의 경로를 통해 가장 적은 연료 사용량을 구한다.
//  * @details 겹치는 구간이 있는 지 확인하고 연료 사용량을 구한다.
//  * 
//  * @param p 알파 연료 사용량
//  * @param q 베타 연료 사용량
//  * @param r 함께 사용하는 연료량
//  * @return long long int 정답
//  */
// long long int cal_min_fuel(int p , int q , int r){

// // 따로 가는 것

//     long long int answer = 999999;

    

//     /**
//      * @brief 안 겹칠 때
//      * 
//      */

//     for(int i = 0 ; i < alpha.size() ; ++i){
//         for(int j = 0 ; j < beta.size(); ++j){

//         }
//     }

//     return answer;
// }

// 1) 1~2 까지의 모든 경로를 찾는다. ex) 1-5-3-7-2
// 2) N부터 역행 하면서 이중 가장 가까운 것을 찾는다.
// N ~ 가장 가까운 것 + 1 , 2 ~ 가장 가까운 것 으로 거리를 구한다.


int main() {
    
    /**
     * @brief 풀이 방법
     * 0) 인접리스트
     * 1) 알파의 모든 경로 구한다.
     * 2) 베타의 모든 경로 구한다.
     * 3) 양쪽의 각 경로를 이중 포문으로 돌면서 계산한다.
     * 
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
     * @brief 0)인접리스트 만들기
     *  O(M)
     */

    for (int i = 0 ; i < M ; ++i){
       
       cin >> left >> right ;

        adj_list[right-1].push_back(left);
        adj_list[left-1].push_back(right);

    //    if(left > right) adj_list[right-1].push_back(left);
    //    else adj_list[left-1].push_back(right);
    }
    

    /**
     * @brief 인접리스트 테스트
     *  
     */

    // for(int i = 0 ; i < N ; ++i){
    //     for(int j = 0 ; j < adj_list[i].size() ; ++j) cout << adj_list[i][j] << ' ';

    //     cout << endl;
    // }

    
    vector<int> path;

    /**
     * @brief 1) 알파의 모든 경로 구하기
     * 
     */
    DFS(adj_list , 1 ,path,"alpha" , isVisited);

    /**
     * @brief 베타의 모든 경로 구하기
     * 
     */
    // DFS(adj_list , N ,path,"beta" , isVisited);
    BFS_2(adj_list);


    /**
     * @brief 경로 확인
     * 
     */

//     cout << "----alpha----" << endl;

//     for(int i = 0 ; i < alpha.size() ; ++i){
//         for(int j = 0 ; j < alpha[i].size(); ++j){
//             cout << alpha[i][j] << ' ';
//         }
//         cout << endl;
//     }

//     cout << "----beta----" << endl;

//      for(int i = 0 ; i < beta.size() ; ++i){
//         for(int j = 0 ; j < beta[i].size(); ++j){
//             cout << beta[i][j] << ' ';
//         }
//         cout << endl;
//     }

// cout << "----set----" << endl;
//     for(int elem : s){
//         cout << elem <<  ' '; 
//     }
//     cout << endl;

// cout << "----map----" << endl;
//    for(pair<int,int> elem : m){
//         cout << elem.first <<  ' ' << elem.second << endl; 
//     }
//     cout << endl;

//     cout << "----map----" << endl;
//    for(pair<int,int> elem : m_0){
//         cout << elem.first <<  ' ' << elem.second << endl; 
//     }
//     cout << endl;

    /**
     * @brief 두 경로를 통해서 가장 적은 연료를 사용하는 것을 구한다.
     * 
     */

    // cout << cal_min_fuel(p,q,r);

    // for(pair<int,int> idx : m){
    //     answer = min(m[idx.first]*r + m_0[idx.first],answer);
    // }
    // answer = min( m[1]*p + m[2]*q , answer);

    // cout << answer;

    answer = m_dist[1] * p + m_dist[2] * q;
    // cout << m_dist[1] << m_dist[2] << answer << endl;

    for(int idx : s){
        answer = min(m_dist[idx] * r + m_0[idx] , answer);
    }

    cout << answer;

    return 0;
}