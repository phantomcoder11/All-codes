// https://leetcode.com/problems/binary-tree-maximum-path-sum/

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
    int solve(TreeNode* root, int &sum){
        if(!root) return 0;
        int l=solve(root->left,sum);
        int r=solve(root->right,sum);
        int temp=max(max(l,r)+root->val,root->val);
        int curr=max(temp,l+r+root->val);
        sum=max(sum,curr);
        return temp;
    }
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        int sum=INT_MIN;
        solve(root,sum);
        return sum;
    }
};