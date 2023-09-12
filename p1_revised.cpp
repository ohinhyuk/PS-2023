#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int , long long int> &a,pair<int , long long int> &b ){
    
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int main() {

    vector<pair<int , long long int> > v;
    
    long long int answer = 0;
    long long int sum = 0;
    long long int x;

    int g , n , k;
    int left = 0;
    int right = 0;

    cin >> n >> k;

    /**
     * @brief 벡터 입력 받음
     * 
     */
    for(int i = 0 ; i < n ; ++i){
        cin >> g >> x;
        v.push_back(make_pair(g,x));
    }

    /**
     * @brief 거리를 기준으로 오름차순으로 정렬
     */

    sort(v.begin(), v.end() ,compare);

    
    /**
     * @brief v를 순회하면서 부분합을 구함
     * 
     */

    while (right < n) {
        if (v[right].second <= 2 * k + v[left].second) {
            sum += v[right].first;
            right++;
        } else {
            sum -= v[left].first;
            left++;
        }

        if (sum > answer) {
            answer = sum;
        }
    }

    /**
     * @brief 정답 제출
     * 
     */
    cout << answer;

    return 0;
}