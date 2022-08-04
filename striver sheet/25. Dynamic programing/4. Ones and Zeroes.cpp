// Memoization
  int dp[601][101][101];
    int knapsack(vector<string>& strs, int m, int n,vector<vector<int>>&v,int idx){
        if(idx==0 || (m==0 && n==0)) return 0;
        if(dp[idx][m][n]!=-1) return dp[idx][m][n];
        if(m>=v[idx-1][0] && n>=v[idx-1][1]){
            return dp[idx][m][n]=max(1+knapsack(strs,m-v[idx-1][0],n-v[idx-1][1],v,idx-1),knapsack(strs,m,n,v,idx-1));
        }else{
            return dp[idx][m][n]=knapsack(strs,m,n,v,idx-1);
        }
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>>v;
        for(auto x:strs){
            int one=0,zero=0;
            for(int i=0;i<x.length();i++){
                if(x[i]=='0') zero++;
                else one++;
            }
            v.push_back({zero,one});
        }
        memset(dp,-1,sizeof(dp));
        return knapsack(strs,m,n,v,strs.size());
        
    }

//Tabulation

int findMaxForm(vector<string>& strs, int m, int n) {
        int l=strs.size();
        int dp[l+1][m+1][n+1];
        vector<vector<int>>v;
        for(auto x:strs){
            int one=0,zero=0;
            for(int i=0;i<x.length();i++){
                if(x[i]=='0') zero++;
                else one++;
            }
            v.push_back({zero,one});
        }
        for(int i=0;i<=strs.size();i++){
            for(int j=0;j<=m;j++){
                for(int k=0;k<=n;k++){
                    if(i==0){
                        dp[i][j][k]=0;
                    }else if(j>=v[i-1][0] && k>=v[i-1][1]){
                        dp[i][j][k]=max(1+dp[i-1][j-v[i-1][0]][k-v[i-1][1]],dp[i-1][j][k]);
                    }
                    else dp[i][j][k]=dp[i-1][j][k];
                }
            }
        }
        return dp[strs.size()][m][n];
    }