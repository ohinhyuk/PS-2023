/**
 *
 * Disjoint Set : (공통 원소가 없는) 서로소 집합 자료 구조
 * union (x,y) x가 속한 집합과 y가 속한 집합을 합친다.
 * find(x) x가 속한 집합의 대표값 (루트 노드)를 반환한다.
 * 
 * 적용
 * 
 * 조건을 만족하는 그룹들은 하나의 그룹으로 합친다.
 * 다 합치고 나면 조건을 만족하지 않는 집합들의 서로소 집합 자료 구조가 나타난다.
 * 
 * 
 * 
 * 
 */

#include <iostream>
#include <vector>
#include <set>

using namespace std;


vector<pair<int, int> > applicants; // 지원자수
int root[8001]; // 집합의 대푯 값
    int N;

/**
 * @brief 집합의 대표 값 ( 루트 노드 )를 찾아서 반환한다.
 * 
 */
int find(int x) {
    if (root[x] == x) return x;
    return find(root[x]);
}

/**
 * @brief x가 속한 집합과 y가 속한 집합을 합친다.
 * 
 */

void union_(int x, int y) {
    x = find(x);
    y = find(y);
    if(x < y) root[y] = x;
    else root[x] = y;

    // cout << "union" << endl;
    // cout << init_x << ' ' << init_y << endl;
    // cout << x << ' ' << y << endl;
    // for(int i = 0 ; i < N ;++i){
    //     cout << root[i] << ' ';
    // }
    // cout << "root" << endl;
}

/**
 * @brief 두 사람이 조건을 성립하는 지 확인하는 함수
 * 
 */
bool isGroup(int i, int j) {
    if (applicants[i].first < applicants[j].first && applicants[i].second > applicants[j].second) return true;
    else if (applicants[i].first > applicants[j].first && applicants[i].second < applicants[j].second) return true;

    return false;
}

int main() {
    
    int x, y;

    cin >> N;
   
    // 지원자들의 점수 입력
    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        applicants.push_back(make_pair(x, y));
    }

    // 집합의 대표 값을 자기 자신으로 초기화
    for (int i = 0; i <= N; i++) {
        root[i] = i; 
    }

    // 모든 참여자들의 두 사람의 조건을 비교
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (isGroup(i, j)) {
                union_(i, j);
            }
        }
    }

    set<int> groupNum; // 그룹의 갯수
    for (int i = 0; i < N; i++) {
        groupNum.insert(root[i]); 
        cout << root[i] << ' ' <<find(i) << endl;
    }

    cout << groupNum.size(); 

    return 0;
}
