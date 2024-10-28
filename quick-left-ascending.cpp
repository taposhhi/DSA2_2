#include<bits/stdc++.h>
using namespace std;

int partition(int arr[],int l, int r){
    int pivot=arr[l];
    int i=l;
    int j=r;

   while(i<j){

    while(arr[i]<=pivot && i<=r) i++;
    while(arr[j]>pivot && j>l)  j--;

    if(i<j){
        swap(arr[i],arr[j]);
        i++;
        j--;
    }
   }
   swap(arr[l],arr[j]);
   return j;
}

void quick(int arr[],int l, int r){
    if(l<r){
        int loc=partition(arr,l,r);
        quick(arr,l,loc-1);
        quick(arr,loc+1,r);
    }
}


int main(){
    int arr[]={5,1,4,2,3};

    quick(arr,0,4);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }

}
