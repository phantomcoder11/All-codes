class Solution {

public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        int prev=intervals[0][0],next=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(next<intervals[i][0]){
                ans.push_back({prev,next});
                prev=intervals[i][0];
            }
            next=max(next,intervals[i][1]);
        }
        ans.push_back({prev,next});
        return ans;
    }
};