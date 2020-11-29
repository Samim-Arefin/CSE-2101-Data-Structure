#include "stack.cpp"
#include <iostream>

int main() {
    stack<std::string>s;

    std::cout<<"Size of Stack: "<<s.size()<<'\n';

    s.push("Arefin");

    s.push("Sheikh");

    std::cout<<"Top of Stack: "<<s.top()<<'\n';

    s.pop();

    s.push("Samim");

    int count=1,size=s.size();

    while(!s.empty())
    {
        std::cout<<s.top();
        if(count<size)
        {
            std::cout<<" ";
        }
        s.pop();
        count++;
    }

    std::cout<<'\n';

    return 0;
}
