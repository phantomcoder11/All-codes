#include<bits/stdc++.h>
using namespace std;

// O(N) time complexity and O(N)Space Complexity
class Solution {
public:
    int trap(vector<int>& height) {
        vector<int>l(height.size(),0);
        l[0]=height[0];
        for(int i=1;i<height.size();i++){
            l[i]=max(l[i-1],height[i]);
        }
        vector<int>r(height.size(),0);
        r[height.size()-1]=height[height.size()-1];
        for(int i=height.size()-2;i>=0;i--){
            r[i]=max(r[i+1],height[i]);
        }
        int ans=0;
        for(int i=0;i<height.size();i++){
            ans+=min(l[i],r[i])-height[i];
        }
        // for(auto x:r) cout<<x<<" ";
        return ans;
    }
};

  // O(N) Time complexity && O(1) Space Complexity
class Solution {
public:
  
    int trap(vector<int>& height) {
        int l=0,r=height.size()-1;
        int leftmax=-1,rightmax=-1;
        int sum=0;
        while(l<=r){
            if(height[l]<=height[r]){
                if(leftmax<=height[l]) leftmax=height[l];
                else sum+=leftmax-height[l];
                l++;
            }
            else{
                if(rightmax<=height[r]) rightmax=height[r];
                else sum+=rightmax-height[r];
                r--;
            }
        }
        return sum;
    }
    
};