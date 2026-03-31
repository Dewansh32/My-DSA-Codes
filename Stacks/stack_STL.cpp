#include <bits/stdc++.h>
using namespace std;

int main() {
    stack<int> S;  // create a stack of integers

    // push elements
    S.push(4);
    S.push(3);
    S.push(2);
    S.push(1);

    // print stack (from top to bottom)
    stack<int> temp = S;  // copy to preserve original stack
    cout << "Stack elements (top to bottom): ";
    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;

    // pop top element
    S.pop();

    // print after pop
    temp = S;
    cout << "After pop: ";
    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;

    // show top element
    cout << "Top element: " << S.top() << endl;

    // check if empty
    cout << "Is stack empty? " << (S.empty() ? "Yes" : "No") << endl;

    // show size
    cout << "Stack size: " << S.size() << endl;

    return 0;
}
