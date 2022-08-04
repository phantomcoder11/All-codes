class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>>nodes;
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* temp=q.front().first;
                int x=q.front().second.first;
                int y=q.front().second.second;
                q.pop();
                nodes[y][x].insert(temp->val);
                if(temp->left) q.push({temp->left,{x+1,y-1}});
                if(temp->right) q.push({temp->right,{x+1,y+1}});
            }
           
        }
        vector<vector<int>>ans;
        for(auto i: nodes){
            vector<int>v;
            for(auto j:i.second){
               // v.insert(v.end(),j.second.begin(),j.second.end());
                for(auto k:j.second){
                    v.push_back(k);
                }
            }
            ans.push_back(v);
        }
        return ans;
    }
};