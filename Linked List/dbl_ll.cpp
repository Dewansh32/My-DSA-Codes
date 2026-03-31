#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // Add element to the front
    void push_front(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // Remove element from the front
    void pop_front() {
        if (!head) {
            cout << "List is empty. Cannot pop.\n";
            return;
        }

        Node* temp = head;
        if (head == tail) { // only one node
            head = tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
    }

    // Display the list from front to back
    void display() const {
        Node* curr = head;
        while (curr) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << "\n";
    }

    // Destructor to free memory
    ~DoublyLinkedList() {
        while (head) {
            pop_front();
        }
    }
};

int main() {
    DoublyLinkedList dll;

    dll.push_front(10);
    dll.push_front(20);
    dll.push_front(30);

    cout << "List after push_front operations: ";
    dll.display();

    dll.pop_front();
    cout << "List after pop_front: ";
    dll.display();

    return 0;
}
