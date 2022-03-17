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

        for(int i=1;i<num;i++){
            int value=arr[i];
            int j=i;
            while(j>0 && arr[j-1]>value){
                arr[j]=arr[j-1];
                j--;
            }
            arr[j]=value;
        }
        std::cout<<"\nAfter Sort:\n";
        for(int i=0;i<num;i++){
            std::cout<<arr[i]<<' ';
        }
        std::cout<<"\n\n";
    }
}
