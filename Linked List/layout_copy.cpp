#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class LList {
private:
    Node* head;
public:
    LList() {
        head = nullptr;
    }

    void push_front(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    void pop_front() {
        if (head == nullptr) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void print() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    ~LList() {
        while (head != nullptr) {
            pop_front();
        }
    }
};

int main() {
    LList list;
    list.push_front(10);
    list.push_front(20);
    list.push_front(30);

    list.print();
    list.pop_front();
    list.print();

    return 0;
}
