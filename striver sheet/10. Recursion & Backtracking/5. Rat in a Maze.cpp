// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void solve(int i,int j,int n,vector<vector<int>> &m,string s,vector<string>&ans,vector<vector<int>>&copy){
        
        if(i>=n || j>=n || i<0 || j<0 ) return;
        if(m[i][j]==0) return;
        if(i==n-1 && j==n-1){
            ans.push_back(s);
            return;
        } 
         if(copy[i][j]){
             copy[i][j]=0;
             solve(i+1,j,n,m,s+'D',ans,copy);
             solve(i,j-1,n,m,s+'L',ans,copy);
             solve(i,j+1,n,m,s+'R',ans,copy);
             solve(i-1,j,n,m,s+'U',ans,copy);
             copy[i][j]=1;
         }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string>ans;
        string s="";
        vector<vector<int>> copy(n,vector<int>(n,1));
        solve(0,0,n,m,s,ans,copy);
        return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends