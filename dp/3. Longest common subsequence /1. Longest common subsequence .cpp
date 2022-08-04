// https://leetcode.com/problems/longest-common-subsequence/
//Memoized version
class Solution {
public:
    int solve(string text1,string text2,int n,int m,int dp[][1001]){
        if(n==0 || m==0) return 0;
        if(dp[n][m]!=-1) return dp[n][m];
        if(text1[n-1]==text2[m-1]){
            return dp[n][m]=1+solve(text1,text2,n-1,m-1,dp);
        }
        return dp[n][m]=max(solve(text1,text2,n-1,m,dp),solve(text1,text2,n,m-1,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int dp[1001][1001];
        int n=text1.size();
        int m=text2.size();
        for(int i=0;i<1001;i++){
            for(int j=0;j<1001;j++){
                dp[i][j]=-1;
            }
        }
        return solve(text1,text2,n,m,dp);
    }
};

// Tabilation top down approach

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        
        int n=text1.size();
        int m=text2.size();
        int dp[n+1][m+1];
        
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0 || j==0){
                    dp[i][j]=0;
                }else if(text1[i-1]==text2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
};