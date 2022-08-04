class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0,high=nums.size()-1;
        while(low<=high){
            
            int mid=(low+high)/2;
            // cout<<low<<" "<<high<<" "<<mid<<endl;
            if(nums[mid]==target) return mid;
            if(nums[low]<=nums[mid]){
                if(nums[low]<=target && nums[mid]>=target) high=mid-1;
                else low=mid+1;
            }
            else if(nums[mid]<=nums[high]){
                //This means mid to h is sorted
                if(nums[mid]<=target && nums[high]>=target) low=mid+1;
                else high=mid-1;
            }
            
        }
        return -1;
    }
};