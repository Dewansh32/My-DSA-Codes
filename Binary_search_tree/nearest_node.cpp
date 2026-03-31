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

static int minDiff = INT16_MAX;
static Node* minRoot = NULL;

int nearestNode(Node* root,int k)
{
    if(root == NULL) return INT16_MAX;
    if(abs(root->data - k) < minDiff)
    {
        minDiff = abs(root->data - k);
        minRoot = root;
    }

    if(k>root->data)
    {
        nearestNode(root->right,k);
    }
    else if(k<root->data)
    {
        nearestNode(root->left,k);
    }

    return minRoot->data;

}

int main()
{
    int arr[6] ={8,5,11,3,6,20};

    Node* root = buildBST(arr,6);
    inorder(root);
    cout<<endl;

    cout<<nearestNode(root,19);

    return 0;
}