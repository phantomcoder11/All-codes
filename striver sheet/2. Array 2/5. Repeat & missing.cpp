// https://leetcode.com/problems/set-mismatch/
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
         int x=0;
        for(int i=0;i<nums.size();i++){
            x^=nums[i];
        }
        for(int i=1;i<=nums.size();i++){
            x^=i;
        }
        int set_bit=x&-x;
        int a=0,b=0;
        for(auto n:nums){
            if(n&set_bit){
                a=a^n;
            }else b=b^n;
        }
        for(int i=1;i<=nums.size();i++){
           if(i&set_bit){
                a=a^i;
            }else b=b^i;
        }
        int count=0;
        for(auto x:nums){
            if(a==x) return {a,b};
        }
        return {b,a};
    }
};