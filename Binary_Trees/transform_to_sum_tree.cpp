#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

static int idx = -1;

Node* buildTree(vector<int>& nodes) {
    idx++;
    if(nodes[idx] == -1)
        return NULL;

    Node* root = new Node(nodes[idx]);
    root->left = buildTree(nodes);
    root->right = buildTree(nodes);

    return root;
}

// 🔥 TRANSFORM TO SUM TREE
int transform(Node* root) {
    if(root == NULL)
        return 0;

    int leftOld = transform(root->left);
    int rightOld = transform(root->right);

    int currOld = root->data;

    int leftData = (root->left != NULL) ? root->left->data : 0;
    int rightData = (root->right != NULL) ? root->right->data : 0;

    root->data = leftOld + rightOld + leftData + rightData;

    return currOld;
}

// preorder print to verify
void preorder(Node* root) {
    if(root == NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};

    idx = -1;
    Node* root = buildTree(nodes);

    cout << "Before Transform (Preorder): ";
    preorder(root);
    cout << endl;

    transform(root);

    cout << "After Transform (Preorder): ";
    preorder(root);
    cout << endl;

    return 0;
}
