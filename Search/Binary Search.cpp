#include<bits/stdc++.h>

bool binarysearch(int arr[],int num,int value){
    int left=0;
    int right=num-1;
    while(left<=right){
        int mid=left+(right-left)/2;
        if(arr[mid]==value){
            return true;
        }
        else if(arr[mid]>value){
            right=mid-1;
        }else{
            left=mid+1;
        }
    }
    return false;
}

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
        std::sort(arr,arr+num);
        int s;
        std::cout<<"Enter Number:\n";
        std::cin>>s;
        if(binarysearch(arr,num,s)==true){
            std::cout<<"Found\n\n";
        }else{
            std::cout<<"Not Found\n\n";
        }
    }
}
