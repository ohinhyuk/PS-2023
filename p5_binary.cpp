#include <iostream>
#include <vector>
using namespace std;


vector<int> cards;
vector<int> insIdx;
vector<int> decIdx;
vector<int> insCards;
vector<int> decCards;

int binarysearch(int left, int right, int target) {

	int mid;

	while (left < right) {
		mid = (left + right) / 2;

		if (insCards[mid] < target) {
			left = mid + 1;
		}
		else {
			right = mid;
		}
	}
	return right;
}

int main() {


	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int tmp;
        cin >> tmp;
        cards.push_back(tmp);
	}

    insCards.push_back(cards[0]);
    decCards.push_back(cards[n-1]);

	insIdx.push_back(0); // lis 배열의 맨 첫번째 값은 arr[0]으로 초기화
    decIdx.push_back(n-1);

	int i = 1;
	int j = 0;

	// arr의 두번째부터 마지막까지 하나씩 lis와 비교하면서 넣어준다.
	while (i < n) {
		// lis 배열의 맨 뒤의 값보다 arr[i]가 더 크면 그것을 lis 배열 맨 뒤에 넣어준다.
		if (insCards[j] < cards[i]) {
			insIdx.push_back(i);
            insCards.push_back(cards[i]);
			j += 1;
		}
		// cards[i]값이 더 작으면, cards[i]의 값이 lis 배열 중 어느 곳에 들어올지 이분탐색한다.
		else {
            // 0부터 j까지 탐색하면서 cards[i]가 들어갈 수 있는 위치를 찾아서 idx에 반환
			int idx = binarysearch(0, j, cards[i]);
            cout << i << j << ' ' << idx << ' ' << cards[i] << cards[j] << endl;
            
            if(insIdx[idx] != cards[i]){
                insIdx[idx] = i;
                insCards[idx] = cards[i];
            } 
		}
		i += 1;
	}

    for(int ff : insIdx) cout << ff << ' ';

	cout << j + 1;

    return 0;
}