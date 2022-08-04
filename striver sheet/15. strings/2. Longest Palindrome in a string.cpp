// https://leetcode.com/problems/longest-palindromic-substring/
//https://leetcode.com/problems/longest-palindromic-substring/discuss/1689129/C%2B%2B-solution-%3A-longest-palindromic-substring-using-the-longest-common-substring
// Aditya Verma Pattern using LCS
class Solution {
public:
    string lps(string a,string b){
        int n=a.length();
        int dp[n+1][n+1];
        int maxlen=0,point=0;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                if(i==0 || j==0) dp[i][j]=0;
                else if(a[i-1]==b[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                    if(maxlen<dp[i][j]){
                        int start=(i-1)-dp[i][j]+1;
                        int end=i-1;
                        int revstart=(j-1)-dp[i][j]+1;
                        int revend=j-1;
                        if(n-1-revend==start && n-1-revstart==end){
                            maxlen=dp[i][j];
                            point=start;
                        }
                    }
                }else dp[i][j]=0;
            }
        }
        return a.substr(point,maxlen);
    }
    string longestPalindrome(string s) {
        string a=s;
        reverse(a.begin(),a.end());
        return lps(s,a);
    }
};