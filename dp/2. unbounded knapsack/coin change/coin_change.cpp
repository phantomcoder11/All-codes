// { Driver Code Starts
//For detailed exp look my notebook
//https://practice.geeksforgeeks.org/problems/coin-change2448/1
//https://leetcode.com/problems/coin-change-2/
#include <bits/stdc++.h>
using namespace std;
//1d dp
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int dp[amount+1];
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for(int i=0;i<coins.size();i++){
            for(int j=coins[i];j<=amount;j++){
                dp[j]=dp[j]+dp[j-coins[i]];
            }
        }
        return dp[amount];
    }
};

//2d dp

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
       int dp[n+1][amount+1];
      
        for(int i=0;i<=n;i++){
            for(int j=0;j<=amount;j++){
                if(j==0) dp[i][j]=1;
                else if(i==0) dp[i][j]=0;
                else if(coins[i-1]<=j){
                    
                     dp[i][j]=dp[i-1][j]+dp[i][j-coins[i-1]];
                }else{
                     dp[i][j]=dp[i-1][j];
                }
            }
        }
    
        return dp[n][amount];
    }
};