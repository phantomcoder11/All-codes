class Solution {
public:
//Using Priority queues 
//         vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         priority_queue<pair<int,int>>q;
//             for(int i=0;i<k;i++){
//                 q.push({nums[i],i});
//             }
//             vector<int>ans;
//             ans.push_back(q.top().first);
//             for(int i=k;i<nums.size();i++){
//                 q.push({nums[i],i});
//                 while((q.top().second<=i-k)) q.pop();
               
//                 ans.push_back(q.top().first);
//             }
//             return ans;
//     }
    // Using deque
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            if(dq.size() && dq.front()==i-k){
                dq.pop_front();
            }
            while(dq.size() && nums[dq.back()]<=nums[i]) dq.pop_back();
            dq.push_back(i);
            if(i>=k-1) ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};