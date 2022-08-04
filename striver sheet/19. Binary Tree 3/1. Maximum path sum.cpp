/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxSum=-1001;
        sum(root,maxSum);
        return maxSum;
    }
    int sum(TreeNode* root, int &maxSum){
        if(!root) return 0;
        int l=sum(root->left,maxSum); 
        int r=sum(root->right,maxSum);
        maxSum=max(maxSum,root->val+((l>0)?l:0)+((r>0)?r:0));
        return (max(l,r)>0?max(l,r):0)+root->val;
    }
};