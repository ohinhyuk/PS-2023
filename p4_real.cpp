#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

// 정렬 함수 (오름차순 , 오름차순)
bool compare(pair<long long int ,long long int> a , pair<long long int ,long long  int> b){
    if(a.first == b.first){
        return a.second < b.second;
    }else{
        return a.first < b.first;
    }
}

int main() {

    vector<pair<long long int , long long int> > step; // f,g를 모두 가지고 있는 step 벡터
    long long int n1 , n2 , first , second; 

    cin >> n1;

    for(long long int i = 0 ; i < n1 ; ++i){
        cin >> first >> second;
        step.push_back(make_pair(first,second));
    }

    cin >> n2;

    for(long long int i = 0 ; i < n2; ++i){
        cin >> first >> second;
        step.push_back(make_pair(first,second));
    }

    long long int p, q;

    cin >> p >> q;

    // 오름차순 정렬
    sort(step.begin() , step.end() , compare);

    long long int answer = 0;


    long long int startIdx = 0; // step 함수의 index 중 p보다 작은 것 중 가장 가까운 것
    long long int endIdx = 0; // step 함수의 index 중 q보다 작은 것 중 가장 가까운 것
    
   
   // 예외 1) p,q가 첫번째 step보다 작은 경우
    if(step[0].first > q){
        cout << 0 << endl;
        return 0;
    }

    // 예외 2) p , q 가 마지막 step보다 큰 경우
    else if(p >= step[step.size()-1].first ){
        startIdx = step.size()-1;
        endIdx = step.size()-1;
    }

    // 예외 3) p는 마지막 step보다 크지 않고 q는 마지막 step보다 크고
    else if(q >= step[step.size()-1].first ){
        endIdx = step.size()-1;
    }
    else{
         // 메인 해결 알고리즘 : p와 q를 통해 startIdx 와 endIdx를 구하는 과정
        for(long long int i = 0 ; i < step.size()-1 ; ++i){
            
            // step 함수 업데이트
            // index값이 큰데 함수 값이 더 작으면 큰 값으로 업데이트
            if(step[i].second > step[i+1].second) step[i+1].second = step[i].second;

            // startIdx를 찾는 과정
            if(step[i].first <= p && step[i+1].first > p){
                startIdx = i;
            }

            // endIdx를 찾는 과정
            if(step[i].first <= q && step[i+1].first > q){
                endIdx = i;
                break;
            }
        }
    }
   
 
    long long int startToEndValue = 0;


    // startIdx ~ endIdx 사이의 값을 계산
    for(long long int i = startIdx ; i < endIdx ; ++i){
        startToEndValue += (step[i+1].first - step[i].first) * step[i].second;
    }

    //예외 4) p가 첫번째 step보다 작고 q는 첫번째 step보다 큰 경우 -> (step[0].first > p) ? 0

    // startIdx ~ p 사이의 값을 계산
    long long int startToPValue = (step[0].first > p) ? 0 : (p - step[startIdx].first) * step[startIdx].second ;

    // q ~ endIdx 사이의 값을 계산
    long long int qToEndValue = (q - step[endIdx].first + 1) * step[endIdx].second;

    // total = (startIdx ~ endIdx) - (startIdx ~ p) - (q - endIdx)
    cout << (startToEndValue - startToPValue + qToEndValue ) % 10007 << endl;

    return 0;
}