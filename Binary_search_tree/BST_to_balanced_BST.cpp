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

void inorder(Node* root,vector<int> &arr)
{
    if(root == NULL) return;

    inorder(root->left,arr);
    arr.push_back(root->data);
    inorder(root->right,arr);
}

Node* buildBST(vector<int> arr,int st,int end)
{
    if(st>end) return NULL;
    int mid = (st + end)/2;
    
    Node* root = new Node(arr[mid]);

    root->left = buildBST(arr,st,mid-1);
    root->right = buildBST(arr,mid+1,end);

    return root;
}

void preorder(Node* root)
{
    if(root == NULL) return;

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}





int main() {
    Node* root = new Node(6);

    root->left = new Node(5);
    root->left->left = new Node(4);
    root->left->left->left = new Node(3);

    root->right = new Node(7);
    root->right->right = new Node(8);
    root->right->right->right = new Node(9);
    preorder(root);
    cout<<endl;

    vector<int> arr;
    inorder(root,arr);

    root = buildBST(arr,0,arr.size()-1);
    preorder(root);
    cout<<endl;
    return 0;
}