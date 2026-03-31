#include <iostream>
using namespace std;

string rem_dup(string str, string ans, int i, bool check[]) {
    // Base condition
    if (i == str.length()) return ans;

    int idx = str[i] - 'a'; // Convert char to index (0-25)

    if (!check[idx]) {
        ans.push_back(str[i]);
        check[idx] = true;
    }

    // Return the recursive result
    return rem_dup(str, ans, i + 1, check);
}

int main() {
    string str = "appnnacollege";
    bool check[26] = {false};
    string ans = "";

    cout << rem_dup(str, ans, 0, check);

    return 0;
}
