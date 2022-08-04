#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    // O(m+n) time complexity and O(1) space
    // int kthElement(int arr1[], int arr2[], int n, int m, int k)
    // {
    //     int i=0,j=0,x=0;
    //     while(i<n && j<m){
    //         if(arr1[i]<=arr2[j]){
    //              if(x==k-1) return arr1[i];
    //              i++;x++;
                 
    //         }else{
    //              if(x==k-1) return arr2[j];
    //              j++;x++;
    //         }
    //     }
    //     while(i<n){
    //              if(x==k-1) return arr1[i];
    //              i++;x++;
    //     }
    //     while(j<m){
                 
    //              if(x==k-1) return arr2[j];
    //              j++;x++;
    //         }
    //     return -1;
    // }
    // Time O(log(min(n,m) And space O(1)
    int kthElement(int arr1[], int arr2[], int n, int m, int k){
        if(n>m) return kthElement(arr2,arr1,m,n,k);
        int low=max(0,k-m);
        int high=min(n,k);
        while(low<=high){
            int cut1=(low+high)/2;
            int cut2=k-cut1;
            // cout<<cut2<<endl;
            // if(cut2>m){
            //     low=cut1+1;
            //     continue;
            // }
            // if(cut2<0){
            //     high=cut1-1;
            //     continue;
            // }
            int l1=(cut1==0)?INT_MIN:arr1[cut1-1];
            int l2=(cut2==0)?INT_MIN:arr2[cut2-1];
            
            int r1=(cut1==n)?INT_MAX:arr1[cut1];
            int r2=(cut2==m)?INT_MAX:arr2[cut2];
            
            if(l1<=r2 && l2<=r1){
                return max(l1,l2);
            }
            else if(l1<r2){
                low=cut1+1;
            }else high=cut1-1;
        }
        return -1;
    }
};












// { Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}  // } Driver Code Ends