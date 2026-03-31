#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> nsl(n), nsr(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            nsl[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            nsr[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        long long maxArea = 0;
        for (int i = 0; i < n; i++) {
            long long width = nsr[i] - nsl[i] - 1;
            long long area = 1LL * heights[i] * width;
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};

int main() {
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    Solution sol;
    cout << sol.largestRectangleArea(heights) << "\n";
    return 0;
}
