// https://leetcode.com/problems/edit-distance/

// Memoized  Code
class Solution {
public:
    int dp[501][501];
    int solve(string &a,string &b,int i,int j){
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(a[i]==b[j]) return dp[i][j]=solve(a,b,i-1,j-1);
        int insert=1+solve(a,b,i,j-1);
        int del=1+solve(a,b,i-1,j);
        int replace=1+solve(a,b,i-1,j-1);
        return dp[i][j]=min(insert,min(del,replace));
    }
    int minDistance(string word1, string word2) {
        memset(dp,-1,sizeof(dp));
        return solve(word1,word2,word1.length()-1,word2.length()-1);
    }
};

// Tabulation
class Solution {
public:
    int minDistance(string word1, string word2) {
       int m=word1.length();
        int n=word2.length();
        int dp[m+1][n+1];
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(i==0){
                    dp[i][j]=j;
                }else if(j==0) dp[i][j]=i;
                else if(word1[i-1]==word2[j-1]) dp[i][j]=dp[i-1][j-1];
                else{
                    dp[i][j]=1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
                }
            }
        }
        return dp[m][n];
    }
};