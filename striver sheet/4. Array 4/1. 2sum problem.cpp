class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //O(n) time complexity  O(n) space complexity
        
        unordered_map<int,int>m;
        
        for(int i=0;i<nums.size();i++){
            if(m.find(target-nums[i])!=m.end()){
               return {m[target-nums[i]],i};
            }else{
                m[nums[i]]=i;
            }
            
        }
        return {-1,-1};
        

};