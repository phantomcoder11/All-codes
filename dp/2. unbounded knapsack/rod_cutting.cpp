// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// This question is basically a modification of the unbounded knapsack problem. 
// here the weight array is replaced by the length array. we ourselves made that array
// The price array may be considered as the value array. And the rest is same
class Solution{
  public:
    int cutRod(int price[], int n) {
        //code here
        //Space Complexity: O(n*n)
        int num[n];
        for(int i=0;i<n;i++){
            num[i]=i+1;
        }
        
        int dp[n+1][n+1];
        
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                if(i==0||j==0) dp[i][j]=0;
                else{
                    if(num[i-1]>j){
                      dp[i][j]=dp[i-1][j];
                    }else{
                      dp[i][j]=max(price[i-1]+dp[i][j-num[i-1]],dp[i-1][j]);
                    }
                }
            }
        }
        return dp[n][n];
    }
};
// Space optimized O(n) approach
class Solution{
  public:
    int cutRod(int price[], int n) {
        //code here
        int dp[n+1];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<=n;i++){
            for(int j=0;j<n;j++){
                if(j+1<=i){
                    dp[i]=max(dp[i],dp[i-j-1]+price[j]);
                }
            }
        }
        return dp[n];
    }
};

