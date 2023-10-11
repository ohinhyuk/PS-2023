#include <iostream>
#include <vector>
#include <deque>
#include <set>

using namespace std;

deque<int> emptyDeque;
bool isTerminated = false; 
deque<int> hanoiTop[3];
int cnt = 0;
int answerCnt = 0;

// bool checkSame(deque<int> from , deque<int> by , deque<int> to){

//     set<deque<int> > inputSet;
//     inputSet.insert(from);
//     inputSet.insert(by);
//     inputSet.insert(to);

//     set<deque<int> > hanoiSet;
//     if(hanoiTop[0][0] != -1) hanoiSet.insert(hanoiTop[0]);
//     if(hanoiTop[1][0] != -1){
//         hanoiSet.insert(hanoiTop[1]);
//     }else {
//         hanoiSet.insert(emptyDeque);
//     } 
//     if(hanoiTop[2][0] != -1){
//         hanoiSet.insert(hanoiTop[2]);
//     }else {
//         hanoiSet.insert(emptyDeque);
//     } 


//     if(inputSet == hanoiSet) {
        
//         isTerminated = true;  // 플래그 설정
//         answerCnt = cnt;
//         return true;
//     }
//     return false;
// }


bool checkSame(deque<int> &from, deque<int> &by, deque<int> &to) {
     vector<deque<int> > inputConfig;
    inputConfig.push_back(from);
    inputConfig.push_back(by);
    inputConfig.push_back(to);
    vector<deque<int> > hanoiConfig;
    hanoiConfig.push_back(hanoiTop[0]);
    hanoiConfig.push_back(hanoiTop[1]);
    hanoiConfig.push_back(hanoiTop[2]);

    // 내용을 기준으로 정렬
    sort(inputConfig.begin(), inputConfig.end());
    sort(hanoiConfig.begin(), hanoiConfig.end());

    for (int i = 0; i < 3; i++) {
        if (inputConfig[i] != hanoiConfig[i]) return false;
    }

    isTerminated = true;
    answerCnt = cnt;
    return true;
}
void hanoi(char type, int n , deque<int>& from, deque<int>& by , deque<int>& to){
    if(isTerminated) return; 

    if(n == 1){
        to.push_front(from.back());
        from.pop_back();
        cnt++;

        if(type == 'Y'){
            if(checkSame(from , by, to)) return;
        }
        
    }
    else{
        
        hanoi(type, n-1 , from , to , by);
        to.push_front(from.back());
        from.pop_back();
        cnt++;

if(type == 'Y'){
        if(checkSame(from , by, to)) return;

}

        hanoi(type,n-1 , by , from, to);
    }
}


int main() {
    
    int n , target;

    cin >> n >> target;

    int rowBlockNum , block;

    for(int i = 0 ; i < 3 ; ++i){

        cin >> rowBlockNum;
        
        for(int j = 0 ; j < rowBlockNum ; ++j){
            cin >> block;
            hanoiTop[i].push_back(block);
        }

        // if(rowBlockNum == 0) hanoiTop[i].push_back(-1);

    }

    deque<int> from;
    deque<int> by; 
    deque<int> to;
    

    for(int i = n ; i > 0 ; --i){
        from.push_back(i);
    }
    hanoi('N', n , from,by,to);
    
    int tempCnt = cnt;
    isTerminated = false;
    cnt = 0;
    from.clear();
    by.clear();
    to.clear();
    for(int i = n ; i > 0 ; --i){
        from.push_back(i);
    }

    hanoi('Y', n,from,by,to);
    
    cout << answerCnt << tempCnt << endl;

    if(hanoiTop[target-1].front() == n){
        cout << answerCnt;
    } else{
        cout << tempCnt - answerCnt;
    }
    // cout << cnt;


    // for(int i = 0 ; i < 3; ++i){
    //     for(int j = 0 ; j < hanoiTop[i].size() ; ++j){
    //         cout << hanoiTop[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    return 0;
}