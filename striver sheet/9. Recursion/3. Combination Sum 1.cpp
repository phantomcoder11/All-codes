class Solution {
public:
    void recursion(vector<int>&candidates,int target,int i,vector<vector<int>>&ans,vector<int>&v){
        
        if(target==0 && i==candidates.size()){
           
            ans.push_back(v);

            return;
        }
        if(target<0 || i>=candidates.size()){
            
             return;
        }
        if(candidates[i]<=target){
      
             v.push_back(candidates[i]);
             recursion(candidates,target-candidates[i],i,ans,v);
             v.pop_back();
        }

        recursion(candidates,target,i+1,ans,v);
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>>ans;
        vector<int>v;
        recursion(candidates,target,0,ans,v);
        return ans;
    }
};