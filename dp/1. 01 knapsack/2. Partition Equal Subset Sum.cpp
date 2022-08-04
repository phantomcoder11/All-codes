class Solution{
public:
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum=0;
        for(int i=0;i<N;i++) sum+=arr[i];
        if(sum%2!=0) return false;
        sum=sum/2;
        int dp[N+1][sum+1];
        for(int i=0;i<=N;i++){
            for(int j=0;j<=sum;j++){
                if(j==0){
                    dp[i][j]=1;
                }else if(i==0){
                    dp[i][j]=0;
                }else if(arr[i-1]>sum){
                    dp[i][j]=dp[i-1][j];
                }else{
                    dp[i][j]=dp[i-1][j] || dp[i-1][j-arr[i-1]];
                }
            }
        }
        return dp[N][sum];
    }
};