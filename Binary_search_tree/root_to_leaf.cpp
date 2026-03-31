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

void pathprint(vector<int> path)
{
    cout<<"Path: ";
    for(int i=0;i<path.size();i++)
    {
        cout<<path[i]<<" ";
    }
    cout<<endl;
}

void pathHelper(Node* root,vector<int> &path)
{
    if(root == NULL) return;
    path.push_back(root->data);

    if(root->left==NULL && root->right==NULL)
    {
        pathprint(path);
        path.pop_back();
        return;
    }

    pathHelper(root->left,path);
    pathHelper(root->right,path);

    path.pop_back();
}

void rootToLeaf(Node* root)
{
    vector<int> path;
    pathHelper(root,path);
}

int main()
{
    int arr[9] = {8,5,3,1,4,6,10,11,14};

    Node* root = buildBST(arr,9);
    inorder(root);
    cout<<endl;

    rootToLeaf(root);

    return 0;
}