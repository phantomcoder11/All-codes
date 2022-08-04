class Solution {
public:
    int lcs(string word1, string word2){
        int dp[word1.length()+1][word2.length()+1];
        for(int i=0;i<=word1.length();i++){
            for(int j=0;j<=word2.length();j++){
                if(i==0 || j==0) dp[i][j]=0;
            else if(word1[i-1]==word2[j-1]) dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[word1.length()][word2.length()];
    }
    int minDistance(string word1, string word2) {
        return word1.length()+word2.length()-2*lcs(word1,word2);
    }
};