class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int pref=1;
        int suff=1;
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            pref=(pref?pref:1)*nums[i];
            suff=(suff?suff:1)*nums[nums.size()-i-1];
            maxi=max(maxi,max(suff,pref));
        }
        return maxi;
    }
};
