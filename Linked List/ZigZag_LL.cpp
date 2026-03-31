#include <bits/stdc++.h>
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
public:
    Node* head;
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

    void push_back(int val) {
        Node* newNode = new Node(val);

        if (head == nullptr) {  // empty list
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) {  // go to last node
            temp = temp->next;
        }
        temp->next = newNode;  // attach new node
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

    // returns pointer to start of second half; breaks the list into two by setting end of first half -> NULL
    Node* splitAtMid(Node* head) {
        if (head == nullptr) return nullptr;
        Node* slow = head;
        Node* fast = head;
        Node* prev = nullptr;

        while (fast != nullptr && fast->next != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        // disconnect first half if prev exists
        if (prev != nullptr) {
            prev->next = nullptr;
        }

        return slow;
    }

    // standard iterative reverse of linked list
    Node* reverse(Node* head) {
        Node* prev = nullptr;
        Node* curr = head;
        Node* next = nullptr;
        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next; // advance to next node (fixed)
        }
        return prev;
    }

    // reorder list in zigzag: L0, Ln, L1, Ln-1, L2, Ln-2, ...
    Node* ZigZag(Node* head) {
        if (head == nullptr || head->next == nullptr) return head;

        // split into two halves
        Node* rightHead = splitAtMid(head);

        // reverse second half
        Node* rightHeadRev = reverse(rightHead);

        Node* left = head;
        Node* right = rightHeadRev;
        Node* tail = nullptr; // keep track of last node we've attached

        // merge by alternating nodes from left and right
        while (left != nullptr && right != nullptr) {
            Node* nl = left->next;
            Node* nr = right->next;

            left->next = right;
            right->next = nl;

            tail = right; // last node attached

            left = nl;
            right = nr;
        }

        // attach any remaining nodes (one of left or right may be non-null)
        if (tail == nullptr) {
            // should not happen except when list was empty
            return head;
        }
        if (left != nullptr) {
            tail->next = left;
        } else if (right != nullptr) {
            tail->next = right;
        }

        return head;
    }
};

int main() {
    LList ll;

    // pushes in front produce list: 5 -> 4 -> 3 -> 2 -> 1 -> NULL
    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);
    ll.push_front(4);
    ll.push_front(5);

    cout << "Original list:" << endl;
    ll.print();

    ll.head = ll.ZigZag(ll.head);

    cout << "After ZigZag reorder:" << endl;
    ll.print();

    return 0;
}
