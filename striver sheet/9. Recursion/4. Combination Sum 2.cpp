class Solution {
public:
    void recursion(int target,int idx,vector<int>&cand,vector<vector<int>>&ans,vector<int>&v){
        if(target==0){
            ans.push_back(v);
        }
        
        for(int i=idx;i<cand.size();i++){
            if(cand[i]<=target){
                if(i>0 && cand[i-1]==cand[i] && i>idx)continue;
                v.push_back(cand[i]);
                recursion(target-cand[i],i+1,cand,ans,v);
                v.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& cand, int target) {
        vector<vector<int>>ans;
        vector<int>v;
        sort(cand.begin(),cand.end());
        recursion(target,0,cand,ans,v);
        return ans;
    }
};