// it is a type of tree where elements lesser than root are on its left and greater are on its right
//and it is applicable to all nodes in the tree
// inorder of a BST is always in ascending order

//complexity - O(logN)

#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int val){
        data= val;
        left=NULL;
        right=NULL;
    }
};
void inOrder(node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}
node* InsertBST(node* root, int val){

    if(root==NULL){
        return new node(val);
    }
    if(val< root->data){
        root->left= InsertBST(root->left,val);
    }else{
        //when val< root->val
        root->right= InsertBST(root->right,val);
    }
    return root;
}
node* minVal(node* root){
    node* temp =root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp;
}
node* maxVal(node* root){
    node* temp =root;
    while(temp->right!=NULL){
        temp=temp->right;
    }
    return temp;
}

int main()
{
    node* root=NULL;
    root= InsertBST(root,5);
    InsertBST(root,1);
    InsertBST(root,3);
    InsertBST(root,4);
    InsertBST(root,2);
    InsertBST(root,7);

    inOrder(root);

    return 0;
}