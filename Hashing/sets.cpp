#include <bits/stdc++.h>
using namespace std;

int main() {
    set<int> s;

    s.insert(1);
    s.insert(5);
    s.insert(3);
    s.insert(2);

    // duplicates (ignored automatically)
    // s.insert(1);
    // s.insert(1);
    // s.insert(1);

    // size of set
    cout << s.size() << endl;

    // erase element
    s.erase(3);

    // check if element exists
    if (s.find(3) != s.end()) {
        cout << "3 exists\n";
    } else {
        cout << "3 doesn't exist\n";
    }

    // print all elements
    for (auto el : s) {
        cout << el << " ";
    }

    cout << endl;

    return 0;
}