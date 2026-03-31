#include<iostream>
#include<climits>
using namespace std;

void max_profit(int arr[], int n) {
    int min_price = INT_MAX;
    int max_profit = 0;

    for(int i = 0; i < n; i++) {
        if(arr[i] < min_price) {
            min_price = arr[i];  // Update min price
        }
        
        int current_profit = arr[i] - min_price;
        
        if(current_profit > max_profit) {
            max_profit = current_profit;  // Update max profit
        }
    }

    cout << "Maximum Profit: " << max_profit << endl;
}

int main() {
    int arr[6] = {7, 1, 5, 3, 6, 4};
    int n = 6;

    max_profit(arr, n);

    return 0;
}
