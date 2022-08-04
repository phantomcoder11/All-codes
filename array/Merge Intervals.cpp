class Solution {
public:

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int prev=intervals[0][0];
        int next=intervals[0][1];
       
        vector<vector<int>>v;
        for(int i=1;i<intervals.size();i++){
           if(next<intervals[i][0]){
                
               v.push_back({prev,next});
               prev=intervals[i][0];
               next=intervals[i][1];
           }else{
               next=max(intervals[i][1],next);
           }
        }
        v.push_back({prev, next});
        return v;
    }
};