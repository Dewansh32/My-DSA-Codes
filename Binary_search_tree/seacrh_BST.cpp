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

Node* insert(Node* root,int val)
{
    if(root == NULL) 
    {
        root = new Node(val);
        return root;
    }

    if(val>root->data)
    {
        root->right = insert(root->right,val);
       
    }
    else{
        root->left = insert(root->left,val);
    }

    return root;
}

void inorder(Node* root)
{
    if(root == NULL) return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

Node* buildBST(int arr[],int n)
{
    Node* root = NULL;
    for(int i=0;i<n;i++)
    {
        root = insert(root,arr[i]);
    }

    return root;
}

bool search(Node* root,int key)
{
    if(root == NULL) return false;

    if(root->data == key)
    {
        return true;
    }

    if(root->data > key)
    {
        return search(root->left,key);
    }
    else{
        return search(root->right,key);
    }
}

int main()
{
    int arr[6] = {5,1,3,4,2,7};

    Node* root = buildBST(arr,6);
    int key = 4;
    cout<<search(root,key);

    return 0;
}