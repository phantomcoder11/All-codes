class Solution {
public:
    //Using O(n*m) time complexiy
    // void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    //     if(nums1.size()==0 || nums2.size()==0) return;
    //   int i=0,j=0;
    //   while(i<m){
    //     if(nums1[i]>nums2[j]){
    //         swap(nums1[i],nums2[j]);
    //         sort(nums2.begin(),nums2.end());
    //     }  
    //       i++;
    //   }
    //     for(int i=m;i<m+n;i++){
    //         nums1[i]=nums2[i-m];
    //     }
    // }
    //Using GAP method
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n){
        for(int i=m;i<m+n;i++){
            nums1[i]=nums2[i-m];
        }
        int gap=m+n;
        while(gap){
            gap=ceil((float)gap/2);
            int i=0,j=0+gap;
            while(j<n+m){
                if(nums1[i] > nums1[j]){
                    swap(nums1[i],nums1[j]);
                }
                i++;j++;
            }
            if(gap==1) break;
        }
    }
//       void merge(vector<int>& nums1, int m, vector<int>& nums2, int n){
//          int a=m-1;
//          int b=n-1;
//           int i= m+n-1;
//           while(a>=0 && b>=0){
//               if(nums1[a]>nums2[b]){
//                   nums1[i--]=nums1[a--];
//               }else{
//                   nums1[i--]=nums2[b--];
//               }
              
//           }
//           while(b>=0){
//               nums1[i--]=nums2[b--];
//           }
        
//     }
};