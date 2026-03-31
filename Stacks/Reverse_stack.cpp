#include <iostream>
#include <stack>
using namespace std;

void pushAtBottom(stack<int> &st, int x) {
    if (st.empty()) {
        st.push(x);
        return;
    }

    int topElement = st.top();
    st.pop();
    pushAtBottom(st, x);
    st.push(topElement);
}

void reverseStack(stack<int> &st) {
    if (st.empty()) return;

    int topElement = st.top();
    st.pop();
    reverseStack(st);
    pushAtBottom(st, topElement);
}

void printStack(stack<int> s) {
    cout << "Stack (top → bottom): ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main() {
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    cout << "Original ";
    printStack(st);

    reverseStack(st);

    cout << "Reversed ";
    printStack(st);

    return 0;
}
