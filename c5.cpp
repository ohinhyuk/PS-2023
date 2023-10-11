#include <iostream>
#include <vector>

using namespace std;

/**

문제 분석

ski trial의 가장 큰 난이도를 찾아라 ->
모든 sequence of cell들의 가장 앞과 끝의 차이 중 가장 큰 차이를 찾아라 ->
sequence of cell의 가장 앞 (floor_alt) 과 가장 끝(alt)을 구하고 그 차이들을 비교하며 구한다.

조건 1 : 인접해 있는 셀로 sequence of cells을 만들 수 있다.
조건 2 :  si 는 si+1 보다 커야 한다.
-> sequence of cell은 상하좌우로 이어진 셀들을 구성할 수 있으며 내림차순이어야 한다.
 
해결 방법

1) alt , floor_alt를 n*n 입력 값으로 초기화 한다.
2) 산의 모든 지점 (n*n)을 순회하면서 고도를 계산한다.
- 1. 방문했었는 지 확인한다.
- 2. 방문한 적이 없었으면 그 지점의 상하좌우로 이동할 수 있는 지 조건을 확인한다.
    2-1 조건 1 : 상하좌우 지점이 각각 유효한지
    2-2 조건 2 : 상하좌우 지점이 고도가 더 높은 지
    2-3 조건 3 : 상하좌우 지점의 floor_alt가 더 낮은 지
- 3. 상하좌우 중 조건이 모두 충족하는 것들은 옮겨갈 지점의 floor_alt를 현재 지점의 floor_alt로 업데이트 시켜준다.
- 4. 2-3 과정을 옮겨간 곳에서도 진행 한다.
3) 계산된 floor_alt와 alt의 차이를 통해 가장 큰 고도의 차이 구해서 출력한다.

시간 복잡도 
input 산의 가로, 세로 길이 n

O(n^2) + O((4n)^2) + O(n^2) =
O(n^2) + O(16n^2) + O(n^2) =
O(n^2)

 */



int n ; //산의 가로 , 세로 길이
vector<vector<int> >alt; // 산의 해당 좌표에서의 고도
vector<vector<int> >floor_alt; // 해당 좌표에서 올라온 지점 중 가장 낮은 고도

/**
 * @brief 해당 좌표의 상하좌우에서 올라갈 수 있는 곳으로 올라가는 함수
 */
void DFS(int i , int j){

    //좌
    if(i-1 >= 0 && alt[i][j] < alt[i-1][j] && floor_alt[i][j] < floor_alt[i-1][j]){
        floor_alt[i-1][j] = floor_alt[i][j];
        DFS(i-1 , j);
    } 
    
    //우
    if(i+1 < n  && alt[i][j] < alt[i+1][j] && floor_alt[i][j] < floor_alt[i+1][j]){
        floor_alt[i+1][j] = floor_alt[i][j];
        DFS(i+1 , j);
    } 
    
    //상
    if(j-1 >=0  && alt[i][j] < alt[i][j-1] && floor_alt[i][j] < floor_alt[i][j-1]){
        floor_alt[i][j-1] = floor_alt[i][j];
        DFS(i,j-1);
    } 

    //하
    if(j+1 < n  && alt[i][j] < alt[i][j+1] && floor_alt[i][j] < floor_alt[i][j+1]){
        floor_alt[i][j+1] = floor_alt[i][j];
        DFS(i , j+1);
    }
}

int main() {


    cin >> n;

    // alt 벡터 n*n 메모리 할당
    alt.resize(n);
    for (int i = 0; i < n; ++i) {
        alt[i].resize(n);
    }

    // floor_alt 벡터 n*n 메모리 할당
    floor_alt.resize(n);
    for (int i = 0; i < n; ++i) {
        floor_alt[i].resize(n);
    }

    // alt , floor_alt 값 할당
    for(int i =0 ; i < n ; ++i){
        for(int j = 0 ; j < n ; ++j){
            cin >> alt[i][j];
            floor_alt[i][j] = alt[i][j];
        }
    }

    // 산을 순회하면서 올라온 고도 계산
    for(int i = 0 ; i < n ; ++i){
        for(int j = 0 ; j < n ; ++j){
            
            // 올라온 적이 없는 산은 올라오지 않음
            if(floor_alt[i][j] == alt[i][j]){
                DFS(i,j);
            }
        }
    }

    int maxAltDiff = 0;

     for(int i =0 ; i < n ; ++i){
        for(int j = 0 ; j < n ; ++j){
            maxAltDiff = max(alt[i][j] - floor_alt[i][j], maxAltDiff);
        }
    }

    cout << maxAltDiff;

    return 0;
}