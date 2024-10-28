#include<bits/stdc++.h>
using namespace std;

void ternary(int arr[],int l,int r,int key){
    if(l<=r){
        int m1=l+(r-l)/3;
        int m2=r-(r-l)/3;
        if(key==arr[m1]) cout<<"found at "<<m1<<endl;
        else if(key==arr[m2]) cout<<"found at "<<m2<<endl;

        else if(key<m1){
           ternary(arr,l,m1-1,key);
        }
        else if(key>m2){
           ternary(arr,m2+1,r,key);
        }
        else if(key>m1&&key<m2){
            ternary(arr,m1+1,m2-1,key);
        }
    }
    else cout<<"not found"<<endl;
}


int main(){
     int n,key;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Enter key : ";
    cin>>key;

    int l=0,r=n-1;

    ternary(arr,l,r,key);
    return 0;
}
