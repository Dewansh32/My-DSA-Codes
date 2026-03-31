#include <bits/stdc++.h>
using namespace std;

class Stack {
    queue<int> q1;
    queue<int> q2;

public:
    // Push operation: O(n)
    void push(int data) {
        // Step 1: push new element into q2
        q2.push(data);

        // Step 2: move all elements from q1 to q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        // Step 3: move everything back to q1
        while (!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
    }

    // Pop operation: O(1)
    void pop() {
        if (q1.empty()) {
            cout << "STACK EMPTY" << endl;
            return;
        }
        cout << "Popped: " << q1.front() << endl;
        q1.pop();
    }

    // Top operation: O(1)
    int top() {
        if (q1.empty()) {
            cout << "STACK EMPTY" << endl;
            return -1;
        }
        return q1.front();
    }

    // Check if stack is empty
    bool empty() {
        return q1.empty();
    }
};

int main() {
    Stack st;

    cout << "---- Pop on empty ----" << endl;
    st.pop();

    cout << "\n---- Push elements ----" << endl;
    st.push(10);
    st.push(20);
    st.push(30);

    cout << "\nTop element (should be 30): " << st.top() << endl;

    cout << "\n---- Pop elements ----" << endl;
    st.pop();   // 30
    st.pop();   // 20

    cout << "\nTop element (should be 10): " << st.top() << endl;

    st.pop();   // 10

    cout << "\n---- Empty check ----" << endl;
    cout << (st.empty() ? "Stack is empty" : "Stack is not empty") << endl;

    cout << "\n---- Pop again ----" << endl;
    st.pop();

    return 0;
}
