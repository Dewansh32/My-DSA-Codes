#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

class Info{
    public:
    bool isBST;
    int min,max;
    int sz;

    Info(bool isbst,int a,int b,int c)
    {
        isBST = isbst;
        min = a;
        max = b;
        sz = c;
    }
};

static int maxSize = 0;

Info* maxBST(Node* root)
{
    Info* curr = new Info(false,0,0,0);
    if(root == NULL)
    {
        curr->isBST = true;
        curr->min=0;
        curr->max=0;
        curr->sz = 0;
        return curr;
    }

    Info* left = maxBST(root->left);
    Info* right = maxBST(root->right);
    

    if(root->left==NULL && root->right==NULL)
    {
        curr->isBST = left->isBST && right->isBST;
        curr->min = root->data;
        curr->max = root->data;
        curr->sz = 1;
        if(curr->sz > maxSize && curr->isBST) maxSize = curr->sz;
    }
    else if(root->left==NULL)
    {
        curr->isBST = right->isBST && root->data<right->min;
        curr->min = min(root->data,right->min);
        curr->max = max(root->data,right->max);
        curr->sz = right->sz + 1;
        if(curr->sz > maxSize && curr->isBST) maxSize = curr->sz;
    }
    else if(root->right==NULL)
    {
        curr->isBST = left->isBST && root->data>left->max;
        curr->min = min(root->data,left->min);
        curr->max = max(root->data,left->max);
        curr->sz = left->sz + 1;
        if(curr->sz > maxSize && curr->isBST) maxSize = curr->sz;
    }
    else{
        curr->isBST = ((left->isBST && right->isBST) && (root->data<right->min && root->data>left->max));
        curr->min = min(root->data,min(right->min,left->min));
        curr->max = max(root->data,max(right->max,left->max));
        curr->sz = left->sz + right->sz + 1;
        if(curr->sz > maxSize && curr->isBST) maxSize = curr->sz;
    }

    return curr;

}

int main() {
    Node* root = new Node(50);

    root->left = new Node(30);
    root->left->left = new Node(5);
    root->left->right = new Node(20);

    root->right = new Node(60);
    root->right->left = new Node(45);
    root->right->right = new Node(70);
    root->right->right->left = new Node(65);
    root->right->right->right = new Node(80);
    
    maxBST(root);

    cout<<maxSize;

    return 0;
}