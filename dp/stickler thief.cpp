// Stickler the thief wants to loot money from a society having n houses
// in a single line. He is a weird person and follows a certain rule when
// looting the houses. According to the rule, he will never loot two consecutive
// houses. At the same time, he wants to maximize the amount he loots. The
// thief knows which house has what amount of money but is unable to come
// up with an optimal looting strategy. He asks for your help to  nd the
// maximum money he can get if he strictly follows the rule. Each house has
// a[i] amount of money present in it.
//  Given an array, the solution is to  nd the maximum sum subsequence
// where no two selected elements are adjacent. So the approach to the
// problem is a recursive solution. So there are two cases.
//  1. If an element is selected then the next element cannot be selected.
//  2. if an element is not selected then the next element can be selected.
// So the recursive solution can easily be devised. The sub-problems can be
// stored thus reducing the complexity and converting the recursive solution
// to Dynamic programming problem.

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        //Initialize dp
        int dp[n+1];
        dp[0]=0;
        dp[1]=arr[0];
        
        for(int i=2;i<n+1;i++){
            // we have two choice either we 
            // steal the house arr[i]+dp[i-2] and
            // we don't steal that particular house dp[i-1]
            dp[i]=max(arr[i-1]+dp[i-2],dp[i-1]);
        }
        return dp[n];
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}
  // } Driver Code Ends