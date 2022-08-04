class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
      sort(nums.begin(),nums.end());
      int n=nums.size();
        vector<vector<int>>ans;
      for(int i=0;i<n-2;i++){
          if(i!=0 && nums[i]==nums[i-1]) continue;
          for(int j=i+1;j<n-1;j++){
               if(j!=i+1 && nums[j]==nums[j-1]) continue;
              int l=j+1,r=n-1;
              long long sum=nums[i]+nums[j];
              while(l<r){
                  if(sum+nums[l]+nums[r]==target){
                      ans.push_back({nums[i],nums[j],nums[l],nums[r]});
                      l++;
                      while(l<r && nums[l]==nums[l-1]) l++;
                  }
                  if(sum+nums[l]+nums[r]>target){
                     r--;
                  }else l++;
              }
          }
      }
        return ans;
    }
};