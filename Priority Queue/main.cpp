#include "queue.cpp"
#include <iostream>

int main() {

    queue<int>q;

    q.push(5,1);

    std::cout<<"Priority Queue Size: " <<q.size()<<'\n';

    q.push(20,2);
    q.push(10,0);

    std::cout<<"\nTop of Priority Queue: "<<q.top()<<'\n';

    q.push(15,1);
    q.push(100,4);
    q.push(25,3);
    q.push(50,5);

    std::cout<<"\nPriority Queue Size: " <<q.size()<<'\n';

    int count=1,size=q.size();
    while(!q.empty())
    {
        std::cout<<q.top();
        if(count<size)
        {
            std::cout<<" ";
        }
        q.pop();
    }


    return 0;
}
