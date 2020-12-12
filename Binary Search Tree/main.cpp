#include "BST.h"
#include <iostream>

int main() {
    BST bst;
    BST* root=nullptr;

    std::cout<<"Enter Binary Search Tree Size:";
    int size;
    std::cin>>size;

    for(int i=0;i<size;i++)
    {
        int num;
        std::cin>>num;
        root=bst.push(root,num);
    }


    std::cout<<"\nInorder Traversal:";
    bst.InorderPrint(root);
    std::cout<<'\n';
    std::cout<<"Preorder Traversal:";
    bst.PreorderPrint(root);
    std::cout<<'\n';
    std::cout<<"Postorder Traversal:";
    bst.PostorderPrint(root);
    std::cout<<'\n';


    BST *min=bst.min(root);
    if(min!=nullptr)
    {
        std::cout<<"Minimum Value in BST:"<<min->GetData()<<'\n';
    }
    else
    {
        std::cout<<"Tree is empty\n";
    }


    BST *max=bst.max(root);
    if(max!=nullptr)
    {
        std::cout<<"\nMaximum Value in BST:"<<max->GetData()<<'\n';
    }
    else
    {
        std::cout<<"\nTree is empty\n";
    }


    std::cout<<"\nEnter a number you want to search:\n";
    int num;
    std::cin>>num;
    if(bst.search(root,num))
    {
        std::cout<<"\nFound";
    }
    else
    {
        std::cout<<"\nNot Found!!";
    }


    std::cout<<"\n\nEnter a number you want to delete:\n";
    int temp;
    std::cin>>temp;
    root=bst.pop(root,temp);


    std::cout<<"\nInorder Traversal:";
    bst.InorderPrint(root);
    std::cout<<'\n';
    std::cout<<"Preorder Traversal:";
    bst.PreorderPrint(root);
    std::cout<<'\n';
    std::cout<<"Postorder Traversal:";
    bst.PostorderPrint(root);
    std::cout<<'\n';

    return 0;
}

//First Input
/*
Enter Binary Search Tree Size:5
50 25 75 5 10

Inorder Traversal:5 10 25 50 75

Preorder Traversal:50 25 5 10 75

Postorder Traversal:10 5 25 75 50

Minimum Value in BST:5

Maximum Value in BST:75

Enter a number you want to search:
25

Found

Enter a number you want to delete:
5

Inorder Traversal:10 25 50 75

Preorder Traversal:50 25 10 75

Postorder Traversal:10 25 75 50

 */



//Second Input
/*
Enter Binary Search Tree Size:9
50 25 75 5 10 60 80 77 85

Inorder Traversal:5 10 25 50 60 75 77 80 85

Preorder Traversal:50 25 5 10 75 60 80 77 85

Postorder Traversal:10 5 25 60 77 85 80 75 50

Minimum Value in BST:5

Maximum Value in BST:85

Enter a number you want to search:
100

Not Found!!

Enter a number you want to delete:
75

Inorder Traversal:5 10 25 50 60 77 80 85

Preorder Traversal:50 25 5 10 77 60 80 85

Postorder Traversal:10 5 25 60 85 80 77 50

 */