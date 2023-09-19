#include <iostream>
#include <vector>

using namespace std;

int main() {

    int N;
    
    cin >> N;
    
    vector<int> segments(N); // 세그먼트의 길이
    vector<vector<int> > minInRange(N, vector<int>(N, 0)); // minInRange[i][j] : i~j까지의 세그먼트를 합치는데 필요한 최소 비용
    vector<int> seqSum(N + 1); // seqSum[i] : 0~i까지의 세그먼트 길이의 합
    
    /**
     * @brief 세그먼트들 입력받고 seqSum 계산
     */

    for (int i = 0; i < N; ++i) {
        cin >> segments[i];
        seqSum[i + 1] = seqSum[i] + segments[i];
    }

    /**
     * @brief 1 ~ 10 까지의 최소 용접 비용을 구한다.
     */

    for (int len = 2; len <= N; len++) {
        for (int start = 0; start < N - len + 1; start++) {
            int end = start + len - 1;
            minInRange[start][end] = INT_MAX;
            
            for (int mid = start; mid < end; mid++) {
                int hours = minInRange[start][mid] + minInRange[mid + 1][end] + seqSum[end + 1] - seqSum[start]; // start~mid 최소 비용, mid+1~end 최소 비용, start~end까지의 용접 비용
                minInRange[start][end] = min(minInRange[start][end], hours);
            }
        }
    }
    
    cout << minInRange[0][N - 1] << endl;
    
    return 0;
}