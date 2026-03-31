#include <iostream>
using namespace std;

class Node {
    public:
    int val;
    Node* next;
    Node(int x) : val(x), next(nullptr) {}
};

Node* append(Node* &tail, int value) {
    Node* n = new Node(value);
    if (tail) tail->next = n;
    tail = n;
    return n;
}

void printList(Node* head) {
    for (Node* p = head; p; p = p->next) {
        cout << p->val;
        if (p->next) cout << " -> ";
    }
    cout << endl;
}

Node* swapNodes(Node* head, int x, int y) {
    // implement your logic here (swap nodes by changing links, not values)
    Node* temp = head;
    Node* prev = NULL;
    while(temp!=NULL)
    {
        if(temp->val == x)
        {
            break;
        }
        prev = temp;
        temp = temp->next;
    }

    Node* temp2 = head;
    Node* prev2 = NULL;

    while(temp2!=NULL)
    {
        if(temp2->val == y)
        {
            break;
        }
        prev2 = temp2;
        temp2 = temp2->next;
    }
    Node* nxt = temp2->next;
    prev->next = temp2;
    temp2->next = temp->next;
    prev2->next = temp;
    temp->next = nxt;
    

    return head;
}

int main() {
    Node* head = new Node(1);
    Node* tail = head;
    append(tail, 2);
    append(tail, 3);
    append(tail, 4);

    cout << "Original List: ";
    printList(head);

    int x = 2, y = 4;

    head = swapNodes(head, x, y);

    cout << "After Swapping " << x << " and " << y << ": ";
    printList(head);

    return 0;
}
