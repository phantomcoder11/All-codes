class Solution {
public:
    void recursion(vector<int>&nums,int idx,vector<vector<int>>&ans){
        if(idx==nums.size()){
            ans.push_back(nums);
            return;
        }
        if(idx>nums.size()) return;
        for(int i=idx;i<nums.size();i++){
            swap(nums[i],nums[idx]);
            recursion(nums,idx+1,ans);
            swap(nums[i],nums[idx]);
             
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        recursion(nums,0,ans);
        return ans;
    }
};