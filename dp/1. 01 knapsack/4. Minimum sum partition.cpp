int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int sum=0;
	    for(int i=0;i<n;i++) sum+=arr[i];
	    int dp[n+1][sum+1];

      for(int i=0;i<=n;i++){
          for(int j=0;j<=sum;j++){
              if(j==0) dp[i][j]=1;
              else if(i==0) dp[i][j]=0;
              else if(arr[i-1]>j){
                  dp[i][j]=dp[i-1][j];
              }else{
                  dp[i][j]=dp[i-1][j-arr[i-1]] || dp[i-1][j];
              }
          }
      }
     
      for(int i=sum/2;i>=0;i--){
          if(dp[n][i]){
              return sum-2*i;
          } 
      }
      return -1;
	} 