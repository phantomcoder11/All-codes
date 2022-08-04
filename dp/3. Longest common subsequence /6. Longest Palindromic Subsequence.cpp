// https://leetcode.com/problems/longest-palindromic-subsequence/
class Solution {
public:
    int lcs(string a,string b){
        int dp[a.length()+1][b.length()+1];
        for(int i=0;i<=a.length();i++){
            for(int j=0;j<=b.length();j++){
                if(i==0||j==0){
                    dp[i][j]=0;
                }else if(a[i-1]==b[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[a.length()][b.length()];
    }
    int longestPalindromeSubseq(string s) {
        string a=s;
        reverse(a.begin(),a.end());
        return lcs(s,a);
    }
};