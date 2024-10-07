// complexitry to delete
//best case- o(h) , wordt case- o(n)

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
node* DeletioninBST(node* root, int val){

    //base case
    if(root==NULL){
        return root;
    }
    if(root->data==val){
        // 0 child
        if(root->left==NULL and root->right==NULL){
        delete root;
        return NULL;
        }
        // 1 child 
            // if child is on left
        if(root->left!=NULL and root->right==NULL){
            node* temp = root->left;
            delete root;
            return temp;
        }
            // if child is on right
        if(root->left==NULL and root->right!=NULL){
            node* temp = root->right;
            delete root;
            return temp;
        }        

        // 2 child
        if(root->left!=NULL and root->right!=NULL){
            // find minimum valude in right subtree (inorder presesessor)
            // int mini= minVal(root->right)->data;
            // root->data= mini;
            // root->right= DeletioninBST(root->right,mini);
            // return root;
            
            // by using inorder successor

            int maxx= maxVal(root->left)->data;
            root->left= DeletioninBST(root->left,maxx);
            return root;
            
        }

    }else if(root->data>val){
        root->left= DeletioninBST(root->left,val);
        return root;
    }
        root->right= DeletioninBST(root->right,val);
         return root;
    
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
    cout<<endl;
    DeletioninBST(root, 1);
    inOrder(root);
    return 0;
}