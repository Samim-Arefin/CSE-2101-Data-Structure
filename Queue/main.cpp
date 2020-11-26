#include "queue.h"
#include <iostream>

int main() {
    queue q;

    q.push('#');

    std::cout<<"Size of Queue: "<<q.size()<<'\n';

    q.pop();

    q.push('S');
    q.push('a');
    q.push('m');
    q.push('i');
    q.push('m');

    std::cout<<"\nSize of Queue: "<<q.size()<<'\n';

    std::cout<<"\nFront of Queue: "<<q.front()<<'\n';

    std::cout<<"Back of Queue: "<<q.back()<<'\n';

    while(!q.empty())
    {
        std::cout<<q.front();
        q.pop();
    }
    std::cout<<'\n';

    return 0;
}
