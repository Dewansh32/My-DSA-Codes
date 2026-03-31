#include <bits/stdc++.h>
using namespace std;

bool isDuplicate(const string &S) {
    stack<char> st;
    for (char c : S) {
        if (c == ')') {
            // If immediately matching '(' then we have "()"
            if (st.empty()) continue;           // malformed but skip safely
            if (st.top() == '(') return true;  // redundant pair like "( )" or "(a)"?
            // otherwise pop until '('
            while (!st.empty() && st.top() != '(') {
                st.pop();
            }
            if (!st.empty()) st.pop(); // pop the '('
        } else {
            st.push(c);
        }
    }
    return false; // no redundant parentheses found
}

int main() {
    string S1 = "((a+b)+(c+d))";
    string S2 = "((a+b))";

    cout << S1 << " -> " << (isDuplicate(S1) ? "redundant" : "not redundant") << "\n";
    cout << S2 << " -> " << (isDuplicate(S2) ? "redundant" : "not redundant") << "\n";

    return 0;
}
