//Leetcode  https://leetcode.com/problems/online-stock-span
// GFG https://practice.geeksforgeeks.org/problems/stock-span-problem-1587115621/1#
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int a[], int n)
    {
       // Your code here
       stack<pair<int,int>>s;
       vector<int>v;
       for(int i=0;i<n;i++){
           
           if(s.empty()) v.push_back(1);
           
           else if(!s.empty() && s.top().first>a[i]) {
               v.push_back(i-s.top().second);
           }
           else if(!s.empty() && s.top().first<=a[i]){
               int count=0;
               while(!s.empty() && s.top().first<=a[i]){
                   s.pop();
                   count++;
               }
               if(s.empty())
               v.push_back(i+1);
               else
               v.push_back(i-s.top().second);
           }
           s.push({a[i],i});
       }
       return v;
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
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
  // } Driver Code Ends