#include<iostream>
template<typename T>
class List{
    T data;
    List<T>* next;
public:
    void setData(T data){
        this->data=data;
    }
    T getData(){
        return data;
    }
    void setNext(List<T>* next){
        this->next=next;
    }
    List<T>* getNext(){
        return next;
    }
};

template<typename T>
class stack{
    List<T>* head;
    int Size;
public:
    stack(){
        head=nullptr;
        Size=0;
    }
    void push(T data){
        List<T>* Node=new List<T>;
        Node->setData(data);
        Node->setNext(nullptr);
        if(head==nullptr){
            head=Node;
            Size++;
        }else{
            Node->setNext(head);
            head=Node;
            Size++;
        }
    }
    void pop()
    {
        if (empty()){
            return;
        }
        else{
            List<T>* Node=head;
            head=head->getNext();
            delete Node;
            Size--;
        }
    }
    bool empty(){
        if(head==nullptr){
            return true;
        }else{
            return false;
        }
    }
    T top(){
        return head->getData();
    }
    int size(){
        return Size;
    }
};

bool isOperand(char ch){
    if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z')){
        return true;
    }else{
        return false;
    }
}

std::string PostfixtoPrefix(std::string Postfix){
    stack<std::string>s;
    for(int i=0;i<Postfix.size();i++){
        if(isOperand(Postfix[i])){
            std::string str(1,Postfix[i]);
            s.push(str);
        }else{
            std::string str1=s.top();
            s.pop();
            std::string str2=s.top();
            s.pop();
            std::string Prefix=Postfix[i]+str2+str1;
            s.push(Prefix);
        }
    }
    return s.top();
}

int main(){
   std::string Postfix;
   std::cin>>Postfix;
   std::cout<<PostfixtoPrefix(Postfix)<<'\n';
}
