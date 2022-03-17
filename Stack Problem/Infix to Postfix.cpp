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

bool isoperator(char ch){
    if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^'){
        return true;
    }else{
        return false;
    }
}

int precedence(char ch){
    if(ch=='+' || ch=='-'){
        return 1;
    }else if(ch=='*' || ch=='/'){
        return 2;
    }else if(ch=='^'){
        return 3;
    }else{
        return -1;
    }
}

std::string InfixToPostfix(std::string Infix){
    std::string Postfix;
    stack<char>s;
    for(int i=0;i<Infix.size();i++){
        if(isalpha(Infix[i]) || isdigit(Infix[i])){
            Postfix+=Infix[i];
        }else if(Infix[i]=='('){
               s.push(Infix[i]);
        }else if(Infix[i]==')'){
            while(s.top()!='(')
            {
                Postfix+=s.top();
                s.pop();
            }
            if(s.top()=='('){
                s.pop();
               }
        }else if(isoperator(Infix[i])){
            if(s.empty()){
                s.push(Infix[i]);
            }else{
                if(precedence(Infix[i])>precedence(s.top())){
                    s.push(Infix[i]);
                }else if(precedence(Infix[i])==precedence(s.top()) && Infix[i]=='^'){
                    s.push(Infix[i]);
                }else{
                    while((!s.empty() && precedence(Infix[i])<=precedence(s.top()))){
                         Postfix+=s.top();
                         s.pop();
                    }
                    s.push(Infix[i]);
                }
            }
        }
    }
    if(!s.empty()){
        while(!s.empty()){
            Postfix+=s.top();
            s.pop();
        }
    }
    return Postfix;
}

int main(){
    std::string str;
    std::cin>>str;
    std::cout<<InfixToPostfix(str)<<'\n';
}
