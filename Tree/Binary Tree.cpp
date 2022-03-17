#include<bits/stdc++.h>
class BST
{
public:
    int data;
    BST* left;
    BST* right;
    BST(int data)
    {
        this->data=data;
        this->left=nullptr;
        this->right=nullptr;
    }

    void Inorder(BST* root)
    {
        if(root==nullptr)
        {
            return;
        }
        Inorder(root->left);
        std::cout<<root->data<<" ";
        Inorder(root->right);
    }
    void Preorder(BST* root)
    {
        if(root==nullptr)
        {
            return;
        }
        std::cout<<root->data<<" ";
        Preorder(root->left);
        Preorder(root->right);
    }
    void Postorder(BST* root)
    {
        if(root==nullptr)
        {
            return;
        }
        Postorder(root->left);
        Postorder(root->right);
        std::cout<<root->data<<" ";
    }
};

int main(){
    BST* root=new BST(5);
    root->left=new BST(2);
    root->right=new BST(7);
    root->left->left=new BST(1);
    root->left->right=new BST(3);
    root->right->left=new BST(6);
    root->right->right=new BST(8);
    root->Inorder(root);
    std::cout<<'\n';
    root->Postorder(root);
    std::cout<<'\n';
    root->Preorder(root);
}
