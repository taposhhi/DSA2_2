
#include<bits/stdc++.h>
using namespace std;

void knapsack(int wt[],int val[],int n,int c){
     int dp[n+1][c+1];
    int i,j,k;
    for(i=0;i<=n;i++){
        for(j=0;j<=c;j++){
            if(i==0 || j==0) dp[i][j]=0;
            else if(j<wt[i-1]) {
                dp[i][j]=dp[i-1][j];
            }
            else {
                    int u=wt[i-1];
                    dp[i][j]=max(dp[i-1][j],dp[i-1][j-u]+val[i-1]);
            }
        }
    }


    cout<<"Table"<<endl;
    for(i=0;i<=n;i++){
        for(j=0;j<=c;j++){
            cout<<dp[i][j]<<'\t';
        }
        cout<<'\n';
    }

    i=n,j=c;
    while(i>0 && j>0){
        if(dp[i][j]==dp[i-1][j]) i--;
        else{
            cout<<"item is : "<<i<<" and value is : "<<val[i-1]<<endl;
            j=j-wt[i-1];
            i--;
        }
    }
}

int main(){
    int val[]={150,180,170,350,300};
    int wt[]={3,2,3,6,5};
    int n=5;
    int cap=7;

    knapsack(wt,val,n,cap);
}
