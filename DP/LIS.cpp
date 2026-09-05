#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lcs(vector<int> nums, vector<int> copy) {
        int m = copy.size();
        int n = nums.size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (copy[i - 1] == nums[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[m][n];
    }

    int lengthOfLIS(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());

        // Sorted unique array
        vector<int> copy(s.begin(), s.end());

        return lcs(nums, copy);
    }
};

int main() {
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};

    Solution obj;
    cout << "Length of LIS = " << obj.lengthOfLIS(nums) << endl;

    return 0;
}