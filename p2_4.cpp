#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int N;
vector<int> segments; // 세그먼트의 길이
vector<vector<int> > minInRange; // minInRange[i][j] : i~j까지의 세그먼트를 합치는데 필요한 최소 비용
vector<int> seqSum; // seqSum[i] : 0~i까지의 세그먼트 길이의 합


// start ~ end 까지 붙일 때 드는 시간 중 가장 적게드는 시간을 계산하는 함수
int minCost(int start, int end) {

    // 연결하는 과정이 불필요할 때
    if (start == end) return 0;
    
    // 이미 방문했던 곳일 때
    if (minInRange[start][end] != -1) return minInRange[start][end];

    int cost = INT_MAX;

    // 용접 시킬 수 있는 모든 방법을 돈다.
    for (int mid = start; mid < end; ++mid) {
        int hours = minCost(start, mid) + minCost(mid + 1, end) + seqSum[end + 1] - seqSum[start]; // start~mid 최소 비용, mid+1~end 최소 비용, start~end까지의 용접 비용
        cost = min(cost, hours);
    }

    minInRange[start][end] = cost;
    return cost;
}

int main() {

    cin >> N;

    segments.resize(N);
    seqSum.resize(N + 1, 0);
    minInRange.resize(N, vector<int>(N, -1));

    /**
     * @brief 세그먼트들 입력받고 seqSum 계산
     */
    for (int i = 0; i < N; ++i) {
        cin >> segments[i];
        seqSum[i + 1] = seqSum[i] + segments[i];
    }

    cout << minCost(0, N - 1) << endl;

    return 0;
}
