#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(list<int>& lst) {
        int n = (int)lst.size();
        if (n <= 1) return true;

        stack<int> S;
        auto it = lst.begin();

        // push first half values onto stack
        for (int i = 0; i < n / 2; ++i) {
            S.push(*it);
            ++it;
        }

        // if odd length, skip the middle element
        if (n % 2 == 1) ++it;

        // compare second half with values popped from stack
        while (it != lst.end()) {
            if (S.empty()) return false;      // defensive
            if (*it != S.top()) return false;
            S.pop();
            ++it;
        }

        return S.empty();
    }
};

int main() {
    list<int> lst1 = {1, 2, 2, 1};
    list<int> lst2 = {1, 2, 3};

    Solution sol;
    cout << (sol.isPalindrome(lst1) ? "true" : "false") << endl; // true
    cout << (sol.isPalindrome(lst2) ? "true" : "false") << endl; // false

    return 0;
}
