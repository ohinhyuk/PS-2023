/**
 * 주어진 무작위 탑을 주어진 목적지에 일렬로 세우는데 걸리는 최소의 움직임 수를 구하라 ->
 * 
 * disk들이 무작위로 위치가 주어지기 때문에 각 disk들의 위치(rod)를 바로 알 수 있도록 disk들의 위치를 만들어서 알고리즘의 출발 위치로 사용한다.
 * disk들의 위치가 무작위 임을 고려하여 이미 도착 위치에 도착해 있는 disk들은 카운트 하지 않고 패스한다.
 * 주어진 목적지를 처음 알고리즘의 도착 위치로 사용한다.
 * 
 * 위 조건들을 고려하여 기존의 하노이 탑을 변형하여 사용한다.
 * 
 * 해결 방법
 * 1. n개의 disk들의 위치(Rod)들을 입력받고 저장한다.
 * 2. 무작위로 나열된 1~n까지의 disk들을 시작위치(from)에서 도착위치(To)로 옮긴다.
 *  - n이 1인 경우 : disk 1만 옮긴다 (이미 도착 위치(To)에 있다면 그대로 두고 아니라면 옮기고(disk들의 위치를 저장한 값을 변경) 카운트를 하나 올린다.)
 *  - n이 1이 아닌 경우 :   1) 1~n-1 까지 n-1의 위치 (rod)를 시작 위치로 하여 n의 temp를 도착 위치로 하여 옮긴다.
 *                      2) disk n을 옮긴다. (이미 도착 위치(To)에 있다면 그대로 두고 아니라면 옮기고(disk들의 위치를 저장한 값을 변경) 카운트를 하나 올린다.)
 *                      3) 1~n-1 까지 n-1의 위치( rod)를 시작위치로 하여 n의 도착 위치를 도착 위치로 하여 옮긴다.
 * 
 * 3. 2. 과정을 정렬이 완료 될 때까지 반복적으로 진행한다.
 * 
 * 시간복잡도
 * O(n) + O(2^n) = O(2^n)
 */

#include <iostream>
#include <vector>

using namespace std;

vector<int> diskRodIdx; // 각 디스크의 rod 위치
int cnt = 0; // 이동 시킨 횟수
int n, target; 


void customHanoi(int n, int from , int tmp, int to){

    if(n == 1){

        // 이미 to에 위치 해 있는 경우는 제외한다.
        if(from != to){
            cnt++;
            diskRodIdx[n] = to;
        }
        
    }else{
        
        // 이미 to에 위치 해 있는 경우는 제외한다.
        if(from != to){
            
            customHanoi(n-1, diskRodIdx[n-1] , 6-diskRodIdx[n-1]-tmp, tmp);
            
            cnt++;
            diskRodIdx[n] = to;

        }

        customHanoi(n-1, diskRodIdx[n-1] , 6-diskRodIdx[n-1]-to , to);
    }
}

int main() {

    cin >> n >> target;
    
    diskRodIdx.resize(n+1);

    for (int i = 0; i < 3; ++i){
        
        int diskNum, disk;
        cin >> diskNum;

        for (int j = 0; j < diskNum; ++j) {
            cin >> disk;
            diskRodIdx[disk] = i+1;
        }
    }

    int from = diskRodIdx[n]; // n 의 출발 위치
    int to = target; // n의 도착 위치
    int tmp= 6 - from - to; // n의 출발 위치와 도착 위치를 제외한 곳

    // 1~n노드를 from에서 to로 이동 시킴
    customHanoi( n , from , tmp, to );
    
    cout << cnt;

    return 0;
}