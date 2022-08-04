//Initial template for C++
//https://practice.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1/#
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int median(vector<vector<int>> &matrix, int r, int c){
        // code here  
       int  low=1,high=2000;
       while(low<=high){
           int count=0;
           int mid=(low+high)/2;
           for(int i=0;i<r;i++){
               int l=0,h=c-1;
               while(l<=h){
                   int m=(l+h)/2;
                   if(matrix[i][m] <= mid ) l=m+1;
                   else h=m-1;
               }
               count+=l;
           }
           if(count<=r*c/2)low=mid+1;
           else high=mid-1;
       }
       return low;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        cout<<obj.median(matrix, r, c)<<endl;        
    }
    return 0;
}  // } Driver Code Ends