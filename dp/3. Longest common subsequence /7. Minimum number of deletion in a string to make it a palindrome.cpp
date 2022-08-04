// https://practice.geeksforgeeks.org/problems/minimum-number-of-deletions4610/1/

int lps(string a,string b){
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
int minDeletions(string str, int n) { 
    //complete the function here 
    string a=str;
    reverse(a.begin(),a.end());
    return n-lps(str,a);
} 