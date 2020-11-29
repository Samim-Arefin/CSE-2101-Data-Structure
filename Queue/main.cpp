#include "queue.cpp"
#include <iostream>

int main() {
    queue<std::string>q;

    q.push("Hello");

    std::cout<<q.front()<<'\n';

    q.pop();

    std::cout<<"Size of Queue: "<<q.size()<<'\n';

    q.push("Samim");
    q.push("Arefin");
    q.push("Sheikh");

    std::cout<<"\nFront of Queue: "<<q.front()<<'\n';
    std::cout<<"\nBack of Queue: "<<q.back()<<'\n';

    int count=1,size=q.size();

    while(!q.empty())
    {
        std::cout<<q.front();
        if(count<size)
        {
            std::cout<<" ";
        }
        q.pop();
        count++;
    }

    std::cout<<'\n';



    return 0;
}
