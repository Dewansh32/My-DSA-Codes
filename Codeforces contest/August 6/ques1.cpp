#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        unordered_map<int, int> freq;
        long long sum = 0;

        int maxFreq = 0;
        int maxValue = 0;

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            sum += x;

            freq[x]++;

            if (freq[x] > maxFreq) {
                maxFreq = freq[x];
                maxValue = x;
            }
        }

        int others = n - maxFreq;

        if (maxFreq <= others + 2) {
            cout << sum << '\n';
        } else {
            int useless = maxFreq - (others + 2);
            cout << sum - 1LL * useless * maxValue << '\n';
        }
    }

    return 0;
}