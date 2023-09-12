#include <iostream>
using namespace std;

int counter_four_logn(int n){
    int result = 0;
    int multiplier = 1;

    while(n){
        int digit = n % 10;
        if(digit > 4) digit--;
        result += digit * multiplier;
        multiplier *= 9;
        n /= 10;
    }

    return result;
}

int main() {
    int input;
    cin >> input;
    cout << counter_four_logn(input) << endl;
    return 0;
}