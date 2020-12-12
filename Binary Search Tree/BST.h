/*
Created by Samim Arefin on 12/12/2020.
Pabna University of Science & Technology
*/
#ifndef BINARY_SEARCH_TREE_BST_H
#define BINARY_SEARCH_TREE_BST_H

class BST {
int data;
BST *left;
BST *right;
int size{0};
int count{0};
public:

    int GetData() const
    {
        return data;
    }

    BST* CreateNode(int data);
    BST* push(BST *root,int data);
    bool search(BST *root,int data);
    BST* max(BST *root);
    BST* min(BST *root);
    BST* pop(BST *root,int data);
    void Postorder(BST *root);
    void Preorder(BST *root);
    void Inorder(BST *root);

    void InorderPrint(BST *root)
    {
        count=0;
        Inorder(root);
    }

    void PreorderPrint(BST *root)
    {
        count=0;
        Preorder(root);
    }

    void PostorderPrint(BST *root)
    {
        count=0;
        Postorder(root);
    }


};


#endif //BINARY_SEARCH_TREE_BST_H
