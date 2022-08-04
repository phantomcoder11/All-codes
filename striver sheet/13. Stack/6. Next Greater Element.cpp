#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>m;
        int l=nums2.size();
        m[nums2[l-1]]=-1;
   
        stack<int>s;
        s.push(nums2[l-1]);
        for(int i=l-2;i>=0;i--){
            while(s.size() && s.top()<=nums2[i]){
                s.pop();
            }
            if(s.empty()){
                m[nums2[i]]=-1;
                
            }else{
                m[nums2[i]]=s.top(); 
            }
            s.push(nums2[i]);
        }
        vector<int>ans;
        for(int i=0;i<nums1.size();i++){
            ans.push_back(m[nums1[i]]);
        }
        return ans;
    }
};