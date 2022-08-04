
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int mn=n-1;
        int temp;
        bool flag=true;
        for(int i=n-1;i>=1;i--){

            if(nums[i]>nums[i-1]){
                // cout<<nums[i-1]<<nums[mn];
                flag=false;
                temp=i-1;
                break;
            }
        }
         // cout<<nums[temp]<<" ";
         if(flag){
             sort(nums.begin(),nums.end());
             return;
         } 
        
         int x=INT_MAX;
         for(int i=n-1;i>=temp;i--){
             if(nums[i]>nums[temp]){
               
                 if(x>nums[i]){
                     x=nums[i];
                     mn=i; 
                 }
                 
             }
         }
        swap(nums[temp],nums[mn]);
        sort(nums.begin()+temp+1,nums.end());
        return;
       
    }
};