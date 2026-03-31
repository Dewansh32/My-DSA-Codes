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

Node* getInorderSuccessor(Node* root)
{
    while(root->left != NULL)
    {
        root = root->left;
    }

    return root;
}

Node* delNode(Node* root,int val)
{
    if(root == NULL) return NULL;

    if(val<root->data)
    {
        root->left = delNode(root->left,val);
    }
    else if(val>root->data)
    {
        root->right = delNode(root->right,val);
    }
    else
    {
        // case1: if root->left && root->right == NULL
        if(root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

        //case2: 1 child
        if(root->left == NULL || root->right == NULL)
        {
            return root->left == NULL ? root->right : root->left;
        }

        //case3: root has two children
        Node* IS = getInorderSuccessor(root->right);
        root->data = IS->data;

        root->right = delNode(root->right,IS->data);
        return root;
    }
    return root;
}

int main()
{
    int arr[9] = {8,5,3,1,4,6,10,11,14};

    Node* root = buildBST(arr,9);
    
    inorder(root);
    cout<<endl;

    delNode(root,5);

    inorder(root);
    cout<<endl;

    return 0;
}