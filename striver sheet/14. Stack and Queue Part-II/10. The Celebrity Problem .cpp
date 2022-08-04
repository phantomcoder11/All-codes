//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // Time O(n2)
        // vector<int>v(n,0);
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         if(M[i][j]==1){
        //             v[i]=-1;
        //             v[j]++;
        //         }
                
        //     }
        // }
        // for(int i=0;i<n;i++){
        //     if(v[i]==n-1) return i;
        // }
        // return -1;
        //Time O(n)
        
    stack<int>s;
    for(int i=0;i<n;i++){
        s.push(i);
    }
    while(s.size()>1){
        int first=s.top();
        s.pop();
        int second=s.top();
        s.pop();
        if(M[first][second]) s.push(second);
        else s.push(first);
    }
    
    if(s.empty()) return -1;
    int ans=s.top();
    for(int i=0;i<n;i++){
        if(M[ans][i]) return -1;
        if(i!=ans && !M[i][ans]) return -1;
    }
    return ans;
    
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}
  // } Driver Code Ends