#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int M,N;

vector<vector<int> > alpha;
vector<vector<int> > beta;

void DFS(vector<int> adj_list[], int target, vector<int> path , string type){
    
    path.push_back(target);

    if(target == N){
        if(type == "alpha") alpha.push_back(path);
        else if(type == "beta") beta.push_back(path);
        return;
    }

    for(int i = 0 ; i < adj_list[target-1].size(); ++i) DFS(adj_list, adj_list[target-1][i] , path, type);
}



long long int cal_min_fuel(int p , int q , int r){
    
    long long int answer = 999999;

    /**
     * @brief 안 겹칠 때
     * 
     */
    for(int i = 0 ; i < alpha.size() ; ++i){
        for(int j = 0 ; j < beta.size(); ++j){

            long long int tempAlpha = 0;

            for(int i2 = 0 ; i2 < alpha[i].size() ; ++i2){
                long long int tempBeta = 0;
                
                for(int j2 = 0 ; j2 < beta[j].size() ; ++j2){
                    
                    if(alpha[i][i2] == beta[j][j2]){
                        // cout << "min result" << tempAlpha << ' ' << tempBeta << ' ' << min((alpha[i].size()- i2) , (beta[j].size()-j2)) << endl; 
                        answer = min( answer , static_cast<long long int>(tempAlpha + tempBeta + min((alpha[i].size()- i2-1) , (beta[j].size()-j2-1)) * r));
                    }
                    tempBeta += q;
                }
                tempAlpha += p;
            }

            answer = min(answer, static_cast<long long int>(alpha[i].size() * p + beta[j].size() * q));
            // cout << "min result" << answer << endl;
        }
    }


    return answer;

}

int main() {
    
    /**
     * @brief 풀이 방법
     * 0) 인접리스트
     * 1) 알파의 모든 경우의 수 구한다.
     * 2) 베타의 모든 경우의 수 구한다.
     * 3) 양쪽의 각 경우의 수를 이중 포문으로 돌면서 계산한다.
     * 
     */

    /**
     * @brief 입력 받기
     * 
     */

    int p , q ,r , left , right;
    

    cin >> p >> q >> r >> N >> M;
    
    vector<int> adj_list[N];
    /**
     * @brief 인접리스트 만들기
     *  O(M)
     */

    for (int i = 0 ; i < M ; ++i){
       
       cin >> left >> right ;

       if(left > right) adj_list[right-1].push_back(left);
       else adj_list[left-1].push_back(right);
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
 * @brief 알파의 모든 경우의 수 구하기
 * 
 */
    DFS(adj_list , 1 ,path,"alpha");

    /**
     * @brief 베타의 모든 경우의 수 구하기
     * 
     */
    DFS(adj_list , 2 ,path,"beta");


    cout << "----alpha----" << endl;

    for(int i = 0 ; i < alpha.size() ; ++i){
        for(int j = 0 ; j < alpha[i].size(); ++j){
            cout << alpha[i][j] << ' ';
        }
        cout << endl;
    }

    cout << "----beta----" << endl;

     for(int i = 0 ; i < beta.size() ; ++i){
        for(int j = 0 ; j < beta[i].size(); ++j){
            cout << beta[i][j] << ' ';
        }
        cout << endl;
    }

    
    cout << cal_min_fuel(p,q,r);


    return 0;
}