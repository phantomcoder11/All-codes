class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++) sum+=nums[i];
        if(target>sum || (target+sum)%2==1) return 0;
        sum=(sum+target)/2;
        if(sum<0) return 0;
        int dp[n+1][sum+1];
        
        for(int i=0;i<=sum;i++) dp[0][i]=0;
        dp[0][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=sum;j++){
                if(nums[i-1]>j){
                    dp[i][j]=dp[i-1][j];
                } 
                else{
                     dp[i][j]=dp[i-1][j]+dp[i-1][j-nums[i-1]];
                }
            }
        }
     
        return dp[n][sum];
    }
};