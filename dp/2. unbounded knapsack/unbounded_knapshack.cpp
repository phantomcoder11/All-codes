// Note that we use 1D array here which is different from classical knapsack
// where we used 2D array. Here number of items never changes.
// We always have all items available.

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
int knapSack(int W, int n,
                       int val[], int wt[])
{
    //Unbounded Knapshack with O(NW) time complexity
    
   // Unbounded Knapshack is exactly same as 0-1 KnapSack just the difference is that 
   // we can have infinite number of items.
   // Let's try to understand this using an example : 
   // We are going to shopping and we bought aata 1 packet, and maggi and then again we bought maggi
   // here comes the difference 


// int dp[n+1][W+1];
            
//         for(int i=0;i<n+1;i++){
//             for(int j=0;j<W+1;j++){
//                 if(i==0 || j==0){
//                     dp[i][j]=0;
//                 }else{
                    
//                     if(wt[i-1]>j){
//                         dp[i][j]=dp[i-1][j];
//                     }else{
//                         dp[i][j]=max(val[i-1]+dp[i][j-wt[i-1]],dp[i-1][j]);
//                     }
//                 }
//             }
//         }
//         return dp[n][W];


    //Unbounded Knapshack with O(W) time complexity
    // dp[i] is going to store maximum value
    // with knapsack capacity i.
    int dp[W+1];
    memset(dp, 0, sizeof dp);
 
    // Fill dp[] using above recursive formula
    for (int i=0; i<=W; i++)
      for (int j=0; j<n; j++)
         if (wt[j] <= i)
            dp[i] = max(dp[i], dp[i-wt[j]] + val[j]);
 
    return dp[W];
}
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}  // } Driver Code End