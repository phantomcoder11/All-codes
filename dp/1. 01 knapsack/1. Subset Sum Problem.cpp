//https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1/#


//Recursive way
class Solution{   
public:
    bool solve(vector<int>&arr,int sum,int n){
        if(sum==0) return 1;
        if(n<=0) return 0;
        if(arr[n-1]>sum) return solve(arr,sum,n-1);
        else return solve(arr,sum-arr[n-1],n-1) || solve(arr,sum,n-1);
    }
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        return solve(arr,sum,arr.size());
    }
};

//Memoized Way
class Solution{   
public:

    bool solve(vector<int>&arr,int sum,int n,vector<vector<int>>&dp){
        if(sum==0) return 1;
        if(n<=0) return 0;
        if(dp[n][sum]!=-1) return dp[n][sum];
        if(arr[n-1]>sum) return dp[n][sum]=solve(arr,sum,n-1,dp);
        else return dp[n][sum]=solve(arr,sum-arr[n-1],n-1,dp) || solve(arr,sum,n-1,dp);
    }
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        vector<vector<int>>dp(arr.size()+1,vector<int>(sum+1,-1));
        return solve(arr,sum,arr.size(),dp);
    }
};

// Top down Approach
class Solution{   
public:

    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n=arr.size();
        int dp[n+1][sum+1];
        for(int i=0;i<=sum;i++){
            dp[0][i]=0;
        }
        for(int i=0;i<=n;i++){
            dp[i][0]=1;
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
                if(arr[i-1]>j){
                    dp[i][j]=dp[i-1][j];
                }else{
                    dp[i][j]=dp[i-1][j] ||  dp[i-1][j-arr[i-1]];
                }
            }
        }
        return dp[n][sum];
    }
};