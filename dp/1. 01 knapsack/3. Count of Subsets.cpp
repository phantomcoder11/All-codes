#include <bits/stdc++.h>
using namespace std;
int solve(vector<int>&arr,int n,int sum){
    int dp[n+1][sum+1];
    for(int i=0;i<=sum;i++) dp[0][i]=0;
    dp[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=sum;j++){
            if(arr[i-1]<=j) dp[i][j]=dp[i-1][j]+dp[i-1][j-arr[i-1]];
            else dp[i][j]=dp[i-1][j-arr[i-1]];
        }
    }
    
    return dp[n][sum];
}
int main()
{
    int n;
    cin>>n;
    int sum;
    cin>>sum;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<solve(arr,n,sum);
    return 0;
}