#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>

using namespace std;


int M,N;

vector<vector<int> > alpha;
vector<vector<int> > beta;


void BFS(vector<int> adj_list[], int target, vector<int> path , string type ,vector<bool> isVisited){
    queue<int> q;

    q.push(target);

    while(!q.empty()){
        target = q.front();
        
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

    // 마지막 도시 도착
    if(target == N){
        if(type == "alpha") alpha.push_back(path);
        else if(type == "beta") beta.push_back(path);
        return;
    }

    // 완전 탐색
    for(int i = 0 ; i < adj_list[target-1].size(); ++i){
        if(!isVisited[adj_list[target-1][i]-1]){
            
            DFS(adj_list, adj_list[target-1][i] , path, type, isVisited);
        }
        
    } 
}


/**
 * @brief 알파 베타의 각각의 경로를 통해 가장 적은 연료 사용량을 구한다.
 * @details 겹치는 구간이 있는 지 확인하고 연료 사용량을 구한다.
 * 
 * @param p 알파 연료 사용량
 * @param q 베타 연료 사용량
 * @param r 함께 사용하는 연료량
 * @return long long int 정답
 */
long long int cal_min_fuel(int p , int q , int r){
    
    long long int answer = 999999;

    /**
     * @brief 안 겹칠 때
     * 
     */

    for(int i = 0 ; i < alpha.size() ; ++i){
        for(int j = 0 ; j < beta.size(); ++j){

            // // 경로 겹치는 지 확인
            // long long int tempAlpha = 0;

            // for(int i2 = 0 ; i2 < alpha[i].size()-1 ; ++i2){
            //     long long int tempBeta = 0;
                
            //     for(int j2 = 0 ; j2 < beta[j].size()-1 ; ++j2){
                    
            //         // 경로가 겹쳤을 때
            //         if(alpha[i][i2] == beta[j][j2]){
            //             answer = min( answer , static_cast<long long int>(tempAlpha + tempBeta + min((alpha[i].size()- i2-1) , (beta[j].size()-j2-1)) * r));
            //             break;
            //         }
            //         tempBeta += q;
            //     }
            //     tempAlpha += p;
            // }


            // // 경로가 겹치지 않았을 때
            // answer = min(answer, static_cast<long long int>(alpha[i].size() * p + beta[j].size() * q));

            map<int ,int> checkTwo;
            vector<int> twoElement;
            for(int i2 = 0 ; i2 < alpha[i].size()-1 ; ++i2){
                checkTwo[alpha[i][i2]]++;
            }

            for(int j2 = 0 ; j2 < beta[j].size() -1 ; ++j2){
                checkTwo[beta[j][j2]]++;
            }

            for(auto pair : checkTwo){
                if(pair.second == 2){
                    twoElement.push_back(pair.first);
                }
            }

            if(twoElement.size() == 0){
                answer = min(answer, static_cast<long long int>(alpha[i].size() * p + beta[j].size() * q));
            } else{
                for(int meetX : twoElement){
                    long long int tempMin = 0;
                    int i2;
                    int j2;

                    for(i2 = 0 ; i2< alpha[i].size()-1 ; ++i2){
                        if( alpha[i][i2] == meetX){
                            tempMin += i2 * p;
                            break;
                        } 
                    }
                    for(j2 = 0 ; j2< beta[j].size()-1 ; ++j2){
                        if( beta[j][j2] == meetX){
                            tempMin += j2 * q;
                            break;
                        } 
                    }

                    tempMin += min(alpha[i].size() - i2-1 , beta[j].size() - j2-1) * r;
                    
                    answer = min(answer , tempMin);
                }
            }
        }
    }

    return answer;
}

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

    int p , q ,r , left , right;
    

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

    for(int i = 0 ; i < N ; ++i){
        for(int j = 0 ; j < adj_list[i].size() ; ++j) cout << adj_list[i][j] << ' ';

        cout << endl;
    }

    
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
    DFS(adj_list , 2 ,path,"beta" , isVisited);


    /**
     * @brief 경로 확인
     * 
     */

    // cout << "----alpha----" << endl;

    // for(int i = 0 ; i < alpha.size() ; ++i){
    //     for(int j = 0 ; j < alpha[i].size(); ++j){
    //         cout << alpha[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    // cout << "----beta----" << endl;

    //  for(int i = 0 ; i < beta.size() ; ++i){
    //     for(int j = 0 ; j < beta[i].size(); ++j){
    //         cout << beta[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    /**
     * @brief 두 경로를 통해서 가장 적은 연료를 사용하는 것을 구한다.
     * 
     */
    cout << cal_min_fuel(p,q,r);


    return 0;
}