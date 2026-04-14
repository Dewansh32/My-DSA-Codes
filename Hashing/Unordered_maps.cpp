#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_map<string, int> m;

    m["China"] = 150;
    m["India"] = 150;
    m["US"] = 50;
    m["Nepal"] = 10;
    m["Nepal"] = 200; // overwrites previous value

    // Traversing the map
    for (pair<string, int> country : m) {
        cout << country.first << "," << country.second << endl;
    }

    cout << endl;

    // Checking if key exists
    if (m.count("Nepal")) {
        cout << "Nepal exists\n";
    } else {
        cout << "Nepal doesn't exist\n";
    }

    return 0;
}