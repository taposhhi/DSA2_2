#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,key;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Enter key : ";
    cin>>key;
    int l=0,r=n-1,mid;
    while(l<=r){
        mid=l+(r-l)/2;
        if(arr[mid]==key){
            cout<<"found at "<< mid<<endl;
    return 0;
        }
        else if(key<arr[mid]){
            r=mid-1;
        }
         else if(key>arr[mid]){
            l=mid+1;
        }
    }
    cout<<"Not found";
}
