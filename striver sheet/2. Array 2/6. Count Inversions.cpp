#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
   long long int merge(long long low, long long high,long long mid,long long arr[]){

       
       long long int inv=0;
       long long int n1=mid-low+1,n2=high-mid;
       long long int a[n1],b[n2];
       for(long long int i=0;i<n1;i++) a[i]=arr[i+low];
       
       for(long long int j=0;j<n2;j++) b[j]=arr[j+mid+1];
       
       long long int i=0,j=0,k=low;
       
       while(i<n1 && j<n2){
           if(a[i]<=b[j]){
               arr[k++]=a[i++];
        
           }else{
               arr[k++]=b[j++];
               inv+=n1-i;
              
           } 
       }
        while(i<n1){
            arr[k]=a[i];
            i++;k++;
        }
         while(j<n2){
            arr[k]=b[j];
            k++;j++;
        }
       return inv;
   }
   long long int mergesort(long long int low, long long int high,long long arr[]){
       long long int inv=0;
        if(low<high){
           long long int mid=(low+high)/2;
           
           inv+=mergesort(low,mid,arr);
           inv+=mergesort(mid+1,high,arr);
           inv+=merge(low,high,mid,arr);
           
        }
        return inv;
        
    }
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        return mergesort(0,N-1,arr);
    }

};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends