class Solution {
public:
    int merge(int l,int m,int h,vector<int>&nums){
        int i,j=m+1,count=0;
        for(int i=l;i<=m;i++){
            while(j<=h && nums[i]> (2*(long long)nums[j])){
                j++;
            }
            count+=j-(m+1);
        }
        i=l,j=m+1;
        vector<int>temp;
        while(i<=m && j<=h){
            if(nums[i]<=nums[j]) temp.push_back(nums[i++]);
            else temp.push_back(nums[j++]);
        }
        while(i<=m)  temp.push_back(nums[i++]);
        while(j<=h) temp.push_back(nums[j++]);
        for(int i=l;i<=h;i++){
            nums[i]=temp[i-l];
        }
        return count;
    }
    int mergesort(int l,int h,vector<int>&nums){
        int count=0;
        if(l<h){
            int mid=(l+h)/2;
            count+=mergesort(l,mid,nums);
            count+=mergesort(mid+1,h,nums);
            count+=merge(l,mid,h,nums);
            
        }
        return count;
    }
    int reversePairs(vector<int>& nums) {
        return mergesort(0,nums.size()-1,nums);
        
    }
};