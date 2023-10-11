#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canGroup(pair<int, int>& a, pair<int, int>& b) {
    return (a.first < b.first && a.second > b.second) || (a.first > b.first && a.second < b.second);
}

bool canFormTripleGroup(vector<pair<int, int> >& applicants, int i, int j, int k) {
    return canGroup(applicants[i], applicants[j]) && 
           canGroup(applicants[j], applicants[k]) &&
           canGroup(applicants[i], applicants[k]);
}

int countGroups(vector<pair<int, int> > applicants, bool startWithTriple) {
    int count = 0;

    if (startWithTriple) {
        while (applicants.size() >= 3) {
            bool foundTriple = false;

            for (int i = 0; i < applicants.size() - 2; ++i) {
                for (int j = i + 1; j < applicants.size() - 1; ++j) {
                    for (int k = j + 1; k < applicants.size(); ++k) {
                        if (canFormTripleGroup(applicants, i, j, k)) {
                            count++;
                            applicants.erase(applicants.begin() + k);
                            applicants.erase(applicants.begin() + j);
                            applicants.erase(applicants.begin() + i);
                            foundTriple = true;
                            break;
                        }
                    }
                    if (foundTriple) break;
                }
                if (foundTriple) break;
            }
            if (!foundTriple) break;
        }
    }

    while (applicants.size() >= 2) {
        bool foundPair = false;
        for (int i = 0; i < applicants.size() - 1; ++i) {
            for (int j = i + 1; j < applicants.size(); ++j) {
                if (canGroup(applicants[i], applicants[j])) {
                    count++;
                    applicants.erase(applicants.begin() + j);
                    applicants.erase(applicants.begin() + i);
                    foundPair = true;
                    break;
                }
            }
            if (foundPair) break;
        }
        if (!foundPair) break;
    }

    if (!startWithTriple) {
        while (applicants.size() >= 3) {
            bool foundTriple = false;

            for (int i = 0; i < applicants.size() - 2; ++i) {
                for (int j = i + 1; j < applicants.size() - 1; ++j) {
                    for (int k = j + 1; k < applicants.size(); ++k) {
                        if (canFormTripleGroup(applicants, i, j, k)) {
                            count++;
                            applicants.erase(applicants.begin() + k);
                            applicants.erase(applicants.begin() + j);
                            applicants.erase(applicants.begin() + i);
                            foundTriple = true;
                            break;
                        }
                    }
                    if (foundTriple) break;
                }
                if (foundTriple) break;
            }
            if (!foundTriple) break;
        }
    }

    count += applicants.size();

    return count;
}

int main() {
    
    int N;

    cin >> N;

    vector<pair<int, int> > applicants(N);
    
    for (int i = 0; i < N; ++i) {
        cin >> applicants[i].first >> applicants[i].second;
    }

    int count1 = countGroups(applicants, true);
    int count2 = countGroups(applicants, false);

    cout << max(count1, count2) << endl;

    return 0;
    
}
