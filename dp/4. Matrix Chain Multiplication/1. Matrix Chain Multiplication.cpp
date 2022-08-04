// https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1/#

//Recursive Sol
class Solution{
    int solve(int arr[],int i,int j){
        if(i>=j) return 0;
        int mn=INT_MAX;
        for(int k=i;k<=j-1;k++){
            int temp_ans=solve(arr,i,k)+solve(arr,k+1,j)+arr[i-1]*arr[k]*arr[j];
            if(temp_ans<mn) mn=temp_ans;
        }
        return mn;
    }
public:
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        return solve(arr,1,N-1);
    }
};

// Memoized Solution

class Solution{
    int dp[101][101];
    int solve(int arr[],int i,int j){
        if(i>=j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int mn=INT_MAX;
        for(int k=i;k<=j-1;k++){
            int temp_ans=solve(arr,i,k)+solve(arr,k+1,j)+arr[i-1]*arr[k]*arr[j];
            if(temp_ans<mn) mn=temp_ans;
        }
        return dp[i][j]=mn;
    }
public:
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        memset(dp,-1,sizeof(dp));
        return solve(arr,1,N-1);
    }
};