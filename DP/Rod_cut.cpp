#include <bits/stdc++.h>
using namespace std;

int cutRod(vector<int> &price)
{
    int n = price.size();

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int length = i;
            int value = price[i - 1];

            if (length <= j)
                dp[i][j] = max(value + dp[i][j - length], dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[n][n];
}

int main()
{
    // Hardcoded input
    vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};

    cout << cutRod(price) << endl;

    return 0;
}