#include<bits/stdc++.h>
int main()
{
    int test;
    std::cout<<"Enter Test Case:\n";
    std::cin>>test;
    while(test--)
    {

        int num;
        std::cout<<"Enter Array Size:\n";
        std::cin>>num;
        int arr[num];
        std::cout<<"Enter Array Elements:\n";
        for(int i=0; i<num; i++)
        {
            std::cin>>arr[i];
        }
        bool check=false;
        int s;
        std::cout<<"Enter Number:\n";
        std::cin>>s;
        for(int i=0; i<num; i++)
        {
            if(arr[i]==s)
            {
                check=true;
                break;
            }
        }
        if(check==true)
        {
            std::cout<<"Found\n\n";
        }
        else
        {
            std::cout<<"Not Found\n\n";
        }
    }
}
