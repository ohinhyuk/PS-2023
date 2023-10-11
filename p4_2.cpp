#include <iostream>
#include <vector>
#include <vector>
#include <set>
#include <algorithm> // for sort()

using namespace std;

vector<int> emptyvector;
bool isTerminated = false;
vector<int> hanoiTop[3];
int cnt = 0;
int answerCnt = 0;

bool checkSame(vector<int> &from, vector<int> &by, vector<int> &to) {
    vector<vector<int> > inputConfig{from, by, to};
    vector<vector<int> > hanoiConfig{hanoiTop[0], hanoiTop[1], hanoiTop[2]};

    // 내용을 기준으로 정렬
    // sort(inputConfig.begin(), inputConfig.end());
    // sort(hanoiConfig.begin(), hanoiConfig.end());
    cout << "Input Config Start" << endl;
    for(int i = 0 ; i < 3 ; ++i){
        for(int j = 0 ; j < inputConfig[i].size() ; ++j){
            cout << inputConfig[i][j] << ' ';
        }
        cout << endl;
    }
    cout << "End" << endl;

    cout << "HanoiConfig Start" << endl;
    for(int i = 0 ; i < 3 ; ++i){
        for(int j = 0 ; j < hanoiConfig[i].size() ; ++j){
            cout << hanoiConfig[i][j] << ' ';
        }
        cout << endl;
    }
    cout << "End" << endl;


    for (int i = 0; i < 3; i++) {
        if(inputConfig[i].size() != hanoiConfig[i].size()) return false;

        for(int j = 0 ; j < inputConfig[i].size() ; ++j){
            if (inputConfig[i][j] != hanoiConfig[i][j]) return false;
        }
    }

    isTerminated = true;
    answerCnt = cnt;
    return true;
}

void hanoi(char type, int n, vector<int>& from, vector<int>& by, vector<int>& to) {
    if (isTerminated) return;

    if (n == 1) {
        if (!from.empty()) {
            to.push_back(from.back());
            from.pop_back();
        }
        cnt++;

        if (type == 'Y') {
            if (checkSame(from, by, to)) return;
        }
    } else {
        hanoi(type, n - 1, from, to, by);
        if (!from.empty()) {
            to.push_back(from.back());
            from.pop_back();
        }
        cnt++;

        if (type == 'Y') {
            if (checkSame(from, by, to)) return;
        }

        hanoi(type, n - 1, by, from, to);
    }
}

int main() {
    int n, target;
    cin >> n >> target;

    for (int i = 0; i < 3; ++i) {
        int rowBlockNum, block;
        cin >> rowBlockNum;

        for (int j = 0; j < rowBlockNum; ++j) {
            cin >> block;
            hanoiTop[i].push_back(block);
        }
    }

    vector<int> from, by, to;

    for (int i = n; i > 0; --i) {
        from.push_back(i);
    }
    hanoi('N', n, from, by, to);

    int tempCnt = cnt;
    isTerminated = false;
    cnt = 0;
    from.clear();
    by.clear();
    to.clear();
    for (int i = n; i > 0; --i) {
        from.push_back(i);
    }

    hanoi('Y', n, from, by, to);

    cout << from.size() << by.size() << to.size() << endl;
    cout << tempCnt << answerCnt << endl;

    if (!hanoiTop[target-1].empty() && hanoiTop[target-1].front() == n) {
        cout << answerCnt;
    } else {
        cout << tempCnt - answerCnt;
    }

    return 0;
}
