#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int>nsl,nsr;
        stack<pair<int,int>>s;
        for(int i=0;i<heights.size();i++){
            if(s.empty()){
                nsl.push_back(-1);
            }
            else if(s.size() && s.top().first<heights[i]){
                nsl.push_back(s.top().second);
            }else{
                while(s.size() && s.top().first>=heights[i]) s.pop();
                if(s.empty()) nsl.push_back(-1);
                else nsl.push_back(s.top().second);
            }
            s.push({heights[i],i});
        }
       stack<pair<int,int>>s1;
        for(int i=heights.size()-1;i>=0;i--){
            if(s1.empty()){
                nsr.push_back(heights.size());
            }else if(s1.size() && s1.top().first<heights[i]){
                nsr.push_back(s1.top().second);
            }else{
                while(s1.size() && s1.top().first>=heights[i]) s1.pop();
                if(s1.size()) nsr.push_back(s1.top().second);
                else nsr.push_back(heights.size());
            }
            s1.push({heights[i],i});
        }
        int ans=-1;
        for(int i=0;i<heights.size();i++){
            int x=heights[i]*(nsr[heights.size()-i-1]-nsl[i]-1);
            ans=max(ans,x);
        }
        // for(auto x:nsr) cout<<x<<" ";
        return ans;
    }
};