// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++
// Time complexity O(nlogn) Space Complexity O(1)
class Solution 
{
    bool isPossible(int mid,int m,int n,int A[]){
    int count=1;
            int sum=0;
            for(int i=0;i<n;i++){
                if(mid<A[i]) return false;
                sum+=A[i];
                if(sum>mid){
                    sum=A[i];
                    count++;
                }
            }
            return m>=count;
    }
    public:
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        //code here
        int low=A[0];
        int high=0;
        for(int i=0;i<N;i++) high+=A[i];
       int ans=-1;
            
        while(low<=high){
             int mid=(low+high)/2;
        
            if(isPossible(mid,M,N,A)){
                ans=mid;
                high=mid-1; 
            }
            else{
                low=mid+1;
            }
        }
        return (ans==-1)?low:ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends