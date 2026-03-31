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

bool validateHelper(Node* root,Node* min,Node* max)
{
    if(root == NULL) return true;

    if(min!=NULL && min->data>root->data)
    {
        return false;
    }

    if(max!=NULL && max->data<root->data)
    {
        return false;
    }

    bool BST_left = validateHelper(root->left,min,root);
    bool BST_right = validateHelper(root->right,root,max);

    if(BST_left && BST_right)
    {
        return true;
    }else{
        return false;
    }

}

bool validateBST(Node* root)
{
    return validateHelper(root,NULL,NULL);
}

int main()
{
    int arr[9] = {8,5,3,1,4,6,10,11,14};

    Node* root = buildBST(arr,9);
    inorder(root);
    cout<<endl;

    cout<<(validateBST(root) ? "Valid BST" : "Inavlid BST");

    return 0;
}