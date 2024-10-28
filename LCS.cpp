#include<bits/stdc++.h>
using namespace std;

void lcs(string s1,string s2,int m,int n){
    int dp[m+1][n+1];
    int i,j,k;

    for(i=0;i<=m;i++){
        for(j=0;j<=n;j++){
                if(i==0 ||j==0) dp[i][j]=0;
                else if(s1[i-1]==s2[j-1]) dp[i][j]=dp[i-1][j-1]+1;
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }

    cout<<"Length is "<<dp[m][n]<<endl;
    int l=dp[m][n];
    char arr[l+1];
    arr[l]='\0';

    k=l-1;
    i=m,j=n;

    while(i>0 &&j>0){
        if(dp[i][j]==dp[i-1][j]) i--;
        else if(dp[i][j]==dp[i][j-1])  j--;
        else{
            arr[k]=s1[i-1];
            k--;
            i--;
            j--;
        }
    }
    cout<<arr<<endl;
}


int main(){
    string s1="ACGTCCGCTCG";
    string s2="ATCTCT";

    int m=s1.size();
    int n=s2.size();

    lcs(s1,s2,m,n);
}
