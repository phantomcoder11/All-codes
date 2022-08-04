class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode*,int>>q;
        int ans=0;
        int left=0,right=0;
        q.push({root,0});
        while(!q.empty()){
            int n=q.size();
            int start=q.front().second;
            int end=q.back().second;
            
            ans=max(ans,end-start+1);
            for(int i=0;i<n;i++){
              
                TreeNode* node=q.front().first;
                int y=q.front().second-start;
                q.pop();
               
                if(node->left) q.push({node->left,(long long)2*y+1});
                if(node->right) q.push({node->right,(long long)2*y+2});
            }
            
           
        }
        return ans;
    }
};