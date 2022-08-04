//recursive
class Solution{
public:
    bool isPalindrome(string s,int i,int j){
        while(i<=j){
            if(s[i++]!=s[j--]) return false;
        }
        return true;
    }
    int solve(string s,int i,int j){
        if(i>j) return 0;
        if(isPalindrome(s,i,j)) return 0;
        int ans=INT_MAX;
        for(int k=i;k<=j-1;k++){
            int temp=1+solve(s,i,k)+solve(s,k+1,j);
            ans=min(ans,temp);
        }
        return ans;
    }
    int palindromicPartition(string str)
    {
        // code here
        return solve(str,0,str.length()-1);
    }
};

// Memoized 

class Solution{
public:
    int dp[501][501];
    bool isPalindrome(string s,int i,int j){
        while(i<=j){
            if(s[i++]!=s[j--]) return false;
        }
        return true;
    }
    int solve(string s,int i,int j){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(isPalindrome(s,i,j)) return dp[i][j]=0;
        int ans=INT_MAX;
        for(int k=i;k<=j-1;k++){
            int a=(dp[i][k]!=-1)?dp[i][k]:solve(s,i,k);
            int b=(dp[k+1][j]!=-1)?dp[k+1][j]:solve(s,k+1,j);
            int temp=1+a+b;
            ans=min(ans,temp);
        }
        return dp[i][j]=ans;
    }
    int palindromicPartition(string str)
    {
        // code here
        dp[str.length()+1][str.length()+1];
        memset(dp,-1,sizeof(dp));
        return solve(str,0,str.length()-1);
    }
};