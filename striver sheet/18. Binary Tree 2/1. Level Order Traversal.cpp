class Solution {
public:
    //By bfs
    vector<vector<int>> levelOrderbfs(TreeNode* root) {
        if(root==NULL) return {};
        vector<vector<int>>ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n =q.size();
            vector<int>v;
            for(int i=0;i<n;i++){
                TreeNode* node=q.front();
                q.pop();
                v.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            ans.push_back(v);
        }

        return ans;
    }
    //BY DFS
    vector<vector<int>> levelOrderdfs(TreeNode* root) {
            vector<vector<int>>ans;
            dfs(root,0,ans);
            return ans;
    }
    void dfs(TreeNode* root,int depth,vector<vector<int>>&ans){
        if(!root) return;
        if(ans.size()<=depth) ans.push_back({});
        ans[depth].push_back(root->val);
        dfs(root->left,depth+1,ans);
        dfs(root->right,depth+1,ans);
    }
};