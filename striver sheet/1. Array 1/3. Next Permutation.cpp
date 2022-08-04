class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int i;
        bool flag=true;
        
        for(i=nums.size()-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                flag=false;
                break;
            }
        }
        
        if(flag){
            sort(nums.begin(),nums.end());
            return;
        }
        int mn;
        int x=INT_MAX;
        for(int j=nums.size()-1;j>i;j--){
         
            if(nums[j]>nums[i]){
                
                if(x>nums[j]){
                    x=nums[j];
                    mn=j;
                }
            }
        }
        
        swap(nums[i],nums[mn]);
        sort(nums.begin()+i+1,nums.end());
    }
};