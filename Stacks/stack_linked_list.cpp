#include <bits/stdc++.h>
using namespace std;

template <class T>
class Stack {
    list<T> lst;

public:
    void push(T val) {
        lst.push_front(val); // push at front
    }

    void pop() {
        if (!lst.empty())
            lst.pop_front(); // remove from front
        else
            cout << "Stack is empty!\n";
    }

    T top() {
        if (!lst.empty())
            return lst.front(); // top is the front element
        throw runtime_error("Stack is empty!");
    }

    void print() {
        for (auto it = lst.rbegin(); it != lst.rend(); ++it) {
            cout << *it << " ";
        }
        cout << endl;
    }

    bool empty() {
        return lst.empty();
    }
};

int main() {
    Stack<int> S;
    S.push(4);
    S.push(3);
    S.push(2);
    S.push(1);
    S.print();   // prints: 4 3 2 1

    S.pop();
    S.print();   // prints: 4 3 2

    cout << S.top() << endl; // prints: 2

    return 0;
}
