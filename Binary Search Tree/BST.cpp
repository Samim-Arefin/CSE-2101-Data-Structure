/*
Created by Samim Arefin on 12/12/2020.
Pabna University of Science & Technology
*/
#include<iostream>
#include "BST.h"
BST* BST::CreateNode(int data) {
    BST *NewNode=new BST;
    NewNode->data=data;
    NewNode->left=NewNode->right=nullptr;
    return NewNode;
}

BST* BST::push(BST *root, int data) {
    if(root==nullptr)
    {
        size++;
        root=CreateNode(data);
        return root;
    }
    if(root->data>data)
    {
        root->left=push(root->left,data);
    }
    else if(root->data<=data)
    {
        root->right=push(root->right,data);
    }
    return root;
}

BST* BST::max(BST *root) {
     if(root==nullptr)
     {
         return nullptr;
     }
     else if(root->right== nullptr)
     {
         return root;
     }
     return max(root->right);
}

BST* BST::min(BST *root) {
     if(root==nullptr)
     {
         return nullptr;
     }
     else if(root->left==nullptr)
     {
         return root;
     }
     return min(root->left);
}

BST* BST::pop(BST *root, int data) {
     if(root==nullptr)
     {
         return nullptr;
     }
     if(root->data>data)
     {
         root->left=pop(root->left,data);
     }
     else if(root->data<data)
     {
         root->right=pop(root->right,data);
     }
     else {
         if (root->left == nullptr && root->right == nullptr)
         {
             size--;
             root = nullptr;
         }
         else if (root->left == nullptr)
         {
             size--;
             root = root->right;
         }
         else if (root->right == nullptr)
         {
             size--;
             root = root->left;
         }
         else
         {
             BST *Node=min(root->right);
             root->data=Node->data;
             root->right=pop(root->right,Node->data);
         }
     }
     return root;
}

bool BST::search(BST *root, int data) {
     if(root==nullptr)
     {
         return false;
     }
     else if(root->data==data)
     {
         return true;
     }
     else if(root->data>data)
     {
         return search(root->left,data);
     }
     else
     {
         return search(root->right,data);
     }
}

void BST::Inorder(BST *root) {
      if(root==nullptr)
      {
          return;
      }
      count++;
      Inorder(root->left);
      if(count==size)
      {
          std::cout<<root->data<<'\n';
      }
      else
      {
          std::cout<<root->data<<" ";
      }
      Inorder(root->right);
}

void BST::Postorder(BST *root) {
      if(root==nullptr)
      {
          return;
      }
      Postorder(root->left);
      Postorder(root->right);
      count++;
      if(count==size)
      {
          std::cout<<root->data<<'\n';
      }
      else
      {
          std::cout<<root->data<<" ";
      }
}

void BST::Preorder(BST *root) {
      if(root==nullptr)
      {
          return;
      }
      count++;
      if(count==size)
      {
          std::cout<<root->data<<'\n';
      }
      else
      {
          std::cout<<root->data<<" ";
      }
      Preorder(root->left);
      Preorder(root->right);
}