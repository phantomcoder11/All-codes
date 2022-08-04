class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
       vector<vector<int>>v;
        if(nums.size()==0 || nums.size()==1) return v;

        sort(nums.begin(),nums.end());
       for(int i=0;i<nums.size()-2;i++){
          
           if(i==0 || (i>0 && nums[i]!=nums[i-1])){
               int l=i+1,h=nums.size()-1;
               while(l<h) {
                 if(nums[l]+nums[h]<(-nums[i]) ){
                  
                   l++;
               }
               else if(nums[l]+nums[h]>(-nums[i]) ){
                   h--;
               }
               else if(nums[l]+nums[h]==(-nums[i])){
                   
                   v.push_back({nums[i],nums[l],nums[h]});
                   
                   while(l<h && nums[l]==nums[l+1])  l++;
                   while(l<h && nums[h]==nums[h-1] )  h--;
                   l++;
                   h--;
                  
               }  
               }
               
           }
           
       }
        return v;
    }
};



