class Solution {
public:
    //Time O(n) and Space O(1);
    // int singleNonDuplicate(vector<int>& nums) {
    //     int ans=nums[0];
    //     for(int i=1;i<nums.size();i++){
    //         ans=ans^nums[i];
    //     }
    //     return ans;
    // }
    
    //Time O(logn) && Space O(1);
    int singleNonDuplicate(vector<int>& nums) {
        int low=0,high=nums.size()-1;
        while(low<high){

            int mid=(low+high)/2;
           
            if(mid%2==0 && nums[mid]==nums[mid+1] || 
               mid%2==1 && nums[mid]==nums[mid-1]){
                low=mid+1;
            }
            else high=mid;
        }
        return nums[low];
    }
};