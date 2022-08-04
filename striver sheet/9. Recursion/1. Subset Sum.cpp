#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    void recursion(vector<int>&arr,int n,int i,vector<int>&v,int sum){
        if(i==n){
            v.push_back(sum);
            return;
        }
        recursion(arr,n,i+1,v,sum+arr[i]);
        recursion(arr,n,i+1,v,sum);
    }
    vector<int> subsetSums(vector<int> arr, int n)
    {
        // Write Your Code here
     vector<int>v;
     recursion(arr,n,0,v,0);
     return v;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends