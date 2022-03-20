#include<bits/stdc++.h>
#define Max 100
class Heap{
     int tree[Max];
     int size;
 public:
    Heap(){
        size=0;
    }
    void heapify_bottom_to_root(int at){
        int parrent=at/2;
        if(parrent<=0){
            return;
        }else if(tree[at]<tree[parrent]){
            std::swap(tree[at],tree[parrent]);
            heapify_bottom_to_root(parrent);
        }
    }
    void push(int data){
        size++;
        tree[size]=data;
        heapify_bottom_to_root(size);
    }

    void heapify_root_to_bottom(int at){
        int left=at*2;
        int right=at*2+1;
        if(left<=size && tree[left]<=tree[right] && tree[left]<tree[at]){
            std::swap(tree[left],tree[at]);
            heapify_root_to_bottom(left);
        }else if(right<=size && tree[right]<=tree[left] && tree[right]<tree[at]){
            std::swap(tree[at],tree[right]);
            heapify_root_to_bottom(right);
        }
    }
    void pop(){
        if(size==0){
            return;
        }else{
              tree[1]=tree[size];
              tree[size]=INT_MAX;
              heapify_root_to_bottom(1);
              size--;

        }
    }
    int top(){
        if(size==0){
            return -1;
        }else{
            return tree[1];
        }
    }
    void print(){
        for(int i=1;i<=size;i++){
            std::cout<<tree[i]<<" ";
        }
        std::cout<<'\n';
    }
};

int main(){
    Heap hp;
    std::cout<<"Enter Size:\n";
    int s,num;
    std::cin>>s;
    for(int i=1;i<=s;i++){
        std::cin>>num;
        hp.push(num);
    }
    hp.print();
    while(hp.top()!=-1){
        std::cout<<"Top:"<<hp.top()<<'\n';
        hp.pop();
    }
}
