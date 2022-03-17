#include<bits/stdc++.h>
int partition(int arr[],int start,int end){
     int pivot=arr[end];
     int pindex=start;
     for(int i=start;i<end;i++){
        if(arr[i]<=pivot){
            std::swap(arr[pindex],arr[i]);
            pindex++;
        }
     }
     std::swap(arr[end],arr[pindex]);
     return pindex;
}

void quicksort(int arr[],int start,int end)
{
    if(start>end)
    {
        return;
    }
    int pindex=partition(arr,start,end);
    quicksort(arr,start,pindex-1);
    quicksort(arr,pindex+1,end);
}
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
        quicksort(arr,0,num-1);
        std::cout<<"\nAfter Sort:\n";
        for(int i=0;i<num;i++){
            std::cout<<arr[i]<<' ';
        }
        std::cout<<"\n\n";
    }

}
