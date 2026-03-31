#include <bits/stdc++.h>
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
    if (nodes[idx] == -1) {
        return NULL;
    }

    Node* curr = new Node(nodes[idx]);
    curr->left = buildTree(nodes);
    curr->right = buildTree(nodes);

    return curr;
}

bool isIdentical(Node* root1,Node* root2)
{
    if(root1 == NULL && root2 == NULL)
    {
        return true;
    }
    else if(root1 == NULL || root2 == NULL)
    {
        return false;
    }

    if(root1->data != root2->data)
    {
        return false;
    }

    return isIdentical(root1->left,root2->left) && isIdentical(root1->right,root2->right);
}

bool isSubtree(Node* root, Node* subRoot) {
    // TODO: Implement subtree checking logic
    if(root == NULL && subRoot == NULL)
    {
        return true;
    }
    else if(root == NULL || subRoot == NULL)
    {
        return false;
    }
    
    if(root->data == subRoot->data)
    {
        if(isIdentical(root,subRoot))
        {
            return true;
        }
    }
    bool leftsubtree = isSubtree(root->left,subRoot);
    if(!leftsubtree)
    {

        isSubtree(root->right,subRoot);
    }

    return true;
}

int main() {
    vector<int> rootNodes = {
        1, 2, 4, -1, -1, 5, -1, -1, 3, -1, -1
    };

    idx = -1;
    Node* root = buildTree(rootNodes);

    vector<int> subRootNodes = {
        2, 4, -1, -1, 5, -1, -1
    };

    idx = -1;
    Node* subRoot = buildTree(subRootNodes);

    bool ans = isSubtree(root, subRoot);

    if (ans)
        cout << "true";
    else
        cout << "false";

    return 0;
}
