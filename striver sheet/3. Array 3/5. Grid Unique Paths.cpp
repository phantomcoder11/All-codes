class Solution {
public:
    //Using Maths combinations
    // int uniquePaths(int m, int n) {
    //     int N=m+n-2;
    //     int r=min(m-1,n-1);
    //     double ans=1;
    //     for(int i=1;i<=r;i++,N--){
    //         ans=ans*N/i;
    //     }
    //     return (int)ans;
    // }
    //Using DP memoization
//     int dp[101][101];
//     int ans(int m, int n,int i,int j){
        
//         if(i>=n||j>=m) return 0;
//         if(i==n-1 && j==m-1) return 1;
//         if(dp[i][j]!=-1) return dp[i][j];
        
        
//         return dp[i][j]=ans(m,n,i+1,j)+ans(m,n,i,j+1);
        
//     }
//      int uniquePaths(int m, int n) {
       
//        memset(dp,-1,sizeof(dp));
//        return ans(m,n,0,0);
//     }
    
    //Using Dp tabulation
    int uniquePaths(int m,int n){
        int dp[m][n];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 || j==0){
                    dp[i][j]=1;
                }
            }
        }
        
        
         for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        
        return dp[m-1][n-1];
    }
};