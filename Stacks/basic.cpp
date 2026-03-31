#include <bits/stdc++.h>
using namespace std;

template <class T>
class Stack {
    vector<T> vect;
public:
    void push(T val) {
        vect.push_back(val);
    }

    void pop() {
        if (!vect.empty())
            vect.pop_back();
        else
            cout << "Stack is empty!\n";
    }

    T top() {
        if (!vect.empty())
            return vect.back();
        throw runtime_error("Stack is empty!");
    }

    void print() {
        for (int i = 0; i < vect.size(); i++) {
            cout << vect[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack<int> S;
    S.push(4);
    S.push(3);
    S.push(2);
    S.push(1);
    S.print();

    S.pop();
    S.print();

    cout << S.top();
    return 0;
}
