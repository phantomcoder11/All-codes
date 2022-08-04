class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>>ans;
        queue<TreeNode*>q;
        q.push(root);
        int flag=1;
        while(!q.empty()){
            int n=q.size();
            
            vector<int>v(n);
            for(int i=0;i<n;i++){
                TreeNode* node=q.front();
                q.pop();
                if(flag==0){
                v[n-i-1]=node->val;
                }else
                v[i]=(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            
            flag=1-flag;
            ans.push_back(v);
        }
        return ans;
    }
};