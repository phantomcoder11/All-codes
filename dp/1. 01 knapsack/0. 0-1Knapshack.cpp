// Recursive approach
class Solution{
      public:
      int solve(int W,int wt[],int val[],int n){
        if(n==0 || W<=0) return 0;
        
        if(wt[n-1]<=W){
            return max(val[n-1]+solve(W-wt[n-1],wt,val,n-1),solve(W,wt,val,n-1));
        }else{
            return solve(W,wt,val,n-1);
        }
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       return solve(W,wt,val,n);
    }
};

//MEMOIZED APPROACH 
class Solution{
      public:
    int dp[1001][1001];
    int solve(int W,int wt[],int val[],int n){
        if(n==0 || W<=0) return 0;
        if(dp[W][n]!=-1) return dp[W][n];
        if(wt[n-1]<=W){
            return dp[W][n]=max(val[n-1]+solve(W-wt[n-1],wt,val,n-1),solve(W,wt,val,n-1));
        }else{
            return dp[W][n]=solve(W,wt,val,n-1);
        }
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
      // Your code here
      dp[W+1][n+1];
      memset(dp,-1,sizeof(dp));
      return solve(W,wt,val,n);
    }
};



//BOTTOM-UP APPROACH
class Solution{
      public:
    int knapSack(int W, int wt[], int val[], int n) 
    { 
      // Your code here
      int dp[n+1][W+1];
     for(int i=0;i<=n;i++){
         for(int j=0;j<=W;j++){
             if(i==0 || j==0){
                 dp[i][j]=0;
             }else if(wt[i-1]<=j){
                 dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
             }
             else dp[i][j]=dp[i-1][j];
         }
     }
      return dp[n][W];
    }
};
