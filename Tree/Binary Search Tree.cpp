#include<bits/stdc++.h>
class Node{
     int data;
     Node* left;
     Node* right;
 public:
    void setData(int data){
         this->data=data;
    }
    int getData(){
         return data;
    }
    void setLeft(Node* left){
          this->left=left;
    }
    Node* getLeft(){
          return left;
    }
    void setRight(Node* right){
          this->right=right;
    }
    Node* getRight(){
          return right;
    }
};

class BST{
    Node* root;
    int Size;
public:
    BST(){
      root=nullptr;
      Size=0;
    }
    Node* Insert(Node* root,int data){
         if(root==nullptr){
            Node* node=new Node;
            node->setData(data);
            node->setLeft(nullptr);
            node->setRight(nullptr);
            root=node;
            return root;
         }else if(root->getData()>data){
            root->setLeft(Insert(root->getLeft(),data));
         }else{
            root->setRight(Insert(root->getRight(),data));
         }
         return root;
    }
    void push(int data){
        Size++;
        root=Insert(root,data);
    }
    void InorderPrint(Node* root){
        if(root==nullptr){
            return;
        }
        InorderPrint(root->getLeft());
        std::cout<<root->getData()<<" ";
        InorderPrint(root->getRight());
    }
    void Inorder(){
         InorderPrint(root);
    }
    void PostOrderPrint(Node* root){
        if(root==nullptr){
            return;
        }
        PostOrderPrint(root->getLeft());
        PostOrderPrint(root->getRight());
        std::cout<<root->getData()<<" ";
    }
    void Postorder(){
         PostOrderPrint(root);
    }
    void PreOrderPrint(Node* root){
        if(root==nullptr){
            return;
        }
        std::cout<<root->getData()<<" ";
        PreOrderPrint(root->getLeft());
        PreOrderPrint(root->getRight());
    }
    void Preorder(){
         PreOrderPrint(root);
    }
    Node* MaxElement(Node* root){
          if(root==nullptr){
            return nullptr;
          }else if(root->getRight()==nullptr){
              return root;
          }
          return MaxElement(root->getRight());
    }
    void Max(){
       Node* max=MaxElement(root);
       if(max==nullptr){
        std::cout<<"Tree is empty\n";
       }else{
        std::cout<<max->getData()<<'\n';
       }
    }
    Node* MinElement(Node* root){
          if(root==nullptr){
            return nullptr;
          }else if(root->getLeft()==nullptr){
              return root;
          }
          return MinElement(root->getLeft());
    }
    void Min(){
       Node* min=MinElement(root);
       if(min==nullptr){
        std::cout<<"Tree is empty\n";
       }else{
        std::cout<<min->getData()<<'\n';
       }
    }

    bool SearchElement(Node* root,int data){
         if(root==nullptr){
            return false;
         }else if(root->getData()==data){
            return true;
         }else if(root->getData()>data){
            return SearchElement(root->getLeft(),data);
         }else{
            return SearchElement(root->getRight(),data);
         }
    }
    void search(int data){
        if(SearchElement(root,data)){
            std::cout<<"Element Found\n";
        }else{
            std::cout<<"Element Not Found!\n";
        }
    }
    Node* Delete(Node* root,int data){
         if(root==nullptr){
            return nullptr;
         }else if(root->getData()>data){
            root->setLeft(Delete(root->getLeft(),data));
         }else if(root->getData()<data){
            root->setRight(Delete(root->getRight(),data));
         }else{
             if(root->getLeft()==nullptr && root->getRight()==nullptr){
                Size--;
                root=nullptr;
             }else if(root->getLeft()==nullptr){
                root=root->getRight();
             }else if(root->getRight()==nullptr){
                root=root->getLeft();
             }else{
                Node* node=MinElement(root->getRight());
                root->setData(node->getData());
                root->setRight(Delete(root->getRight(),node->getData()));
             }
         }
         return root;
    }
    void pop(int data){
        if(root==nullptr){
            std::cout<<"Tree is Empty\n";
        }else{
            root=Delete(root,data);
        }
    }
};
int main(){
    BST bst;
   // bst.push(47);
    bst.push(40);
    bst.push(54);
    bst.push(38);
    bst.push(43);
    bst.push(49);
    bst.push(70);
    bst.push(59);
    bst.push(30);
    bst.push(39);
    bst.push(41);
    bst.push(46);
    bst.push(44);
    bst.push(47);
    bst.push(45);
    bst.Inorder();
    std::cout<<'\n';
    bst.Postorder();
    std::cout<<'\n';
    bst.Preorder();
    std::cout<<'\n';
    bst.Max();
    bst.Min();
    bst.search(30);
    bst.search(10);
    bst.pop(39);
    bst.Inorder();
    std::cout<<'\n';
    bst.pop(70);
    bst.Inorder();
    std::cout<<'\n';
    bst.pop(43);
    bst.Inorder();
    std::cout<<'\n';
}
