#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int n0 = 0, n1 = 0;
    for (char c : s) {
        if (c == '0') n0++;
        else n1++;
    }

    int L0 = 0;
    char exp = '0';
    for (char c : s) {
        if (c == exp) {
            L0++;
            exp = (exp == '0') ? '1' : '0';
        }
    }

    int L1 = 0;
    exp = '1';
    for (char c : s) {
        if (c == exp) {
            L1++;
            exp = (exp == '1') ? '0' : '1';
        }
    }

    int D = n0 - n1;
    int ans = 1e9;

    for (int delta = -1; delta <= 1; delta++) {
        if (abs(D - delta) <= 1) {
            int len = -1;
            
            if (delta == 1) {
                len = (L0 % 2 != 0) ? L0 : L0 - 1;
            } else if (delta == -1) {
                len = (L1 % 2 != 0) ? L1 : L1 - 1;
            } else if (delta == 0) {
                int len0 = (L0 % 2 == 0) ? L0 : L0 - 1;
                int len1 = (L1 % 2 == 0) ? L1 : L1 - 1;
                len = max(len0, len1);
            }
            
            if (len >= 0) {
                ans = min(ans, n - len);
            }
        }
    }

    if (ans > n) {
        cout << -1 << "\n";
    } else {
        cout << ans << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}