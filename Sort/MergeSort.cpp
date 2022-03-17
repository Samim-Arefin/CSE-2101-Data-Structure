#include<bits/stdc++.h>

void mergeArray(int arr[],int left,int mid,int right){
    int Left_SubArraySize=mid-left+1;
    int Right_SubArraySize=right-mid;
    int LeftArray[Left_SubArraySize],RightArray[Right_SubArraySize];

    for(int i=0;i<Left_SubArraySize;i++){
        LeftArray[i]=arr[i+left];
    }

    for(int i=0;i<Right_SubArraySize;i++){
        RightArray[i]=arr[i+mid+1];
    }

    int IndexofLeftArray=0,IndexofRightArray=0,Index=left;

    while(Left_SubArraySize>IndexofLeftArray && Right_SubArraySize>IndexofRightArray){
        if(LeftArray[IndexofLeftArray]<=RightArray[IndexofRightArray]){
            arr[Index]=LeftArray[IndexofLeftArray];
            IndexofLeftArray++;
        }else{
            arr[Index]=RightArray[IndexofRightArray];
            IndexofRightArray++;
        }
        Index++;
    }

    while(Left_SubArraySize>IndexofLeftArray){
        arr[Index]=LeftArray[IndexofLeftArray];
        Index++;
        IndexofLeftArray++;
    }

    while(Right_SubArraySize>IndexofRightArray){
        arr[Index]=RightArray[IndexofRightArray];
        Index++;
        IndexofRightArray++;
    }
}

void mergeSort(int arr[],int left,int right){
    if(left<right){
        int mid=left+(right-left)/2;
        mergeSort(arr,left,mid);
        mergeSort(arr,mid+1,right);
        mergeArray(arr,left,mid,right);
    }
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

        mergeSort(arr,0,num-1);
        std::cout<<"\nAfter Sort:\n";
        for(int i=0;i<num;i++){
            std::cout<<arr[i]<<' ';
        }
        std::cout<<"\n\n";
    }
}
