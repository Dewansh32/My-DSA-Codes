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

void printinrange(Node* root,int start,int end)
{
    if(root == NULL) return;

    if(root->data>=start && root->data <= end)
    {
        printinrange(root->left,start,end);
        cout<<root->data<<" ";
        printinrange(root->right,start,end);
    }
    
    if(start>root->data)
    {
        printinrange(root->right,start,end);
        
    }
    else if(root->data>end)
    {
        printinrange(root->left,start,end);
    }

    return;

}

int main()
{
    int arr[9] = {8,5,3,1,4,6,10,11,14};

    Node* root = buildBST(arr,9);
    inorder(root);
    cout<<endl;

    printinrange(root,5,12);

    return 0;
}