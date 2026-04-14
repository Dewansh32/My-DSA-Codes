#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {1,3,2,5,1,3,1,5,1};
    
    unordered_map<int,int> m;

    // Step 1: Count frequency
    for(int i = 0; i < arr.size(); i++) {
        if(m.count(arr[i])) {
            m[arr[i]]++;
        } else {
            m[arr[i]] = 1;
        }
    }

    // Step 2: Find majority element
    int n = arr.size();

    for(auto it : m) {
        if(it.second > n/3) {
            cout << "Majority element = " << it.first << endl;
        }
    }

    return 0;
}