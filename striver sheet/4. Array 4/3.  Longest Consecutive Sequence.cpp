class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int>m;
        int count=0,ans=0;
        for(auto x:nums) m[x]++;
        for(int i=0;i<nums.size();i++){
            if(m.find(nums[i]-1)==m.end()){
               count=0;
                int x=nums[i];
               while(m.find(x)!=m.end()){
                   count++;
                   x++;
               }
                ans=max(ans,count);
            }
        }
        return ans;
    }
};