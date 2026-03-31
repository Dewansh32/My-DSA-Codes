#include<iostream>
using namespace std;

int main() {
    int n=4,m=4;
    int arr[4][4] = {
        {1,  2,  3,  4},
        {5,  6,  7,  8},
        {9, 10, 11, 12},
        {13,14, 15, 16}
    };

    int primarySum = 0, secondarySum = 0;

    for(int i = 0; i < n; i++) {
        primarySum += arr[i][i];             // main diagonal
        secondarySum += arr[i][n - 1 - i];   // anti diagonal
    }

    int total = primarySum + secondarySum;

    // if n is odd, subtract the middle element (it was counted twice)
    if (n % 2 != 0) {
        total -= arr[n/2][n/2];
    }

    cout << total;

    return 0;
}
