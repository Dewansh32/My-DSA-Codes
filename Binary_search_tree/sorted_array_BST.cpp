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

void inorder(Node* root)
{
    if(root == NULL) return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

Node* buildBST(int arr[],int st,int end)
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

int main()
{
    int arr[7] = {3,4,5,6,7,8,9};

    Node* root = buildBST(arr,0,6);
    preorder(root);

    return 0;
}