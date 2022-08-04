// https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence4749/1
// https://leetcode.com/problems/longest-increasing-subsequence/
int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    vector<int>dp(n,0);
	    dp[0]=arr[0];
	    int ans=arr[0];
	    for(int i=1;i<n;i++){
	        for(int j=0;j<i;j++){
	            if(arr[j]<arr[i] && dp[j]+arr[i]>dp[i]){
	                dp[i]=dp[j]+arr[i];
	            }
	        }
	        if(dp[i]==0) dp[i]=arr[i];
	        ans=max(ans,dp[i]);
	    }
	    return ans;
	}