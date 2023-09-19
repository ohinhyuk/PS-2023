#include <iostream>
#include <vector>

using namespace std;


int main() {

    int input;

    cin >> input;

    long long int array[input+1];

    array[0] = 0;
    if(input >= 1) array[1] = 1;
    if(input >= 2) array[2] = 1;
    if(input >= 3) array[3] = 2;
    if(input >= 4) array[4] = 4;
    if(input >= 5) array[5] = 6;

    for(int i = 6 ; i < input+1 ; ++i){
        array[i] = (array[i-1]) + (array[i-3]) + (array[i-4]);
    }

    cout << array[input];
    
    return 0;
}