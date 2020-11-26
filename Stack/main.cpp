#include "stack.h"
#include <iostream>

int main() {
    stack s;
    s.push ('m');
    s.push('i');
    s.push('m');
    s.push('a');
    s.push('S');

    std::cout<<"Size of Stack: "<<s.size()<<'\n';

    s.push('#');

    std::cout<<"\nSize of Stack: "<<s.size()<<'\n';

    s.pop();

    std::cout<<"\nTop of Stack: "<<s.top()<<'\n';

    while(!s.empty())
    {
        std::cout<<s.top();
        s.pop();
    }
    std::cout<<'\n';

    return 0;
}
