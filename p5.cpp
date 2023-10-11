#include <iostream>
#include <vector>

using namespace std;


int main() {
    
/**
 @brief 카드를 가져갈 수 있는 상황
    1) 카드를 하나도 가지고 있지 않을 때
    2) 가장 최근 나의 카드 < new 카드
    3) 가장 최근 나의 카드 > new 카드 -> 이러면 계속 낮은 카드만 가져가야 함.
 * 
dp로 해결
dp[i] = i번째 카드를 오름 차순으로 가져갈 수 있는 최대 카드 수

dp[0] = 1 [ 1 ]
dp[1] = 2 [ 1 , 7]
dp[2] = 2 [ {1 , 3} or {1, 7}  ]
dp[3] = 3 [ {1 , 3 , 4} or {1, 3, 7} or {1, 7, 8} ]
1) 뒤에 추가하는 방법
2) 스킵하는 방법
3) 

 2 
 7 
 8 
 3 
 4 
 5 
 5 
 1
 3
 4

 * 
 */

    int n;
    cin >> n;

    
    int cards[n+1];
    int cardsOneToIdx[n+1];
    int cardsIdxToOne[n+1];
    // int answerCardsIdxToOne[n+1];

    for(int i = 0; i <= n; i++) {
        cardsOneToIdx[i] = 1;
        cardsIdxToOne[i] = 1;
        // answerCardsIdxToOne[i] = 1;
    }

    for (int i = 1; i <= n; ++i) {
        cin >> cards[i];
    }

    for(int i = 2 ; i <= n ; ++i){
        for(int j = 1 ; j < i ; ++j){
            if(cards[i] > cards[j]){
                cardsOneToIdx[i] = max(cardsOneToIdx[i] , cardsOneToIdx[j]+1);
            }
        }
    }

    for(int i = 0 ; i < n ; ++i){
        if(cardsOneToIdx[i] > cardsOneToIdx[i+1]) cardsOneToIdx[i+1] = cardsOneToIdx[i];
    }

    for(int i = n-1 ; i > 0 ; --i){
        for(int j = n ; j > i ; --j){
            if(cards[i] > cards[j]){
                cardsIdxToOne[i] = max(cardsIdxToOne[i] , cardsIdxToOne[j]+1);
                // answerCardsIdxToOne[i] = max(answerCardsIdxToOne[i] , answerCardsIdxToOne[j]+1);
            }
        }
    }
    for(int i = n ; i > 0 ; --i){
        if(cardsIdxToOne[i] > cardsIdxToOne[i-1]) cardsIdxToOne[i-1] = cardsIdxToOne[i];
    }

    // for(int i = 1 ; i <= n ; ++i){
    //     cout << cardsOneToIdx[i] << " ";

    // }
    // cout<< endl;
    // for(int i = 1 ; i <= n ; ++i){
        
    //     cout << cardsIdxToOne[i] << " ";

    // }

    int answer = 0;

    for(int i = 1 ; i <= n ; ++i){
        int temp = cardsOneToIdx[i] + cardsIdxToOne[i] - 1;
        if(answer < temp){
            answer = temp;
        }
    }

    cout << answer;


    return 0;
}