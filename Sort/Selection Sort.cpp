#include<bits/stdc++.h>
int main(){
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
        std::cout<<"Before Sort:\n";
        for(int i=0;i<num;i++){
            std::cout<<arr[i]<<' ';
        }

        for(int i=0;i<num-1;i++){
            for(int j=i+1;j<num;j++){
                if(arr[j]<arr[i]){
                    std::swap(arr[i],arr[j]);
                }
            }
        }
        std::cout<<"\nAfter Sort:\n";
        for(int i=0;i<num;i++){
            std::cout<<arr[i]<<' ';
        }
        std::cout<<"\n\n";
    }
}
