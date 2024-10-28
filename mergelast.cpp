#include<bits/stdc++.h>
using namespace std;

void combine(int arr[],int l, int mid , int r){
    int i=l;
    int j=mid+1;
    int temp[r-l+1];
    int k=0;
    while(i<=mid &&j<=r){
        if(arr[i]<=arr[j]){
            temp[k]=arr[i];
            i++;
        }
        else {
            temp[k]=arr[j];
            j++;
        }
        k++;
    }

    while(i<=mid){
        temp[k]=arr[i];
        i++;
        k++;
    }
    while(j<=r){
        temp[k]=arr[j];
        j++;
        k++;
    }

    int t=0;
    for(i=l;i<=r;i++){
        arr[i]=temp[t];
        t++;
    }

}


void mergesort(int arr[],int l, int r){
    if(l<r){
        int mid=l+(r-l)/2;

        mergesort(arr,l,mid);
        mergesort(arr,mid+1,r);

        combine(arr,l,mid,r);
    }
}

int main(){
    int arr[]={5 ,1 , 4, 2, 3};

    mergesort(arr,0,4);
    for(int i=0;i<=4;i++){
        cout<<arr[i]<<endl;
    }
    return 0;
}
