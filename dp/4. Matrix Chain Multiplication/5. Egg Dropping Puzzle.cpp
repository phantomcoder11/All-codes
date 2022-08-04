// Recursive + memoization
// https://leetcode.com/problems/super-egg-drop/
// https://practice.geeksforgeeks.org/problems/egg-dropping-puzzle-1587115620/1#
// https://leetcode.com/problems/super-egg-drop/discuss/792736/CPP-Explained-Recursive-greatermemoization-greateroptimization-greaterDP-oror-Well-Explained-oror-Easy-to-unserstand
int dp[201][201];
    int solve(int e,int f){
        if(dp[e][f]!=-1) return dp[e][f];
        if(f==0 || f==1) return f;
        if(e==1) return dp[e][f]=f;
        
        int mn=INT_MAX;
        for(int k=1;k<=f;k++){
            int a=(dp[e-1][k-1]!=-1)?dp[e-1][k-1]:solve(e-1,k-1);
            int b=(dp[e][f-k]!=-1)?dp[e][f-k]:solve(e,f-k);
            int temp=1+max(a,b);
            mn=min(mn,temp);
        }
        return dp[e][f]=mn;
    }
    int eggDrop(int n, int k) 
    {
        // your code here
        dp[n+1][k+1];
        memset(dp,-1,sizeof(dp));
        return solve(n,k);
    }



// Optimized with binary search
class Solution {
public:
    int dp[101][10001];
    int solve(int e,int f){
        if(dp[e][f]!=-1) return dp[e][f];
        if(f==0 || f==1) return f;
        if(e==1) return dp[e][f]=f;
        
        int mn=INT_MAX;
        int l=1,h=f;
        while(l<=h){
            int mid=(l+h)/2;
            int left=(dp[e-1][mid-1]!=-1)?dp[e-1][mid-1]:solve(e-1,mid-1);
            int right=(dp[e][f-mid]!=-1)?dp[e][f-mid]:solve(e,f-mid);
            int temp=1+max(left,right);
            if(left<right){
                l=mid+1;
            }else h=mid-1;
            mn=min(mn,temp);
        }
        return dp[e][f]=mn;
    }
    int superEggDrop(int k, int n) {
        // dp[k+1][n+1];
        memset(dp,-1,sizeof(dp));
        return solve(k,n);
    }
};